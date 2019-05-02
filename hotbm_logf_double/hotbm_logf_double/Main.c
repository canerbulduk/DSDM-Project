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

  unsigned long long int logtable6[] = {0,576460769483293300,1729382411529111600,2882304191013932500,4035226107937788400,5188148162300713000,6341070354102738000,7493992683343898000,8646915150024223000,9799837754143748000,10952760495702503000,12105683374700526000,13258606391137845000,14411529545014493000,15564452836330506000,16717376265085915000};
  unsigned long long int logtable7[] = {0,72057594306363400,216172784529702940,360287976900526300,504403171418833340,648518368084624400,792633566897899300,936748767858658200,1080863970966901100,1224979176222628400,1369094383625839600,1513209593176535000,1657324804874715000,1801440018720379100,1945555234713528000,2089670452854161200};
  unsigned long long int logtable8[] = {0,9007199258935296,27021597801971710,45035996378562560,63050394988707840,81064793632407550,99079192309661700,117093591020470270,135107989764833280,153122388542750720,171136787354222620,189151186199248930,207165585077829660,225179983989964830,243194382935654460,261208781914898500};

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
	epsZ2 = A2==0 ? 0 : 1<<

	// 13bits MS part - 60bits LS part
	L0_1 = logtable0[A0];
	L1_1 = logtable0[A1];
	L2_1 = logtable0[A2];
	L3_1 = logtable0[A3];
	L4_1 = logtable0[A4];
	L5_1 = logtable0[A5];
	L6 = logtable0[A6];
	L7 = logtable0[A7];
	L8 = logtable0[A8];



	SUM_LS=SELECT_RANGE(L7,59,0) + SELECT_RANGE(L6,59,0) + L5 + L4 + L3 + L2 + L1 + L0;
	SUM_MS=

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
