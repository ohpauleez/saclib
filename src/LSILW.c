/*======================================================================
                         w <- LSILW(I)

Logarithmic standard interval - logarithm of width.

Inputs
   I    : an open logarithmic standard interval.

Outputs
   w    : a BETA-integer. Width(I) = 2^w.
======================================================================*/
#include "saclib.h"

BDigit LSILW(I)
       Word I;
{
       Word a,b,k,l,w;

Step1: /* Case analysis. */
       FIRST2(I,&a,&b);
       if (a == 0)
          w = -SECOND(b);
       else if (b == 0)
          w = -SECOND(a);
       else {
          k = SECOND(a);
          l = SECOND(b);
	  if (LBRNSIGN(a) > 0 || LBRNSIGN(b) < 0)
             w = - maxm(k,l);
	  else
	     w = - k + 1; }

Return: /* Prepare for return. */
        return(w);
}
