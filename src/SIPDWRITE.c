/*======================================================================
                        SIPDWRITE(A,k)

Software interval polynomial decimal write.

Inputs
   A : a software interval polynomial.
   k : a nonnegative BETA-digit.

Effect
   A is written as a polynomial in x with the coefficients
   written as intervals, whose endpoints have k decimal digits
   after the decimal point.  An end-of-line character follows
   the polynomial.
======================================================================*/
#include "saclib.h"

void SIPDWRITE(A,k)
	Word *A;
	BDigit k;
{
	BDigit i,n,p,q,t;

Step1: /* Convert and write coefficients. */
	n = A[0];
	p = A[3];
	q = 2 * p + 6;
	t = n * q + 1;
	for (i = n; i >= 0; i--) {
	   SIDWRITE(A + t,k);
	   t = t - q;
	   SWRITE(" x^");
	   IWRITE(i);
	   if (i != 0)
	      SWRITE(" + "); }
	SWRITE("\n");

Return: /* Return. */
	return;
}
