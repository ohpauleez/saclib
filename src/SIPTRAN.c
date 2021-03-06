/*======================================================================
                           B <- SIPTRAN(A,I)

Software interval polynomial translation.

Inputs
   A : a software interval polynomial.
   I : a software interval.

Output
   B : B(x) = B(x + I), a software interval polynomial.
======================================================================*/
#include "saclib.h"

BDigit *SIPTRAN(A,I)
	BDigit *A,*I;
{
	BDigit i,j,n,p,q1,q2,S,t;
	BDigit *B,*Bp,*Bpp,*J,*K;

Step1: /* Get an array for B. */
	n = A[0];
	p = A[3];
	q1 = p + 3;
	q2 = q1 + q1;
	t = n * q2;
	S = t + q2 + 1;
	B = GETARRAY(S);

Step2: /* Copy A into B. */
	for (i = 0; i < S; i++)
	   B[i] = A[i];

Step3: /* Get arrays for software intervals J and K. */
	J = GETARRAY(q2);
	K = GETARRAY(q2);

Step4: /* Translate by synthetic division. */
	Bp = B +  1;
	for (i = 0; i < n; i++) {
	   Bpp = Bp + t;
	   for (j = n - 1; j >= i; j--) {
	      SIPROD(Bpp,I,J);
	      SISUM(Bpp - q2,J,K);
	      SICOPY(K,Bpp - q2);
	      Bpp = Bpp - q2; } }

Step5: /* Free arrays J and K. */
	FREEARRAY(J);
	FREEARRAY(K);

Return: /* Return B. */
	return(B);
}
