/*======================================================================
                      R <- PILBRN(a,h)

Pair of integers to logarithmic binary rational number.

Inputs
   a : an integer.
   h : a BETA-integer.

Output
   R : A logarithmic binary rational number equal to a/2^h.
======================================================================*/
#include "saclib.h"

Word PILBRN(a,h)
       Word a;
       BDigit h;
{
       BDigit k,n;
       Word b,R;

Step1: /* R = 0. */
       if (a == 0) {
	  R = 0;
	  goto Return; }

Step2: /* R /= 0. */
       n = IORD2(a);
       b = IDP2(a,n);
       k = h - n;
       R = LIST2(b,k);

Return: /* Return R. */
	return(R);
}
