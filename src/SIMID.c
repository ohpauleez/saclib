/*======================================================================
                      M <- SIMID(I)

Software interval midpoint.

Input
   I : a software interval.

Output
   c : an approximate midpoint of c.  If p is the precision of I,
       then c is a p-precision software float that is nearest to
       the midpoint of I.
======================================================================*/
#include "saclib.h"

BDigit *SIMID(I)
	BDigit *I;
{
	BDigit *M,p,q;

Step1: /* Add endpoints and diminish  the exponent. */
	p = I[2];
	q = p + 3;
	M = GETARRAY(q);
	FSUM(I,I + q,0,M);
	M[0] = M[0] - 1;

Return: /* Return M. */
	return (M);
}
