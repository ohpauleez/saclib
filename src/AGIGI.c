/*========================================================================
                           B <- AGIGI(A)

Array Gaussian integer to Gaussian integer.

Input
   A : a Guassian integer in array representation.

Output
   B : A in list representation.

========================================================================*/
#include "saclib.h"

Word AGIGI(A)
	BDigit **A;
{
	Word B1,B2,B;

Step1: /* Apply AII twice. */
	B1 = AII(A[0]);
	B2 = AII(A[1]);
	if (B1 == 0 && B2 == 0)
	   B = 0;
	else
	   B = LIST2(B1,B2);

Return: /* Return B. */
	return(B);
}
