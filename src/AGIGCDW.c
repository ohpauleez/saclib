/*=======================================================================
                           C <- AGIGCDW(A,B)

Array Gaussian integer greatest common divisor, Weilert's method.

Inputs
   A, B : array Gaussian intgegers.
   C : an array for a greatest common divisor of A and B.

Effect
   A greatest common divisor of A and B (0 if A = B = 0) is
   placed in C.
=======================================================================*/
#include "saclib.h"

BDigit **AGIGCDW(A,B)
	BDigit **A,**B;
{
	BDigit **C,**D,**E,**F,**T1,**T2,**T3,**T4;
	BDigit h,k,k1,k2,m,n,p;

Step1: /* Get auxilliary arrays. */
	m = MAX(A[0][1],A[1][1]);
	n = MAX(B[0][1],B[1][1]);
	p = MAX(m,n) + 3;
	C = GETMATRIX(2,p);
	D = GETMATRIX(2,p);
	E = GETMATRIX(2,p);
	F = GETMATRIX(2,p);
	T1 = GETMATRIX(2,p);
	T2 = GETMATRIX(2,p);
	T3 = GETMATRIX(2,p);
	T4 = GETMATRIX(2,p);

Step2: /* A = 0 or B = 0. */
        if (AGIZERO(A)) {
           AGICOPY(B,C);
           goto Step9; }
        if (AGIZERO(B)) {
           AGICOPY(A,C);
           goto Step9; }

Step3: /* Reduce the inputs. */
	AGIRP(A,D,T1, &k1);
	AGIRP(B,E,T1, &k2);
	k = MIN(k1,k2);

Step4: /* Interchange D and E if required. */
	if (AGINC(D,E) == 1) {
	   T4 = D;
	   D = E;
	   E = T4; }

Step5: /* Compute T1 = D - u * E for suitable unit u. */
	AGIMD(D,E,T1);

Step6: /* Reduce T1 to F and update. */
	if (!AGIZERO(T1))
	   AGIRP(T1,F,T3, &h);
	else
	   AGICOPY(T1,F);
	T4 = D;
	D = E;
	E = F;
	F = T4;

Step7: /* If E /= 0, return to Step4. */
	if (!AGIZERO(E))
	   goto Step4;

Step8: /* Compute C = D * (1 + i)^k. */
	h = k >> 1;
	AGIMP2(D,h,C);
	if ((k & 1) == 1) {
	   AGICOPY(C,D);
	   AISUM(D[0],D[1],C[1]);
	   D[1][0] = - D[1][0];
	   AISUM(D[0],D[1],C[0]); }

Step9: /* Free arrays. */
	FREEMATRIX(D,2);
	FREEMATRIX(E,2);
	FREEMATRIX(F,2);
	FREEMATRIX(T1,2);
	FREEMATRIX(T2,2);
	FREEMATRIX(T3,2);
	FREEMATRIX(T4,2);

Return: /* Return C. */
	return(C);
}
