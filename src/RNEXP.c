/*======================================================================
                      S <- RNEXP(R,n)

Rational number exponentiation.  

Inputs
   R : a non-zero rational number.  
   n : a positive BETA-digit.

Output
  S : R^n, a rational number.
======================================================================*/
#include "saclib.h"

Word RNEXP(R,n)
        Word R;
	BDigit n;
{
        Word R1,R2,S,S1,S2;

Step1: /* Exponentiate numerator and denominator. */
        FIRST2(R,&R1,&R2);
	S1 = IEXP(R1,n);
	S2 = IEXP(R2,n);
        S = LIST2(S1,S2);

Return: /* Return S. */
        return(S);
}
