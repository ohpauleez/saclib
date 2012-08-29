/*======================================================================
                          J <- LBRINEG(I)

Logarithmic binary rational interval negative.

Input
   I : a logarithmic binary rational interval.

Output
   J : the negative of I.
======================================================================*/
#include "saclib.h"

Word LBRINEG(I)
	Word I;
{
	Word J;

Step1: /* Negate and interchange endpoints. */
	J = LIST2(LBRNNEG(SECOND(I)),LBRNNEG(FIRST(I)));

Return: /* Return J. */
	return(J);
}
