#include <stdio.h>
#include <C:\Users\caner\CLionProjects\untitled1\bambu_macros.h>
#include "bambu_macros.h"
#define SUPPORT_SUBNORMALS
#define LOG2 0x2C5C860

#define CE_MACRO32(cond, a, b) ((((unsigned int) ((((int)(cond))<<31)>>31))&(a))|((~((unsigned int) ((((int)(cond))<<31)>>31)))&(b)))

#define MAX(x, y) (((x) > (y)) ? (x) : (y));
#define MIN(x, y) (((x) < (y)) ? (x) : (y));

#define PRECISION 200
#define SZ 64

typedef union {
	unsigned int b;
	float f;
} float_uint_converter;


void range_red(unsigned long long int Y0, unsigned char A, unsigned long long int out[])
{
  //Z = out[0]
  //almostLog = out[1] & out[2]

  unsigned char invtable0[] = {32,32,31,30,29,28,27,27,26,25,25,24,24,23,23,22,43,42,41,41,40,39,38,38,37,36,36,35,35,34,34,33};
	unsigned long int logtable0_1[] = {0,0,266327,541388,825775,1120142,1425216,1425216,1741805,2070812,2070812,2413252,2413252,2770268,2770268,3143156,5910074,6107462,6309607,6309607,6516744,6729125,6947023,6947023,7170733,7400572,7400572,7636886,7636886,7880051,7880051,8130476};
	unsigned long int logtable1_1[] = {0,16400,49296,82322,115479,148767,182188,215742,232570,266327,300220,334251,368421,402730,437180,471772};
	unsigned long int logtable2_1[] = {0,2048,6146,10246,14348,18452,22558,26666,30776,34888,39002,43118,47236,51356,55479,59603};
	unsigned long int logtable3_1[] = {0,256,768,1280,1792,2304,2816,3328,3840,4353,4865,5377,5890,6402,6914,7427};
	unsigned long int logtable4_1[] = {0,32,96,160,224,288,352,416,480,544,608,672,736,800,864,928};
	unsigned long int logtable5_1[] = {0,4,12,20,28,36,44,52,60,68,76,84,92,100,108,116};

	unsigned long long int logtable0_0[] = {0, 0, 443495784957107441, 408967542716309484, 210202761557502709, 586169748105148596, 483367143421258030, 483367143421258030, 272658672494231207, 489550094456689689, 489550094456689689, 154982152445328750, 154982152445328750, 65043238028969363, 65043238028969363, 539027481613361078, 622583452284905181, 759572586635749126, 660371207705242522, 660371207705242522, 253985390270980735, 446061511024831737, 645570292658782688, 645570292658782688, 35466593504830009, 328384990975929281, 328384990975929281, 840155138376129331, 840155138376129331, 936672260909567195, 936672260909567195, 712430320143961608};
	unsigned long long int logtable1_0[] = {0, 24054437449941404, 651381705105933614, 718720183519062944, 253546689982371970, 450311980697035046, 211900181597358425, 761543230352098123, 421132014018166394, 443495784957107441, 918228965153013894, 815353360150571272, 273403381874430950, 599681119542337355, 811752134397187310, 1096475649311993935};
	unsigned long long int logtable2_0[] = {0, 288277297239442841, 289497709739546985, 294099812123855996, 304342014990976339, 322486043632438145, 350796944522549847, 391543091824143748, 446996193910259219, 519431299901810434, 611126806221285649, 724364463162525236, 861429381476625838, 1024610038974018153, 63276782535919071, 285567853176287860};
	unsigned long long int logtable3_0[] = {0, 4503691255436680, 40534870717378714, 112601445241265087, 220707814484637524, 364858378910835840, 545057539789194721, 761309699195240573, 1013619260010888437, 149069121317791972, 473506696824928394, 834014887227713707, 77676594028740779, 510339233358517480, 979085708334582096, 330998922882241584};
	unsigned long long int logtable4_0[] = {0, 70368923135146, 633323529478656, 1759240974382938, 3448129848175812, 5699998741381724, 8514856244721744, 11892710949113582, 15833571445671586, 20337446325706751, 25404344180726727, 31034273602435821, 37227243182735006, 43983261513721926, 51302337187690902, 59184478797132936};
	unsigned long long int logtable5_0[] = {0, 1099511977301, 9895614087178, 27487834385144, 53876189648513, 89060696654644, 133041372180944, 185818233004871, 247391295903928, 317760577655666, 396926095037687, 484887864827638, 581645903803215, 687200228742161, 801550856422270, 924697803621381};
  unsigned long long int logtable6[] = {0,576460769483293354,1729382411529111552,2882304191013932373,4035226107937788586,5188148162300712960,6341070354102738261,7493992683343897259,8646915150024222721,9799837754143747415,10952760495702504110,12105683374700525573,13258606391137844573,14411529545014493878,15564452836330506256,16717376265085914474};
	unsigned long long int logtable7[] = {0,72057594306363393,216172784529702948,360287976900526246,504403171418833353,648518368084624332,792633566897899246,936748767858658161,1080863970966901140,1224979176222628246,1369094383625839545,1513209593176535100,1657324804874714974,1801440018720379233,1945555234713527940,2089670452854161158};
	unsigned long long int logtable8[] = {0,9007199258935296,27021597801971712,45035996378562560,63050394988707840,81064793632407553,99079192309661699,117093591020470277,135107989764833288,153122388542750732,171136787354222609,189151186199248920,207165585077829663,225179983989964840,243194382935654451,261208781914898495};



  unsigned char A0,A1,A2,A3,A4,A5,A6,A7,A8;
  unsigned long long int B0,B1,B2,B3,B4,B5,B6,B7,B8;
	unsigned long long int P0,P1,P2,P3,P4,P5,P6,P7,P8;
	Z0 : Z9 ; //53-69-54 bits
	Z0_d : Z9_d ; //53-69-54 bits
	epsz1 : epsZ8 ; //59-84bits
	L0 : L9; // 57:82bits
	S1 : S9; //82bits
	S1_d : S9_d; //82bits
  unsigned char InvA0;
  A0 = A;
  InvA0 = invtable0[A0];
  L0 = logtable0[A0]; //82bits
  P0 = InvA0 * Y0;

  Z1_d = SELECT_RANGE(P0,53,0);
  S1_d = L0; //82bits

  A1 = SELECT_RANGE(Z1_d,53,50);
  B1 = SELECT_RANGE(Z1_d,49,0);
  L1 = logtable1[A1]; //78bits
  ZM1 = Z1_d;
  P1 = A1*ZM1;

	//epsZ1 = SELECT_BIT(A1,3)==0 ? (SELECT_BIT(A1,2)==0 ? 0 : ((1<<58) | Z1_d)) : ;
	/*
		0000 : 0
	  0XXX : 01 0000 Z1_d
	  else : 1 0000 Z1_d 0
	*/
	epsZ1 = SELECT_RANGE(A1,3,2)==0 ? 0 : (SELECT_BIT(A1,2)==0 ? 0 : ((1<<58) | Z1_d));
	epsZ1 = SELECT_BIT(A1,3)==0 = epsZ1 : epsz1<<1;

	Z2 = (B1<<8) - (P1<<1) + epsZ1;
	S2 = S1_d + L1 ; //82bits

	A2 = SELECT_RANGE(Z2_d,59,56);
	B2 = SELECT_RANGE(Z2_d,55,0);
	L2 = logtable2[A2];
	ZM2 = Z2_d;  //this variable is removable
	P2 = A2 * ZM2 ;
	//68bits
	epsZ2 = A2==0 ? 0 : 1<< ;


	//Sum part is splitted to 2 part , also the tables are splitted to 2 part
	//Less significant part of the tables are 60bits and the rest assigned to more significant tables. 
	// 13bits MS part - 60bits LS part
	// Least significant part never exceed 64 bits. So we don't have any overflow problem.
	unsigned long long int  L0_0, L1_0, L2_0, L3_0, L4_0, L5_0, L6, L7, L8;
	unsigned long int L0_1, L1_1, L2_1, L3_1, L4_1, L5_1;
	L0_1 = logtable0_1[A0];
	L1_1 = logtable1_1[A1];
	L2_1 = logtable2_1[A2];
	L3_1 = logtable3_1[A3];
	L4_1 = logtable4_1[A4];
	L5_1 = logtable5_1[A5];

	L0_0 = logtable0_0[A0];
	L1_0 = logtable1_0[A1];
	L2_0 = logtable2_0[A2];
	L3_0 = logtable3_0[A3];
	L4_0 = logtable4_0[A4];
	L5_0 = logtable5_0[A5];
	L6 = logtable6[A6];
	L7 = logtable7[A7];
	L8 = logtable8[A8];

	SUM_LS = L8 + SELECT_RANGE(L7,59,0) + SELECT_RANGE(L6,59,0) + L5_0 + L4_0 + L3_0 + L2_0 + L1_0 + L0_0;
	SUM_MS = SELECT_RANGE(SUM_LS,63,60) + SELECT_RANGE(L7,63,60) + SELECT_RANGE(L6,63,60) + L5_1 + L4_1 + L3_1 + L2_1 + L1_1 + L0_1;
	BIT_RESIZE(SUM_LS, 60); //

	out[] = "SUM_MS , SUM_LS";

}



float ADD_BUILTIN_PREFIX(logf)(float x)
{

    _Bool s;
    unsigned char wE=11;
    unsigned char wF=52;
    // fpX = 66bit
    unsigned char g=5;
    unsigned char a0=5;
    unsigned char log2wF = 6;
    unsigned char targetprec= 83;
    unsigned char sfinal = 55;
    unsigned char pfinal = 28;
    unsigned long long int log2 = 0b101100010111001000010111111101111101000111001111011110011;
    unsigned short int E0offset = 0b10000001001;
    unsigned char pfinal_s = 0b011100;
    unsigned char lzc_size = 6;
    _Bool FirstBit, sR, small, doRR, ufl, sticky, round;
    unsigned long long Y0, Log_small_normd, Log_g, EFR, Zfinal, Log1p_normal, Z2o2_full, Log_small, Z_small, Z2o2_small ;
	unsigned short int E, absE, E_small, ER, E_normal, lzo, shiftval;
	unsigned int absZ0, absZ0s, squarerIn, Z2o2_small_s, Z2o2;
    unsigned char E0_sub;

    signal absELog2  : std_logic_vector(wF+wE+g-1 downto 0);
    signal absELog2_pad, LogF_normal_pad, Log_normal, Log_normal_normd  : std_logic_vector(wE+targetprec-1 downto 0);
    signal almostLog, logF_normal : std_logic_vector(targetprec-1 downto 0);

    func_in.f = x;
    fpX = func_in.b;

    unsigned long long fpX;
    unsigned char exn;
    //fpx = exn & fpx_0;

    FirstBit = SELECT_BIT(fpX,51);

	Y0 = FirstBit == 0 ? (((1 << 52) | SELECT_RANGE(fpX, 51, 0)) << 1) : ((1 << 52) | SELECT_RANGE(fpx, 51, 0));
	E = SELECT_RANGE(fpX, 62, 52) - ((0b1111111111 << 1) | FirstBit);
    sR = SELECT_RANGE(fpX,62,52)==0b11111111111 ? 0 : !SELECT_BIT(fpX,62);
    absE = sR == 0 ? -E : E;
    absELog2 = absE * log2;

    lzoc1 : lzoc  -- leading zero/one count
      generic map (w => wF,  n => log2wF)
      port map (  i => Y0(wF downto 1), ozb => FirstBit,  zo => lzo); -- lzo = #leading zeros/ones depens FirstBit

    shiftval = lzo - pfinal_s;
    doRR = SELECT_BIT(shiftval,log2wF);
    small = ((E==0) & (doRR==0)) ? 1 : 0;
    absZ0 = sR==0 ? SELECT_RANGE(Y0,(wF-pfinal+1),0) : (0-SELECT_RANGE(Y0,(wF-pfinal+1),0));


    rr: range_red
       port map ( A => fpX(wF-1 downto wF-a0), Y0 => Y0,
                  Z => Zfinal, almostLog => almostLog);

    lshiftsmall: lshift
      generic map (w => wF-pfinal+2,  n => log2wF)
      port map (  i => absZ0, s => shiftval(log2wF-1 downto 0), o => absZ0s );

    squarerIn = doRR==1 ? SELECT_RANGE(Zfinal,(sfinal-1),pfinal) : absZ0 <<(sfinal-wF-3);

    Z2o2_full = squarerIn * squarerIn;
    Z2o2 = SELECT_RANGE(Z2o2_full,53,26);

    Log1p_normal = Zfinal - SELECT_RANGE(Z2o2,27,2);

    absELog2_pad = absELog2 << 26; // targetprec-wF-g = 26
    LogF_normal_pad = SELECT_BIT(logF_normal,(targetprec-1)) ? (0b11111111111<<56) : LogF_normal;

    Log_normal = sR==0 ? (absELog2_pad + LogF_normal_pad) : (absELog2_pad - LogF_normal_pad);

    lzc_norm_0 : lzc_norm
      generic map (w => wE+targetprec, n => lzc_size)
      port map (i => Log_normal, z => E_normal, o => Log_normal_normd);


    rshiftsmall: rshift
      generic map (w => sfinal-pfinal+1,  n => log2wF)
      port map (i => Z2o2,
                s => shiftval(log2wF-1 downto 0),
                o => Z2o2_small_s);

    // send the MSB to position pfinal
    Z2o2_2small = Z2o2_2small<< 30 ; // & wF+g-sfinal downto 0 => '0'

    //mantissa will be either Y0-z^2/2  or  -Y0+z^2/2,  depending on sR
    Z_small = absZ0s << 33; // absZ0s & (pfinal+g-1 downto 0 => '0')
    Log_small = sR==0 ? (Z_small - Z2o2_small) : (Z_small + Z2o2_2small);

    //Possibly subtract 1 or 2 to the exponent, depending on the LZC of Log_small
    //E0_sub
    if (SELECT_BIT(Log_small,(wF+g+1))==1)
    {
      E0_sub = 0b11;
    }
    else if((SELECT_BIT(Log_small,(wF+g+1))==1) & (SELECT_BIT(Log_small,(wF+g))==0) )
    {
      E0_sub=0b10;
    }
    else
    {
      E0_sub=0b01;
    }

    E_small = ((0b11111111<<2)|E0_sub) - lzo;

    //Log_small_normd
    if(SELECT_BIT(Log_small,(wF+g+1))==1)
    {
      Log_small_normd = SELECT_RANGE(Log_small,(wF+g+1),2);
    }
    else if(SELECT_BIT(Log_small,(wF+g))==1)
    {
      Log_small_normd = SELECT_RANGE(Log_small,(wF+g),1);
    }
    else
    {
      Log_small_normd = SELECT_RANGE(Log_small,(wF+g-1),0);
    }

    ER = small==1 ? E_small : (E0offset-E_normal);
    Log_g = small==1 ? SELECT_RANGE(Log_small_normd,(wF+g-2),0)<<1 : SELECT_RANGE(Log_normal_normd,(wE+targetprec-2), (wE+targetprec-wF-g-1)) ;
    sticky = SELECT_RANGE(Log_g, (g-2), 0) == 0 ? 0b0 : 0b1 ;
    round = SELECT_BIT(Log_g,(g-1))&(SELECT_BIT(Log_g,g)|sticky);

    EFR = ((ER<<52)|SELECT_RANGE(Log_g,(wF+g-1),g)) + round;

    /*
    fpR(wE+wF+2 downto wE+wF) <= "110" when ((fpX(wE+wF+2) and (fpX(wE+wF+1) or fpX(wE+wF))) or (fpX(wE+wF+1) and fpX(wE+wF))) = '1' else
                                 "101" when fpX(wE+wF+2 downto wE+wF+1) = "00"                                                       else
                                 "100" when fpX(wE+wF+2 downto wE+wF+1) = "10"                                                       else
                                 "00" & sR when (((Log_normal_normd(wE+targetprec-1)='0') and (small='0')) or ( (Log_small_normd (wF+g-1)='0') and (small='1'))) or (ufl = '1') else
                                 "01" & sR;

    fpR(wE+wF-1 downto 0) <=  EFR;
    */

    return fpR;

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
    nE= sR==1 ? -nE0 : SELECT_RANGE(nE0,7,0); //AbsE
    nELog2 = (unsigned long long)nE * (unsigned long long)LOG2; //AbsE*log2

    nX0 = cmpSqrt2==0 ? ((1<<22|SELECT_RANGE(m,21,0))<<1): m; // Y0
    nX1 = (((!SELECT_BIT(nX0,23))&1)<<23)|SELECT_RANGE(nX0,22,0);   //m-1
    nX = sR==1 ? -nX1 : nX1; //AbsZ0 ??
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
