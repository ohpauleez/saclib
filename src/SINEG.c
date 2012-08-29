/*======================================================================
                      J = SINEG(I)

Software interval negative.

Input
   I : a software interval.

Output
   J : an array of size 2 p + 3 containing - I, where p is the
       precision of I.
======================================================================*/
#include "saclib.h"

extern BDigit *SINEG(I)
	BDigit *I;
{
	BDigit *J,p,q;

Step1: /* Copy endpoints and negate signs. */
	p = I[2];
	q = p + 3;
	J = GETARRAY(q + q);
        FCOPY(I,J + q);
        FCOPY(I + q, J);
	J[1] = - J[1];
	J[q + 1] = - J[q + 1];

Return: /* Return J. */
	return(J);
}
