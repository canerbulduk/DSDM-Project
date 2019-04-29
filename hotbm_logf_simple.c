/* Copyright (C) 2016-2018 Politecnico di Milano (Italy).
   This file is part of the HLS-FP Library.

   The HLS-FP Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The HLS-FP Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


/* In this file the single precision log function is implemented
   following the HOTBM method published by
   Jeremie Detrey and Florent de Dinechin, "Parameterized floating-point logarithm and exponential functions for FPGAs", Microprocessors and Microsystems, vol.31,n.8, 2007, pp.537-545.
   The code has been exhaustively tested and it supports subnormals.
   @author Alessia Chiappa
   @author Roberta Catizzone
   @author Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
*/
#include "bambu_macros.h"

#define SUPPORT_SUBNORMALS

#ifdef CHECK_LOG_FUNCTION
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpfr.h>
#include <gmp.h>
#endif

#ifdef CHECK_LOG_FUNCTION
#define ADD_BUILTIN_PREFIX(fname) local_ ## fname
#else
#define ADD_BUILTIN_PREFIX(fname) __builtin_ ## fname
#endif

#define PRINT_DEBUG_MSG 0
#define CHECK_HOTBM_MAIN 0
#define CHECK_HOTBM_T1 0
#define CHECK_HOTBM_T2 0
#define CHECK_HOTBM_T3 0
#define CHECK_pow 0
#define NORMALIZATION 0
#define PRINT 0

#define LOG2 0x2C5C860
// CE_MACRO32(cond, a, b) = cond[0] && a || ~cond[0] && b  =  c.a + c'b 
#define CE_MACRO32(cond, a, b) ((((unsigned int) ((((int)(cond))<<31)>>31))&(a))|((~((unsigned int) ((((int)(cond))<<31)>>31)))&(b)))

#define PRECISION 200
#define SZ 64

typedef union {
    unsigned int b;
    float f;
} float_uint_converter;


/*
#define SELECT_BIT(VAR, bit) (((VAR)>>(bit))&1) 
//choose selected bit, shift and AND 
#define SET_BIT(VAR, bit, value) VAR = \
   ((UDATATYPE) ((VAR)&~(BOOST_PP_CAT(POW2(bit),ULL)))) | \         -- take variable AND with NOT of ULL of POW2(bit)
   ((UDATATYPE) ((((UDATATYPE)(value)) & 1ULL) << (bit)))           -- select bit?
#define SELECT_RANGE(var, high, low) VAL_RESIZE(((UDATATYPE)(var))>>(low), BOOST_PP_ADD(BOOST_PP_SUB(high,low),1))
#define SET_RANGE(VAR, val, high, low) VAR = \
   BOOST_PP_IF( \
      BOOST_PP_LESS(BITSIZE(high, low), UDATATYPE_BITSIZE), \
      (VAR & ~(UDATATYPE)((BOOST_PP_CAT(POW2(BITSIZE(high, low)),ULL)-1) << low)) | \
         ((VAL_RESIZE(val, BITSIZE(high, low))) << low), \
      val \
   )
*/


__attribute__((always_inline))
static inline
unsigned short int hotbm_t2_pow(unsigned short int x)
{
    unsigned int pp0=0, pp1=0, pp2=0, pp3=0, pp4=0 ,pp5=0, pp6=0, r0, r;

    SET_BIT(pp0, 15, SELECT_BIT(x,9) & SELECT_BIT(x,10));
    SET_BIT(pp1, 15, SELECT_BIT(x,10));

    SET_BIT(pp0, 14, SELECT_BIT(x,8) & SELECT_BIT(x,10));

    SET_BIT(pp0, 13, SELECT_BIT(x,7) & SELECT_BIT(x,10));
    SET_BIT(pp1, 13, SELECT_BIT(x,8) & SELECT_BIT(x,9));
    SET_BIT(pp2, 13, SELECT_BIT(x,9));

    SET_BIT(pp0, 12, SELECT_BIT(x,6) & SELECT_BIT(x,10));
    SET_BIT(pp1, 12, SELECT_BIT(x,7) & SELECT_BIT(x,9));

    SET_BIT(pp0, 11, SELECT_BIT(x,5) & SELECT_BIT(x,10));
    SET_BIT(pp1, 11, SELECT_BIT(x,6) & SELECT_BIT(x,9));
    SET_BIT(pp2, 11, SELECT_BIT(x,7) & SELECT_BIT(x,8));
    SET_BIT(pp3, 11, SELECT_BIT(x,8));

    SET_BIT(pp0, 10, SELECT_BIT(x,4) & SELECT_BIT(x,10));
    SET_BIT(pp1, 10, SELECT_BIT(x,5) & SELECT_BIT(x,9));
    SET_BIT(pp2, 10, SELECT_BIT(x,6) & SELECT_BIT(x,8));

    SET_BIT(pp0, 9, SELECT_BIT(x,3) & SELECT_BIT(x,10));
    SET_BIT(pp1, 9, SELECT_BIT(x,4) & SELECT_BIT(x,9));
    SET_BIT(pp2, 9, SELECT_BIT(x,5) & SELECT_BIT(x,8));
    SET_BIT(pp3, 9, SELECT_BIT(x,6) & SELECT_BIT(x,7));
    SET_BIT(pp4, 9, SELECT_BIT(x,7));

    SET_BIT(pp0, 8, SELECT_BIT(x,2) & SELECT_BIT(x,10));
    SET_BIT(pp1, 8, SELECT_BIT(x,3) & SELECT_BIT(x,9));
    SET_BIT(pp2, 8, SELECT_BIT(x,4) & SELECT_BIT(x,8));
    SET_BIT(pp3, 8, SELECT_BIT(x,5) & SELECT_BIT(x,7));

    SET_BIT(pp0, 7, SELECT_BIT(x,1) & SELECT_BIT(x,10));
    SET_BIT(pp1, 7, SELECT_BIT(x,2) & SELECT_BIT(x,9));
    SET_BIT(pp2, 7, SELECT_BIT(x,3) & SELECT_BIT(x,8));
    SET_BIT(pp3, 7, SELECT_BIT(x,4) & SELECT_BIT(x,7));
    SET_BIT(pp4, 7, SELECT_BIT(x,5) & SELECT_BIT(x,6));
    SET_BIT(pp5, 7, SELECT_BIT(x,6));

    SET_BIT(pp0, 6, SELECT_BIT(x,0) & SELECT_BIT(x,10));
    SET_BIT(pp1, 6, SELECT_BIT(x,1) & SELECT_BIT(x,9));
    SET_BIT(pp2, 6, SELECT_BIT(x,2) & SELECT_BIT(x,8));
    SET_BIT(pp3, 6, SELECT_BIT(x,3) & SELECT_BIT(x,7));
    SET_BIT(pp4, 6, SELECT_BIT(x,4) & SELECT_BIT(x,6));

    SET_BIT(pp0, 5, SELECT_BIT(x,0) & SELECT_BIT(x,9));
    SET_BIT(pp1, 5, SELECT_BIT(x,1) & SELECT_BIT(x,8));
    SET_BIT(pp2, 5, SELECT_BIT(x,2) & SELECT_BIT(x,7));
    SET_BIT(pp3, 5, SELECT_BIT(x,3) & SELECT_BIT(x,6));
    SET_BIT(pp4, 5, SELECT_BIT(x,4) & SELECT_BIT(x,5));
    SET_BIT(pp5, 5, SELECT_BIT(x,5));
    SET_BIT(pp6, 5, SELECT_BIT(x,10));

    SET_BIT(pp0, 4, SELECT_BIT(x,0) & SELECT_BIT(x,8));
    SET_BIT(pp1, 4, SELECT_BIT(x,1) & SELECT_BIT(x,7));
    SET_BIT(pp2, 4, SELECT_BIT(x,2) & SELECT_BIT(x,6));
    SET_BIT(pp3, 4, SELECT_BIT(x,3) & SELECT_BIT(x,5));
    SET_BIT(pp4, 4, SELECT_BIT(x,9));

    SET_BIT(pp0, 3, SELECT_BIT(x,0) & SELECT_BIT(x,7));
    SET_BIT(pp1, 3, SELECT_BIT(x,1) & SELECT_BIT(x,6));
    SET_BIT(pp2, 3, SELECT_BIT(x,2) & SELECT_BIT(x,5));
    SET_BIT(pp3, 3, SELECT_BIT(x,3) & SELECT_BIT(x,4));
    SET_BIT(pp4, 3, SELECT_BIT(x,4));
    SET_BIT(pp5, 3, SELECT_BIT(x,8));

    SET_BIT(pp0, 2, SELECT_BIT(x,0) & SELECT_BIT(x,6));
    SET_BIT(pp1, 2, SELECT_BIT(x,1) & SELECT_BIT(x,5));
    SET_BIT(pp2, 2, SELECT_BIT(x,2) & SELECT_BIT(x,4));
    SET_BIT(pp3, 2, SELECT_BIT(x,7));

    SET_BIT(pp0, 1, SELECT_BIT(x,0) & SELECT_BIT(x,5));
    SET_BIT(pp1, 1, SELECT_BIT(x,1) & SELECT_BIT(x,4));
    SET_BIT(pp2, 1, SELECT_BIT(x,2) & SELECT_BIT(x,3));
    SET_BIT(pp3, 1, SELECT_BIT(x,3));
    SET_BIT(pp4, 1, SELECT_BIT(x,6));

    SET_BIT(pp0, 0, SELECT_BIT(x,0) & SELECT_BIT(x,4));
    SET_BIT(pp1, 0, SELECT_BIT(x,1) & SELECT_BIT(x,3));
    SET_BIT(pp2, 0, SELECT_BIT(x,5));

    r0 = pp0 + pp1 + pp2 + pp3 + pp4 + pp5 + pp6;

    r = (1<<8)|SELECT_RANGE(r0,16,9);

    return r;
}

__attribute__((always_inline))
static inline
unsigned int hotbm_log_log_t1(unsigned char a, unsigned short int b) //(8bit,16bit)
{
    static const unsigned int log_t1_t1_hotbm_table[] = {1280732 ,1268286 ,1256048 ,1244013 ,1232176 ,1220531 ,1209076 ,1197805 ,1186714 ,1175799 ,1165056 ,1154481 ,1144071 ,1133821 ,1123729 ,1113790 ,1104002 ,1094361 ,1084864 ,1075508 ,1066290 ,1057207 ,1048256 ,1039435 ,1030740 ,1022170 ,1013722 ,1005392 ,997180 ,989082 ,981096 ,973221 ,965453 ,957791 ,950232 ,942775 ,935418 ,928159 ,920996 ,913927 ,906950 ,900064 ,893267 ,886558 ,879934 ,873395 ,866938 ,860562 ,854266 ,848049 ,841908 ,835843 ,829852 ,823935 ,818088 ,812313 ,806606 ,800968 ,795397 ,789891 ,784450 ,779073 ,773758 ,768505 ,763312 ,758179 ,753104 ,748087 ,743127 ,738222 ,733372 ,728576 ,723834 ,719143 ,714504 ,709916 ,705378 ,700888 ,696447 ,692054 ,687708 ,683408 ,679153 ,674943 ,670777 ,666655 ,662575 ,658538 ,654542 ,650588 ,646673 ,642799 ,638963 ,635167 ,631408 ,627687 ,624003 ,620356 ,616744 ,613168 ,609627 ,606120 ,602648 ,599209 ,595803 ,592430 ,589089 ,585780 ,582502 ,579255 ,576038 ,572852 ,569695 ,566568 ,563469 ,560399 ,557357 ,554343 ,551357 ,548397 ,545465 ,542558 ,539678 ,536824 ,533995 ,531190 ,528411 ,525656 ,522926 ,520219 ,517536 ,514876 ,512239 ,509624 ,507032 ,504463 ,501915 ,499388 ,496884 ,494400 ,491937 ,489494 ,487072 ,484671 ,482289 ,479926 ,477583 ,475260 ,472955 ,470669 ,468401 ,466152 ,463921 ,461708 ,459513 ,457335 ,455174 ,453030 ,450904 ,448794 ,446701 ,444624 ,442563 ,440518 ,438489 ,436476 ,434478 ,432496 ,430528 ,428576 ,426638 ,424715 ,422807 ,420913 ,419033 ,417167 ,415315 ,413477 ,411653 ,409842 ,408044 ,406259 ,404488 ,402729 ,400983 ,399250 ,397530 ,395821 ,394125 ,392442 ,390770 ,389110 ,387462 ,385825 ,384200 ,382587 ,380985 ,379394 ,377814 ,376245 ,374687 ,373140 ,371603 ,370077 ,368561 ,367056 ,365561 ,364077 ,362602 ,361137 ,359682 ,358237 ,356802 ,355376 ,353959 ,352552 ,351155 ,349766 ,348387 ,347017 ,345656 ,344304 ,342960 ,341625 ,340299 ,338982 ,337673 ,336372 ,335080 ,333796 ,332520 ,331252 ,329993 ,328741 ,327497 ,326262 ,325033 ,323813 ,322600 ,321395 ,320197 ,319007 ,317824 ,316648 ,315480 ,314318 ,313164 ,312017 ,310877 ,309744 ,308617 ,307498 ,306385 ,305279 ,304179 ,303087};

    _Bool sign = !(SELECT_BIT(b, 15)); //  ~MSB(b)
    unsigned short int b0 = SELECT_RANGE(b,14,0) ^ VAL_RESIZE(CE_MACRO32(sign,0xfffff,0),15);
    unsigned short int s_1 = b0;
	
	// SELECT_RANGE(var,high,low) = var[high:low]
	// SELECT_BIT(a,b) = (a >> b) && 0x0001
	// CE_MACRO32(cond, a, b) = cond[0] && a || ~cond[0] && b  =  c.a + c'b 
	// VAL_RESIZE(var,nbit) = var = var[nbit:0]  -- reduces number of bits 
	

	// unsigned char: 8bit
	unsigned char a_1 = SELECT_RANGE(a,7,0);
    unsigned int k_1 = log_t1_t1_hotbm_table[a_1];
    BIT_RESIZE(k_1,21);
    unsigned long int r0_1 = (((unsigned long long int) k_1) * ((((unsigned long long int) s_1) << 1)|1)) >> 17;
	//														    (     Shift left put one instead of 0  )     
	BIT_RESIZE(r0_1 ,21);
	//choose LSB 21 bit
	
	// if sign=0 : r_1 = NOT r0_1[20:0]   -- LSB 21 bit 
    unsigned int r_1 = r0_1 ^ VAL_RESIZE(CE_MACRO32(!sign,0xffffff,0), 21);
    r_1 = r_1 | ((VAL_RESIZE(CE_MACRO32(!sign,0xff,0),8))<< 21);
	// if sign=0 :  r_1 = ff & r_1
	
    return r_1;

}

__attribute__((always_inline))
static inline
unsigned int hotbm_log_log_t2(unsigned char a, unsigned short int b)
{
    static const unsigned short int log_t2_t1_hotbm_table[] = {3138 ,3085 ,3034 ,2984 ,2935 ,2887 ,2841 ,2795 ,2751 ,2707 ,2665 ,2623 ,2582 ,2543 ,2504 ,2466 ,2429 ,2392 ,2357 ,2322 ,2288 ,2254 ,2221 ,2189 ,2158 ,2127 ,2097 ,2068 ,2039 ,2010 ,1983 ,1955 ,1929 ,1903 ,1877 ,1852 ,1827 ,1803 ,1779 ,1756 ,1733 ,1710 ,1688 ,1667 ,1645 ,1624 ,1604 ,1584 ,1564 ,1545 ,1526 ,1507 ,1489 ,1470 ,1453 ,1435 ,1418 ,1401 ,1385 ,1368 ,1352 ,1336 ,1321 ,1306 ,1291 ,1276 ,1261 ,1247 ,1233 ,1219 ,1206 ,1192 ,1179 ,1166 ,1153 ,1141 ,1128 ,1116 ,1104 ,1092 ,1081 ,1069 ,1058 ,1047 ,1036 ,1025 ,1015 ,1004 ,994 ,984 ,974 ,964 ,954 ,944 ,935 ,926 ,916 ,907 ,898 ,890 ,881 ,872 ,864 ,856 ,847 ,839 ,831 ,823 ,816 ,808 ,800 ,793 ,785 ,778 ,771 ,764 ,757 ,750 ,743 ,737 ,730 ,723 ,717 ,710 ,704 ,698 ,692 ,686 ,680 ,674 ,668 ,662 ,656 ,651 ,645 ,640 ,634 ,629 ,624 ,618 ,613 ,608 ,603 ,598 ,593 ,588 ,583 ,579 ,574 ,569 ,565 ,560 ,556 ,551 ,547 ,542 ,538 ,534 ,530 ,525 ,521 ,517 ,513 ,509 ,505 ,501 ,498 ,494 ,490 ,486 ,483 ,479 ,475 ,472 ,468 ,465 ,461 ,458 ,454 ,451 ,448 ,445 ,441 ,438 ,435 ,432 ,429 ,426 ,422 ,419 ,416 ,414 ,411 ,408 ,405 ,402 ,399 ,396 ,394 ,391 ,388 ,385 ,383 ,380 ,378 ,375 ,372 ,370 ,367 ,365 ,363 ,360 ,358 ,355 ,353 ,351 ,348 ,346 ,344 ,341 ,339 ,337 ,335 ,333 ,330 ,328 ,326 ,324 ,322 ,320 ,318 ,316 ,314 ,312 ,310 ,308 ,306 ,304 ,302 ,300 ,299 ,297 ,295 ,293 ,291 ,289 ,288 ,286 ,284 ,282 ,281 ,279 ,277 ,276 ,274 ,272};
    _Bool sign = !(SELECT_BIT(b, 11));
    unsigned short int b0 = SELECT_RANGE(b,10,0) ^ VAL_RESIZE(CE_MACRO32(sign,0xfff,0), 11);
    unsigned short int s = hotbm_t2_pow(b0);
    unsigned char s_1 = SELECT_RANGE(s,7,0);
    unsigned short int k_1 = log_t2_t1_hotbm_table[a];
    BIT_RESIZE(k_1,12);

    unsigned int r0_1 = (((unsigned int) k_1) * ((((unsigned int) s_1) << 1)|1));

    unsigned int r_1 = SELECT_RANGE(r0_1,21,10) ^ (VAL_RESIZE(CE_MACRO32((!SELECT_BIT(s,8)),0xfff,0),12));
    r_1 = r_1 | ((VAL_RESIZE(CE_MACRO32(!SELECT_BIT(s,8),0xfff,0),17))<< 12);

    return r_1;
}

__attribute__((always_inline))
static inline
unsigned int hotbm_log_log_t3(unsigned char a, unsigned char b)
{
    static const unsigned char log_t3_hotbm_table[] = {3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    _Bool sign = !(SELECT_BIT(b, 2));
    unsigned char b0 = SELECT_RANGE(b,1,0) ^ VAL_RESIZE(CE_MACRO32(sign,0xf,0), 2);
    unsigned char x0 = (a<<2) | b0;
    unsigned char r0 = log_t3_hotbm_table[x0];
    BIT_RESIZE(r0,2);
    unsigned int r= r0 ^ VAL_RESIZE(CE_MACRO32(!sign,0xf,0), 2);
    r |= (VAL_RESIZE(CE_MACRO32(!sign,0xfffffff,0), 27))<<2;

    return r;
}

__attribute__((always_inline))
static inline
unsigned int hotbm_log_log(unsigned int x)
{
    static const unsigned int log_t0_hotbm_table[] = {371488631 ,370214139 ,368951989 ,367701975 ,366463897 ,365237560 ,364022772 ,362819346 ,361627102 ,360445860 ,359275447 ,358115692 ,356966429 ,355827497 ,354698734 ,353579988 ,352471104 ,351371934 ,350282334 ,349202159 ,348131272 ,347069535 ,346016814 ,344972979 ,343937902 ,342911457 ,341893521 ,340883974 ,339882697 ,338889576 ,337904496 ,336927347 ,335958019 ,334996406 ,334042403 ,333095908 ,332156819 ,331225039 ,330300469 ,329383015 ,328472585 ,327569085 ,326672426 ,325782521 ,324899282 ,324022624 ,323152465 ,322288721 ,321431313 ,320580162 ,319735190 ,318896321 ,318063479 ,317236592 ,316415586 ,315600391 ,314790937 ,313987156 ,313188979 ,312396340 ,311609175 ,310827418 ,310051008 ,309279881 ,308513978 ,307753237 ,306997600 ,306247009 ,305501407 ,304760737 ,304024945 ,303293975 ,302567774 ,301846290 ,301129471 ,300417265 ,299709622 ,299006493 ,298307829 ,297613582 ,296923705 ,296238151 ,295556875 ,294879831 ,294206974 ,293538262 ,292873650 ,292213097 ,291556560 ,290903999 ,290255371 ,289610639 ,288969761 ,288332699 ,287699415 ,287069870 ,286444028 ,285821852 ,285203305 ,284588352 ,283976957 ,283369086 ,282764705 ,282163779 ,281566276 ,280972162 ,280381405 ,279793974 ,279209836 ,278628960 ,278051316 ,277476874 ,276905603 ,276337474 ,275772458 ,275210526 ,274651650 ,274095802 ,273542954 ,272993079 ,272446150 ,271902140 ,271361024 ,270822775 ,270287368 ,269754778 ,269224979 ,268697947 ,268173658 ,267652088 ,267133213 ,266617009 ,266103454 ,265592524 ,265084198 ,264578452 ,264075266 ,263574616 ,263076482 ,262580842 ,262087675 ,261596961 ,261108680 ,260622810 ,260139332 ,259658226 ,259179473 ,258703053 ,258228948 ,257757137 ,257287604 ,256820329 ,256355294 ,255892481 ,255431872 ,254973450 ,254517197 ,254063096 ,253611130 ,253161283 ,252713537 ,252267876 ,251824284 ,251382745 ,250943242 ,250505761 ,250070285 ,249636800 ,249205289 ,248775738 ,248348133 ,247922457 ,247498697 ,247076838 ,246656866 ,246238767 ,245822527 ,245408132 ,244995568 ,244584822 ,244175880 ,243768730 ,243363357 ,242959750 ,242557895 ,242157779 ,241759390 ,241362715 ,240967743 ,240574460 ,240182856 ,239792917 ,239404632 ,239017989 ,238632977 ,238249585 ,237867800 ,237487612 ,237109009 ,236731980 ,236356515 ,235982603 ,235610232 ,235239393 ,234870075 ,234502267 ,234135959 ,233771141 ,233407802 ,233045934 ,232685525 ,232326566 ,231969048 ,231612960 ,231258293 ,230905038 ,230553185 ,230202726 ,229853650 ,229505948 ,229159613 ,228814634 ,228471003 ,228128711 ,227787749 ,227448109 ,227109783 ,226772761 ,226437036 ,226102599 ,225769441 ,225437556 ,225106934 ,224777567 ,224449449 ,224122570 ,223796923 ,223472501 ,223149295 ,222827298 ,222506503 ,222186901 ,221868487 ,221551252 ,221235188 ,220920290 ,220606550 ,220293960 ,219982513 ,219672204 ,219363024 ,219054967 ,218748026 ,218442195 ,218137466 ,217833833
                                                     };
    unsigned char a_0 = SELECT_RANGE(x,23,16);
    unsigned int r_0 = log_t0_hotbm_table[a_0];
    BIT_RESIZE(r_0,29);

    unsigned char a_1 = SELECT_RANGE(x,23,16);
    unsigned short int b_1 = SELECT_RANGE(x,15,0);
    unsigned int r_1 = hotbm_log_log_t1(a_1, b_1);
    BIT_RESIZE(r_1,29);

    unsigned char a_2 = SELECT_RANGE(x,23,16);
    unsigned short int b_2 = SELECT_RANGE(x,15,4);
    unsigned int r_2 = hotbm_log_log_t2(a_2,b_2);
    BIT_RESIZE(r_2,29);

    unsigned char a_3= SELECT_RANGE(x,23,22);
    unsigned char b_3 = SELECT_RANGE(x,15,13);
    unsigned int r_3 = hotbm_log_log_t3(a_3,b_3);
    BIT_RESIZE(r_3,29);

    unsigned int r = r_0 + r_1 + r_2 + r_3;
    r = SELECT_RANGE(r,28,0); // VAL RESIZE?

    return r;
}

float ADD_BUILTIN_PREFIX(logf)(float x)
{
    _Bool s;
    unsigned short e;
    unsigned int m;
    unsigned long long nELog2,nY0,nY,nZ;
    unsigned int fpX, fpR;
    unsigned int  nX0, nX1, nX;
    unsigned short int nE0;
    unsigned char nE, eR0, eR1, eR2, eR, n_leading_zeros;
    unsigned char sqrt2 = 26;
    _Bool cmpSqrt2;
    _Bool sR;
    unsigned int fR0, fR1, fR ;
    float_uint_converter func_in;
    _Bool LSB_bit, guard_bit,round_bit, sticky_bit, _round;
    unsigned char nZextension;


    func_in.f = x;
    fpX = func_in.b;

    s = (fpX>>31)&1;
    e = SELECT_RANGE(fpX,30,23);
    m = fpX & 0x007fffff;

#ifndef NO_SUBNORMALS
    if ((fpX & 0x7fffffff) == 0) return -__builtin_inff();
#else
    if (e == 0) return -__builtin_inff();
#endif
    if (fpX == 0x7F800000) return __builtin_inff();
    if (fpX == 0xFF800000) return __builtin_nanf("");
    if (e==255)
    {
        func_in.b |= ( 0x7FC << 20 );
        return func_in.f;
    }
    if (s==1) return __builtin_nanf("");
    if(fpX == 0x3F800000) return 0;

#ifndef NO_SUBNORMALS
    if(e==0)
    {
      unsigned int subnormal_lz, mshifted;
      count_leading_zero_macro_lshift(23, m, subnormal_lz,mshifted);
      e = -subnormal_lz;
      m = SELECT_RANGE(mshifted, 21, 0)<<1;
    }
#endif


    cmpSqrt2 = (m>>17) >= sqrt2;



    nE0 = e - (126|((!cmpSqrt2)&1));
    BIT_RESIZE(nE0,9);
    sR = nE0==0 ? cmpSqrt2 : SELECT_BIT(nE0,8);
    nE= sR==1 ? -nE0 : SELECT_RANGE(nE0,7,0);
    nELog2 = (unsigned long long)nE * (unsigned long long)LOG2;

    nX0 = cmpSqrt2==0 ? ((1<<22|SELECT_RANGE(m,21,0))<<1): m;
    nX1 = (((!SELECT_BIT(nX0,23))&1)<<23)|SELECT_RANGE(nX0,22,0);   //m-1
    nX = sR==1 ? -nX1 : nX1;
    BIT_RESIZE(nX,24);

    unsigned int nLogX = hotbm_log_log(nX0);

    nY0 = ((unsigned long long)SELECT_RANGE(nX,22,0))*((unsigned long long) nLogX);
    nY =  ((SELECT_BIT(nX,23))==1) ? ((unsigned long long)nY0-((unsigned long long)nLogX<<23)): nY0;
    BIT_RESIZE(nY,53);
    nZextension = SELECT_BIT(nY,51)?0xff:0;

    nZ = (((unsigned long long)nZextension<<53)|nY) + (((unsigned long long)nELog2)<<26);


#if 1
    unsigned int upper_nZ = nZ >> (60-32);
    count_leading_zero_macro(32, upper_nZ, n_leading_zeros);
    BIT_RESIZE(n_leading_zeros,5);
    nZ <<= 4;
    nZ <<= n_leading_zeros;
    nZ >>=4;
#else
    count_leading_zero_macro_lshift(60, nZ, n_leading_zeros,nZ);
    BIT_RESIZE(n_leading_zeros,5);
#endif
    fR0 = SELECT_RANGE(nZ, 58, 30);
    eR0 = n_leading_zeros;

    //rounding whattttttt????
    float_uint_converter res_fp;

    eR1 = 134 - eR0;
    sticky_bit = (SELECT_RANGE(nZ,33,0) == 0) ? 0 : 1;
    round_bit = SELECT_BIT(fR0, 4);
    guard_bit = SELECT_BIT(fR0, 5);
    LSB_bit = SELECT_BIT(fR0, 6);
    _round = guard_bit&(LSB_bit|round_bit|sticky_bit);


    fR1 = (fR0 >> 6) + _round;
    fR= SELECT_RANGE(fR1,22,0);
    eR2 = eR1 + SELECT_BIT(fR1, 23);
    eR = eR2 & 255;

    res_fp.b=(eR<<23)|fR;
    res_fp.b |=(sR<<31);

	return res_fp.f;
}

float __hide_ieee754_logf (float x)
{
    return ADD_BUILTIN_PREFIX(logf)(x);
}
