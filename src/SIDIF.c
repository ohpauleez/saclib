/*======================================================================
                        SIDIF(I,J,K)

Software interval difference.  

Inputs
   I,J : software intervals of the same precision p.
   K : an array large enough for a software interval of precision p.

Effect
   The p-precision difference is placed in K.
======================================================================*/
#include "saclib.h"

void SIDIF(I,J,K)
	BDigit *I,*J,*K;
{
	BDigit *H;

Step1: /* Negate and add. */
	H = SINEG(J);
	SISUM(I,H,K);

Step2: /* Free array H. */
	FREEARRAY(H);

Return: /* Return. */
	return;
}
