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

#define LOG2 0x2C5C860  //0x162E42FEFA39EF3
// CE_MACRO32(cond, a, b) = cond[0] && a || ~cond[0] && b  =  c.a + c'b 
#define CE_MACRO32(cond, a, b) ((((unsigned int) ((((int)(cond))<<31)>>31))&(a))|((~((unsigned int) ((((int)(cond))<<31)>>31)))&(b)))

#define PRECISION 200
#define SZ 64

typedef union {
    unsigned int b;
    float f;
} float_uint_converter;



//this part can stay same as single precision. 
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
