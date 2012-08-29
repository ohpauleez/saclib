/*======================================================================
                           LBRNSI(R,p,I)

Logarithmic binary rational number to software interval.

Inputs
   R : a logarithmic binary rational number.
   p : a BETA-digit, the desired precision.
   I : (pointer to) an array of size at least 2 p + 6.

Effect
   The smallest p-precision software interval containing R is placed
   in I.
======================================================================*/
#include "saclib.h"

void LBRNSI(R,p,I)
       Word R;
       BDigit p;
       Word *I;
{

Step1: /* Apply LBRNF for each endpoint. */
	LBRNF(R,p,-1,I);
	LBRNF(R,p,+1,I + p + 3);

Return: /* Return. */
        return;
}
