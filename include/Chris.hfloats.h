/*===============================================
                 hfloats.h

  Header file for hardware floats routines.
===============================================*/

/* ----------------------------------------*/
/*            Include                      */
/* ----------------------------------------*/
#include <math.h>
#include <sys/ucontext.h>

/* #include <ieeefp.h> */  /*** Older gcc version? **/
#include <ieee754.h> /** gcc 2.96? linux? *****/
#include <fenv.h>    /** gcc 2.96? linux? *****/

/* ----------------------------------------*/
/*            Hardware Floats              */
/* ----------------------------------------*/

/* DECstations: */
typedef struct {
  unsigned mant_l  : 32;
  unsigned mant_h  : 20;
  unsigned exp     : 11;
  unsigned sign    : 1;
  } ieee_rep;

/* SPARCstations: 
typedef struct {
  unsigned sign    : 1;
  unsigned exp     : 11;
  unsigned mant_h  : 20;
  unsigned mant_l  : 32;
  } ieee_rep; */
typedef union {
  double num;
  ieee_rep rep;
  }  ieee;

#define BIAS 1023
#define MAXEXP 1023
#define MAXEXP1 1024
#define MINEXP -1022
#define MINEXP1 -1023
#define PREC 53
#define PREC1 52

/* ----------------------------------------*/
/*            Rounding modes               */
/* ----------------------------------------*/

/* DECstations:                                        */
/* #define rounddown() swapRM(ROUND_TO_MINUS_INFINITY) */
/* #define roundup()   swapRM(ROUND_TO_PLUS_INFINITY)  */

/* Sun SPARCs: see also man ieee_flags and /usr/include/ieeefp.h */
/* #define rounddown() fpsetround(FP_RM) */
/* #define roundup() fpsetround(FP_RP) */

/* Linux?  gcc 2.96? */
#define rounddown() fesetround(FE_DOWNWARD)
#define roundup() fesetround(FE_UPWARD)

/* ----------------------------------------*/
/*            Hardware intervals           */
/* ----------------------------------------*/

typedef struct {
  double left, right;
} interval;

static interval izero = { 0.0, 0.0 };
static interval ione  = { 1.0, 1.0 };

