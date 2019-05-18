#include "bambu_macros.h"



//support subnormals not asked
#define SUPPORT_SUBNORMALS


//#ifdef CHECK_LOG_FUNCTION
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//#include <mpfr.h>
//#include <gmp.h>
//#endif

//#ifdef CHECK_LOG_FUNCTION
//#define ADD_BUILTIN_PREFIX(fname) local_ ## fname
//#else
//#define ADD_BUILTIN_PREFIX(fname) __builtin_ ## fname
//#endif

//#define CE_MACRO64(cond, a, b) ((((unsigned long long int) ((((unsigned long long int)(cond))<<63)>>63))&(a))|((~((unsigned long long int) ((((unsigned long long int)(cond))<<63)>>63)))&(b)))
#define MASK(n)  ((1ULL << (n)) - 1)

//#define PRECISION 200
//#define SZ 64


typedef union{
	unsigned long long int b;
	double f;
} double_uint_converter;


//#ifdef CHECK_LOG_FUNCTION
void print_binary(unsigned long long int x) {
	for (int c = 63; c >= 0; c--)
	{
		unsigned long long int k;
		k = x >> c;
		if (k & 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	return;
}
//#endif


static inline
void range_red(unsigned char A, unsigned long long int Y0, unsigned long long int* Zfinal, unsigned long long int* almostLog_H, unsigned long long int* almostLog_L)
{
	//make them all static const
	//change long with long long 
	static const unsigned char invtable0[] = { 32,32,31,30,29,28,27,27,26,25,25,24,24,23,23,22,43,42,41,41,40,39,38,38,37,36,36,35,35,34,34,33 };
	static const unsigned long int logtable0_1[] = { 0,0,266327,541388,825775,1120142,1425216,1425216,1741805,2070812,2070812,2413252,2413252,2770268,2770268,3143156,5910074,6107462,6309607,6309607,6516744,6729125,6947023,6947023,7170733,7400572,7400572,7636886,7636886,7880051,7880051,8130476 };
	static const unsigned long int logtable1_1[] = { 0,16400,49296,82322,115479,148767,182188,215742,232570,266327,300220,334251,368421,402730,437180,471772 };
	static const unsigned long int logtable2_1[] = { 0,2048,6146,10246,14348,18452,22558,26666,30776,34888,39002,43118,47236,51356,55479,59603 };
	static const unsigned long int logtable3_1[] = { 0,256,768,1280,1792,2304,2816,3328,3840,4353,4865,5377,5890,6402,6914,7427 };
	static const unsigned long int logtable4_1[] = {0,32,96,160,224,288,352,416,480,544,608,672,736,800,864,928};
	static const unsigned long int logtable5_1[] = { 0,4,12,20,28,36,44,52,60,68,76,84,92,100,108,116 };

	static const unsigned long long int logtable0_0[] = {0, 0, 443495784957107441, 408967542716309484, 210202761557502709, 586169748105148596, 483367143421258030, 483367143421258030, 272658672494231207, 489550094456689689, 489550094456689689, 154982152445328750, 154982152445328750, 65043238028969363, 65043238028969363, 539027481613361078, 622583452284905181, 759572586635749126, 660371207705242522, 660371207705242522, 253985390270980735, 446061511024831737, 645570292658782688, 645570292658782688, 35466593504830009, 328384990975929281, 328384990975929281, 840155138376129331, 840155138376129331, 936672260909567195, 936672260909567195, 712430320143961608};
	static const unsigned long long int logtable1_0[] = {0, 24054437449941404, 651381705105933614, 718720183519062944, 253546689982371970, 450311980697035046, 211900181597358425, 761543230352098123, 421132014018166394, 443495784957107441, 918228965153013894, 815353360150571272, 273403381874430950, 599681119542337355, 811752134397187310, 1096475649311993935};
	static const unsigned long long int logtable2_0[] = {0, 288277297239442841, 289497709739546985, 294099812123855996, 304342014990976339, 322486043632438145, 350796944522549847, 391543091824143748, 446996193910259219, 519431299901810434, 611126806221285649, 724364463162525236, 861429381476625838, 1024610038974018153, 63276782535919071, 285567853176287860};
	static const unsigned long long int logtable3_0[] = {0, 4503691255436680, 40534870717378714, 112601445241265087, 220707814484637524, 364858378910835840, 545057539789194721, 761309699195240573, 1013619260010888437, 149069121317791972, 473506696824928394, 834014887227713707, 77676594028740779, 510339233358517480, 979085708334582096, 330998922882241584};
	static const unsigned long long int logtable4_0[] = {0, 70368923135146, 633323529478656, 1759240974382938, 3448129848175812, 5699998741381724, 8514856244721744, 11892710949113582, 15833571445671586, 20337446325706751, 25404344180726727, 31034273602435821, 37227243182735006, 43983261513721926, 51302337187690902, 59184478797132936};
	static const unsigned long long int logtable5_0[] = {0, 1099511977301, 9895614087178, 27487834385144, 53876189648513, 89060696654644, 133041372180944, 185818233004871, 247391295903928, 317760577655666, 396926095037687, 484887864827638, 581645903803215, 687200228742161, 801550856422270, 924697803621381};
	//0,576460769483293354ULL SO ON..
	static const unsigned long long int logtable6[] = {0 ,576460769483293354ULL,1729382411529111552ULL, 2882304191013932373ULL, 4035226107937788586ULL, 5188148162300712960ULL, 6341070354102738261ULL, 7493992683343897259ULL, 8646915150024222721ULL, 9799837754143747415ULL, 10952760495702504110ULL, 12105683374700525573ULL, 13258606391137844573ULL, 14411529545014493878ULL, 15564452836330506256ULL, 16717376265085914474ULL};
	static const unsigned long long int logtable7[] = {0,72057594306363393,216172784529702948,360287976900526246,504403171418833353,648518368084624332,792633566897899246,936748767858658161,1080863970966901140,1224979176222628246,1369094383625839545,1513209593176535100,1657324804874714974,1801440018720379233,1945555234713527940,2089670452854161158};
	static const unsigned long long int logtable8[] = {0,9007199258935296,27021597801971712,45035996378562560,63050394988707840,81064793632407553,99079192309661699,117093591020470277,135107989764833288,153122388542750732,171136787354222609,189151186199248920,207165585077829663,225179983989964840,243194382935654451,261208781914898495};


	unsigned char A0, A1, A2, A3, A4, A5, A6, A7, A8;
	unsigned long long int B1, B2, B3_0, B4_0, B5_0, B6, B7, B8;
	unsigned long long int B3_1, B4_1, B5_1;
	unsigned long long int P0, P1, P2_0, P3_0, P4_0, P5, P6, P7, P8;
	unsigned int P2_1, P3_1, P4_1;
	unsigned long long int ZM1, ZM2, ZM3, ZM4, ZM5, ZM6, ZM7, ZM8;
	unsigned long long int epsZ1, epsZ2_0, epsZ3_0, epsZ4_0, epsZ5_0, epsZ6_0, epsZ7_0, epsZ8_0;
	unsigned long int epsZ2_1, epsZ3_1, epsZ4_1, epsZ5_1, epsZ6_1, epsZ7_1, epsZ8_1;
	unsigned long long int Z, Z3_0, Z4_0, Z5_0, Z6_0, Z7_0, Z8_0, Z9;
	unsigned long int Z3_1, Z4_1, Z5_1, Z6_1;
	unsigned long long int Z1_d, Z2_d, Z3_d_0, Z4_d_0, Z5_d_0, Z6_d, Z7_d, Z8_d;
	unsigned long int Z3_d_1, Z4_d_1, Z5_d_1;
	unsigned char InvA0;

	A0 = A;
	InvA0 = invtable0[A0];
	P0 = InvA0 * Y0;

	Z1_d = SELECT_RANGE(P0, 53, 0);

	A1 = SELECT_RANGE(Z1_d, 53, 50);
	B1 = SELECT_RANGE(Z1_d, 49, 0);
	ZM1 = Z1_d;
	P1 = A1 * ZM1;
	//***********
	//	epsZ1 = SELECT_BIT(A1,3)==0 ? (SELECT_BIT(A1,2)==0 ? 0 : ((1<<58) | Z1_d)) : ;
	//	0000 : 0
	//  0XXX : 01 0000 Z1_d
	//  else : 1 0000 Z1_d 0
	//***********
	epsZ1 = A1 == 0 ? 0 : (((unsigned long long)1 << 58) | Z1_d);
	epsZ1 = SELECT_BIT(A1, 3) == 0 ? epsZ1 : epsZ1 << 1;

	Z2_d = (B1<<9) - (P1<<1) + epsZ1;
	
	A2 = SELECT_RANGE(Z2_d, 59, 56);
	B2 = SELECT_RANGE(Z2_d, 55, 0);
	ZM2 = Z2_d;  
	//P2 = A2 * ZM2 ; 68bits
	//while Amax=1b1111=15, we can split ZM and P as 60bits and rest
	P2_0=ZM2*A2;
	P2_1 = SELECT_RANGE(P2_0, 63, 60);
	BIT_RESIZE(P2_0,60);
	epsZ2_0 = A2==0 ? 0 : Z2_d;
	epsZ2_1 = A2==0 ? 0 : 1<<7;	
	Z3_0 = SELECT_RANGE(epsZ2_0,59,0) + (SELECT_RANGE(B2,47,0)<<12) - (SELECT_RANGE(P2_0,58,0)<<1);
	Z3_1 = SELECT_RANGE(epsZ2_1,8,0) + SELECT_RANGE(B2, 55, 48) - SELECT_BIT(P2_0, 59) - ((unsigned long long)P2_1<<1); // SELECT_BIT(Z3_0, 60);
	Z3_1 = SELECT_RANGE(Z3_0, 63, 60) == 0b1111 ? Z3_1 - 1 : Z3_1 + SELECT_BIT(Z3_0, 60);
	BIT_RESIZE(Z3_0,60);
	BIT_RESIZE(Z3_1, 9);

	Z3_d_0 = Z3_0;
	Z3_d_1 = Z3_1;
	
	A3 = SELECT_RANGE(Z3_d_1,8,5); // 68:60-59:0
	B3_1 = SELECT_RANGE(Z3_d_1,4,0);
	B3_0 = Z3_d_0;
	ZM3 = (SELECT_RANGE(Z3_d_1,8,0)<<54) | SELECT_RANGE(Z3_d_0,59,6);
	P3_0 = SELECT_RANGE(ZM3,59,0) * A3;  
	P3_1 = SELECT_RANGE(ZM3,62,60) * A3 + SELECT_RANGE(P3_0,63,60);
	BIT_RESIZE(P3_0, 60);
	epsZ3_0 = A3 == 0 ? 0 : Z3_d_0;
	epsZ3_1 = A3 == 0 ? 0 : (1 << 19) | Z3_d_1;
	Z4_0 = (SELECT_RANGE(B3_0,55,0)<<4) 
		 + SELECT_RANGE(epsZ3_0,59,11) + (SELECT_RANGE(epsZ3_1,10,0)<<49) 
		 - SELECT_RANGE(P3_0,59,4) - (SELECT_RANGE(P3_1,3,0)<<56);
	Z4_1 = SELECT_RANGE(B3_0, 59, 56) + (B3_1 << 4)
		+ SELECT_RANGE(epsZ3_1, 20, 11)
		- SELECT_RANGE(P3_1, 6, 4);
	Z4_1 = SELECT_RANGE(Z4_0, 63, 60) == 0b1111 ? Z4_1 - 1 : Z4_1 + SELECT_BIT(Z4_0, 60);
	BIT_RESIZE(Z4_0,60);
	
	Z4_d_0 = Z4_0;
	Z4_d_1 = Z4_1;
	
	A4 = SELECT_RANGE(Z4_d_1, 9, 6);
	B4_1 = SELECT_RANGE(Z4_d_1, 5, 0);
	B4_0 = Z4_d_0;
	ZM4 = (SELECT_RANGE(Z4_d_1, 9, 0) << 47) | SELECT_RANGE(Z4_d_0, 59, 13);
	P4_0 = ZM4 * A4;
	P4_1 = SELECT_BIT(P4_0, 60);
	BIT_RESIZE(P4_0, 60);
	epsZ4_0 = A4 == 0 ? 0 : Z4_d_0;
	epsZ4_1 = A4 == 0 ? 0 : (1 << 23) | Z4_d_1;
	Z5_0 = B4_0 
		 + SELECT_RANGE(epsZ4_0,59,18) + (SELECT_RANGE(epsZ4_1,17,0)<<42) 
		 - SELECT_RANGE(P4_0,59,4) - ((unsigned long long)SELECT_BIT(P4_1,0)<<56);
	Z5_1 = B4_1 + SELECT_RANGE(epsZ4_1, 24, 18);
	Z5_1 = SELECT_RANGE(Z5_0, 63, 60) == 0b1111 ? Z5_1 - 1 : Z5_1 + SELECT_BIT(Z5_0, 60);
	BIT_RESIZE(Z5_0,60);
	
	Z5_d_0 = Z5_0;
	Z5_d_1 = Z5_1;
	
	A5 = SELECT_RANGE(Z5_d_1, 6, 3);
	B5_1 = SELECT_RANGE(Z5_d_1, 2, 0);
	B5_0 = Z5_d_0;
	ZM5 = (SELECT_RANGE(Z5_d_1, 6, 0) << 44) | SELECT_RANGE(Z5_d_0, 59, 16);
	P5 = ZM5 * A5; //55bits - no need to split
	epsZ5_0 = A5 == 0 ? 0 : Z5_d_0;
	epsZ5_1 = A5 == 0 ? 0 : (1 << 23) | Z5_d_1;
	Z6_0 = B5_0 + SELECT_RANGE(epsZ5_0,59,21) + (SELECT_RANGE(epsZ5_1,20,0)<<39) - SELECT_RANGE(P5,54,4);
	Z6_1 = B5_1 + SELECT_RANGE(epsZ5_1,24,21) ;
	Z6_1 = SELECT_RANGE(Z6_0, 63, 60) == 0b1111 ? Z6_1 - 1 : Z6_1 + SELECT_BIT(Z6_0, 60);
	BIT_RESIZE(Z6_0, 60);
	Z6_d = (SELECT_RANGE(Z6_1, 3, 0) << 60) | Z6_0;	

	A6 = SELECT_RANGE(Z6_d, 63, 60);
	B6 = SELECT_RANGE(Z6_d, 59, 0);//60bits
	ZM6 = SELECT_RANGE(Z6_d, 63, 19);
	P6 = A6 * ZM6;
	epsZ6_0 = A6 == 0 ? 0 : SELECT_RANGE(Z6_d, 59, 0);
	epsZ6_1 = A6 == 0 ? 0 : (1 << 23) | SELECT_RANGE(Z6_d, 63, 60);
	Z7_0 = B6 + SELECT_RANGE(epsZ6_0,59,24) + (SELECT_RANGE(epsZ6_1,24,0)<<36) - SELECT_RANGE(P6,48,4);
	BIT_RESIZE(Z7_0, 61);

	//Z7_1 = 0;
	//Z7_d = (((unsigned long long int)SELECT_BIT(Z7_1, 0)) << 60) | Z7_0;
	Z7_d = Z7_0;

	
	A7 = SELECT_RANGE(Z7_d, 60, 57);
	B7 = SELECT_RANGE(Z7_d, 56, 0);
	ZM7 = SELECT_RANGE(Z7_d, 60, 22);
	P7 = A7 * ZM7;
	epsZ7_0 = A7 == 0 ? 0 : SELECT_RANGE(Z7_d, 59, 0);
	epsZ7_1 = A7 == 0 ? 0 : (1 << 23) | SELECT_BIT(Z7_d, 60);
	Z8_0 = B7 + SELECT_RANGE(epsZ7_0,59,27) + (SELECT_RANGE(epsZ7_1,24,0)<<33) - SELECT_RANGE(P7,42,4);

	Z8_d = Z8_0;

	A8 = SELECT_RANGE(Z8_d, 57, 54);
	B8 = SELECT_RANGE(Z8_d, 53, 0);
	ZM8 = SELECT_RANGE(Z8_d, 57, 25);
	P8 = A8 * ZM8;
	epsZ8_0 = A8 == 0 ? 0 : Z8_d;
	epsZ8_1 = A8 == 0 ? 0 : (1 << 23);
	Z9 = B8 + SELECT_RANGE(epsZ8_0,59,30) + (SELECT_RANGE(epsZ8_1,24,0)<<30) - SELECT_RANGE(P8,36,4);

	Z = Z9;

	//Sum part is splitted to 2 part , also the tables are splitted to 2 part
	//Less significant part of the tables are 60bits and the rest assigned to more significant tables.
	// 13bits MS part - 60bits LS part
	// Least significant part never exceed 64 bits. So we don't have any overflow problem.
	unsigned long long int  L0_0, L1_0, L2_0, L3_0, L4_0, L5_0, L6, L7, L8;
	unsigned long int L0_1, L1_1, L2_1, L3_1, L4_1, L5_1;
	unsigned long long int SUM_LS;
	unsigned long int SUM_MS;
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

	*Zfinal = Z;
	*almostLog_H = SUM_MS;
	*almostLog_L = SUM_LS;

	//out[0] = Z;
	//out[1] = SUM_MS;
	//out[2] = SUM_LS;
	//return out;
}



double logd(double x)
{

	//make them all const
	static unsigned char wE = 11;
	static unsigned char wF = 52;
	static unsigned char g = 5;
	static unsigned char a0 = 5;
	static unsigned char log2wF = 6;
	static unsigned char targetprec = 83;
	static unsigned char sfinal = 55;
	static unsigned char pfinal = 28;
	static unsigned long long int log2 = 0b101100010111001000010111111101111101000111001111011110011;
	static unsigned short int E0offset = 0b10000001001;
	static unsigned char pfinal_s = 0b011100;
	static unsigned char lzc_size = 6;
	double_uint_converter func_in;
	unsigned long long int fpX;
	unsigned char exn;   //at VHDL, fpX has +2bit for exn part 
	_Bool s, FirstBit, sR, small, doRR, ufl, sticky, round;
	unsigned long long int Y0, Log_small_normd, Log_g, EFR, Zfinal, Log1p_normal, Z2o2_full, Log_small, Z_small, Z2o2_small, ER, squarerIn, Z2o2_small_s, Z2o2;
	unsigned short int E, absE, E_small, E_normal, lzo, shiftval, E_normal_H, E_normal_L;
	unsigned int absZ0, absZ0s;
	unsigned char E0_sub;
	unsigned int absELog2_H;
	unsigned long long int absELog2_L;
	unsigned long long int  Log_normal_normd_H, Log_normal_normd_L;//  : std_logic_vector(wE+targetprec-1 downto 0);
	unsigned long long int 	almostLog_H, almostLog_L,
							absELog2_pad_H, absELog2_pad_L,
							LogF_normal_H, LogF_normal_L, // : std_logic_vector(targetprec - 1 downto 0);
							LogF_normal_pad_H, LogF_normal_pad_L,
							Log_normal_H, Log_normal_L;

	func_in.f = x;
	fpX = func_in.b;	
	
	s = SELECT_BIT(fpX,63);
	FirstBit = SELECT_BIT(fpX, 51);

	Y0 = FirstBit == 0 ? (((((unsigned long long)1) << (int)52) | SELECT_RANGE(fpX, 51, 0)) << 1) : (((unsigned long long)1 << 52) | SELECT_RANGE(fpX, 51, 0));
	E = SELECT_RANGE(fpX, 62, 52) - ((0b111111111 << 1) | !FirstBit);
	BIT_RESIZE(E, 11);
	sR = SELECT_RANGE(fpX, 62, 52) == 0b1111111111 ? 0 : !SELECT_BIT(fpX, 62);
	absE = sR == 1 ? -E : E;
	BIT_RESIZE(absE,11);
	
//#ifndef NO_SUBNORMALS
//    if ((fpX & 0x7fffffffffffffff) == 0) return -__builtin_inf();	// 0 -> -inf
//#else
//    if (E == 0) return -__builtin_inff();	// -0 -> -inf
//#endif
//    if (fpX == 0x7FF0000000000000) return __builtin_inf();		//+inf -> inf
//    if (fpX == 0xFFF0000000000000) return __builtin_nan("");	//-inf -> NaN
//    if (E==2047)
//    {
//        func_in.b |= ( 0xFFF << 51 ); //NaN -> NaN
//        return func_in.f;
//    }
//    if (s==1) return __builtin_nan(""); //negative -> NaN
//    if(fpX == 0x3FF0000000000000) return 0; // +1 -> 0
//	

	//absELog2 <= absE * log2;
	//to calculate AbsELog
	unsigned long int m1 = (log2 >> 49) * absE;            // middle 19 bits at offset 49;
	unsigned long long int m0 = (log2 & MASK(49)) * absE + ((m1 & MASK(11)) << 49); // low 61 bits
	absELog2_H = (unsigned int)(m1 >> 11) + (unsigned int)(m0 >> 60); // final high 8 bits
	absELog2_L = m0 & MASK(60);  // SELECT_RANGE(m0,59,0)

	//lzoc1 : lzoc  -- leading zero/one count
	if(FirstBit){ count_leading_zero_macro(52, 0xffffffffffffff & ~SELECT_RANGE(Y0, 52, 1), lzo); }
	else if (!FirstBit) { count_leading_zero_macro(52, SELECT_RANGE(Y0, 52, 1), lzo); }
	BIT_RESIZE(lzo, 6);



    shiftval = lzo - pfinal_s;
    doRR = SELECT_BIT(shiftval,log2wF);
    small = ((E==0) & (doRR==0)) ? 1 : 0;
    absZ0 = sR==0 ? SELECT_RANGE(Y0,25,0) : (0-SELECT_RANGE(Y0,25,0)); // wF-pfinal+1 = 25
	BIT_RESIZE(absZ0,26);

	//	rr: range_red
	unsigned char A = SELECT_RANGE(fpX, 51, 47); //first 4 bit of fraction part
	range_red(A, Y0, &Zfinal, &almostLog_H, &almostLog_L);
	
	//unsigned long long int *out;
	//out = range_red(A, Y0);
	//Zfinal = out[0];
	//almostLog_H = out[1];
	//almostLog_L = out[2];
	
	//lshiftsmall: lshift
	BIT_RESIZE(shiftval, 7); 
	absZ0s = (unsigned long long)absZ0 << (shiftval);
	BIT_RESIZE(absZ0s, 25);
	squarerIn = doRR == 1 ? SELECT_RANGE(Zfinal, 54, 28) :(unsigned long long) absZ0s<<1; // << (sfinal - wF - 3); // SELECT_RANGE(Zfinal, sfinal - 1, pfinal) 
	BIT_RESIZE(squarerIn, 27);
    Z2o2_full = squarerIn * squarerIn;
    Z2o2 = SELECT_RANGE(Z2o2_full,53,26);

    Log1p_normal = Zfinal - SELECT_RANGE(Z2o2,27,2);
	BIT_RESIZE(Log1p_normal,55);
	
  	LogF_normal_L = almostLog_L + Log1p_normal;
	LogF_normal_H = almostLog_H + SELECT_BIT(LogF_normal_L,60);
	BIT_RESIZE(LogF_normal_L,60);
	
	absELog2_pad_H = ((unsigned long long)absELog2_H << 26) | (SELECT_RANGE(absELog2_L,59,34)); // targetprec-wF-g = 26
	absELog2_pad_L = SELECT_RANGE(absELog2_L,33,0)<<26;
		
    LogF_normal_pad_L = LogF_normal_L;
	LogF_normal_pad_H = SELECT_BIT(LogF_normal_H,22) ? ((unsigned long long)(0b11111111111)<<23) | LogF_normal_H : LogF_normal_H;
	
	Log_normal_L = sR == 0 ? (absELog2_pad_L + LogF_normal_pad_L) : absELog2_pad_L - LogF_normal_pad_L;
	Log_normal_H = sR == 0 ? (absELog2_pad_H + LogF_normal_pad_H + SELECT_BIT(Log_normal_L, 60)) : absELog2_pad_H - LogF_normal_pad_H - SELECT_BIT(Log_normal_L,60);
	BIT_RESIZE(Log_normal_L,60);
	
	//   lzc_norm_0 : lzc_norm
	count_leading_zero_macro(60, Log_normal_L, E_normal_L);
	count_leading_zero_macro(34, Log_normal_H, E_normal_H);
	E_normal = E_normal_H > 33 ? E_normal_L + 34 : E_normal_H;
	Log_normal_normd_H = E_normal < 34 ? (Log_normal_H << E_normal)| ((unsigned long long)Log_normal_L>>(60-E_normal))  : (Log_normal_L>>(60-E_normal)); 
	BIT_RESIZE(Log_normal_normd_H, 34);
	Log_normal_normd_L = E_normal < 34 ? Log_normal_L << (E_normal) : (Log_normal_L<<E_normal);
	BIT_RESIZE(Log_normal_normd_L, 60);

	
	//   rshiftsmall: rshift
	Z2o2_small_s = shiftval>58 ? 0 : Z2o2 >> ((unsigned char) shiftval);  //log2wf
	BIT_RESIZE(Z2o2_small_s, 28);


	Z2o2_small = ((unsigned long long)Z2o2_small_s) <<3;   // & wF+g-sfinal downto 0 => '0'
	
    //mantissa will be either Y0-z^2/2  or  -Y0+z^2/2,  depending on sR
	Z_small = ((unsigned long long)absZ0s) << 33; // absZ0s & (pfinal+g-1 downto 0 => '0')
    Log_small = sR==0 ? (Z_small - Z2o2_small) : (Z_small + Z2o2_small);
	BIT_RESIZE(Log_small,59);
    
	//Possibly subtract 1 or 2 to the exponent, depending on the LZC of Log_small
    //E0_sub
    if (SELECT_BIT(Log_small,(wF+g+1))==1)
    {
      E0_sub = 0b11;
    }
    else if((SELECT_BIT(Log_small,(wF+g+1))==0) & (SELECT_BIT(Log_small,(wF+g))==1) )
    {
      E0_sub=0b10;
    }
    else
    {
      E0_sub=0b01;
    }

    E_small = ((0b11111111<<2)|E0_sub) - lzo;
	BIT_RESIZE(E_small,11);

    //Log_small_normd
    if(SELECT_BIT(Log_small,(wF+g+1))==1)
    {
		Log_small_normd = SELECT_RANGE(Log_small, 58, 2); //(wF+g+1)=58
    }
    else if(SELECT_BIT(Log_small,(wF+g))==1)
    {
		Log_small_normd = SELECT_RANGE(Log_small, 57, 1); //(wF+g)=57
    }
    else
    {
		Log_small_normd = SELECT_RANGE(Log_small, 56, 0); //(wF+g-1)=57
    }

    ER = small==1 ? E_small : (E0offset-E_normal);
	//Log_g = small==1 ? SELECT_RANGE(Log_small_normd,(wF+g-2),0)<<1 : SELECT_RANGE(Log_normal_normd,(wE+targetprec-2), (wE+targetprec-wF-g-1)) ;
	Log_g = small == 1 ? SELECT_RANGE(Log_small_normd, 55, 0) << 1 : (SELECT_RANGE(Log_normal_normd_H, 32, 0) << 24) | (SELECT_RANGE(Log_normal_normd_L, 59, 36));
	sticky = SELECT_RANGE(Log_g, 3, 0) == 0 ? 0b0 : 0b1; // (g-2)=3
    round = SELECT_BIT(Log_g,(g-1))&(SELECT_BIT(Log_g,g)|sticky);
	ufl = 0;

	EFR = ((ER << 52) | SELECT_RANGE(Log_g, 56, 5)) + round; //SELECT_RANGE(Log_g,(wF+g-1),g))
	exn = 0;


	double_uint_converter res_fp;
	res_fp.b = ((unsigned long long)sR<<63)|EFR;

	return res_fp.f;
}

//float __hide_ieee754_logd (float x)
//{
//    return ADD_BUILTIN_PREFIX(logd)(x);
//}


#include <time.h>

//	dummy test.
//	suggestion needed. 

int main_test_log() {

	unsigned long long int i = 0;
	unsigned long long int correct_count = 0;
	unsigned long long int wrong_count = 0;
	unsigned long long int n_ones_pos = 0;
	unsigned long long int n_ones_neg = 0;
	double_uint_converter test_for, test_logd, test_log;

	double total_time;
	clock_t start, end;
	start = clock();

	//for (unsigned long long int i = 0x3ff0001d283bb342; i < 0x7FF0000000000000; i=i+10) //starts input = 1; E=1023

	for (unsigned long long int exp = 1; exp < 2047; exp++)
	{
		//#pragma omp parallel for
		//parallel calculation couldn't enabled. 
		for (unsigned long long int m = 1; m < 0xffff; m++)
		{
			i = exp << 52 | m;
			test_for.b = i;
			test_logd.f = logd(test_for.f);
			test_log.f = log(test_for.f);
			unsigned long long int test_logd_shift = test_logd.b >> 3;
			unsigned long long int test_log_shift = test_log.b >> 3;
			if (test_logd.b == test_log.b) {
				correct_count++;
			}
			else if (abs(test_logd.b - test_log.b) == 1)
			{
				if (test_logd.b > test_log.b)
					n_ones_pos++;
				else
					n_ones_neg++;
			}
			else {
				wrong_count++;
				printf("\nInput value:\t\t%.50f",test_for.f);
				printf("\nCalculated value:\t%.50f\n\t\t\t",test_logd.f);
				print_binary(test_logd.b);
				printf("Expected value:\t\t%.50f\n\t\t\t",test_log.f);
				print_binary(test_log.b);
				printf("wrong count:%llu", wrong_count);

			}
		}
	}

	end = clock();
	//time count stops 
	total_time = ((double)(end - start)) / CLK_TCK;
	//calulate total time
	printf("\nTime taken to calculate: %f ms\n", total_time * 1000);
	printf("\nPer calculation time taken to calculate: %f ms\n", (total_time * 1000) / correct_count);

	printf("\nCalculation freq: %f MHz\n", correct_count / (total_time * 1000000));

	printf("wrong_count=%llu\n", wrong_count);
	printf("correct_count=%llu\n", correct_count);
	printf("n_ones_pos=%llu\n", n_ones_pos);
	printf("n_ones_neg=%llu\n", n_ones_neg);
	return 0;

}


int main()
{
	
	printf("*** main ***\n");
	double_uint_converter test_in,test_out;
	test_in.f =
		0.00000000001111111111222222222200000000000000000000;
	test_out.f = logd(test_in.f);
	printf("\nTest Input:\t");
	print_binary(test_in.b);
	printf("\t\t%.15f", test_in.f);
	printf("\nTest Output:\t");
	print_binary(test_out.b);
	printf("\t\t%.60f\n", test_out.f);
	printf("\t\t%.60f\n", log(test_in.f));
	printf("\n\n\n");
	
	main_test_log();
	




	return 0;

}

