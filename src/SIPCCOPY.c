/*======================================================================
                      B <- SIPCCOPY(A)

Software interval polynomial create copy.

Input
   A : a software interval polynomial.

Output
   B : a copy of A.
======================================================================*/
#include "saclib.h"

BDigit *SIPCCOPY(A)
	BDigit *A;
{
	BDigit *B,i,S;

Step1: /* Get an array for B. */
	S = SIPSIZE(A);
	B = GETARRAY(S);

Step2: /* Copy. */
	for (i = 0; i < S; i++)
           B[i] = A[i];

Return: /* Return B. */
	return(B);
}
