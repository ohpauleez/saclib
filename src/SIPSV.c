/*======================================================================
                           v <- SIPSV(A)

Software interval polynomial sign variations.

Input
    A : a software interval polynomial of positive degree, whose
        leading coefficient has a determinate non-zero sign.

Output
    v :  Either 0, 1, 2 or NIL.
	 If the sign sequence implies that var(A) = 0, v = 0;
	 If the sign sequence implies that var(A) = 1, v = 1;
	 If the sign sequence implies that var(A) >= 2, v = 2;
	 If the sign sequence implies none of the above, v = NIL.
======================================================================*/
#include "saclib.h"

BDigit  SIPSV(A)
        BDigit *A;
{
	BDigit *Ap,i,m,n,p,q2,s,t;
	Word v;

Step1: /* Initialize. */
	n = A[0];
	p = A[3];
	q2 = p + p + 6;
	Ap = A + n * q2 + 1;
	v = 0;
	m = 0;

Step2: /* Compute sign of the leading coefficient. */
	s = SISIGN(Ap);
	t = s;
	i = n - 1;
	Ap = Ap - q2;

Step3: /* Process next coefficient. */
	s = SISIGN(Ap);
	if (s == NIL) {
	   m = m + 1;
	   if (m == 2) {
	      v = NIL;
	      goto Return; } }
	else if (s != 0) {
	   m = 0;
	   if (s == - t) {
	      v = v + 1;
	      if (v == 2)
	         goto Return;
	      t = s; } }

Step4: /* Finished? */
	i = i - 1;
	if (i >= 0) {
	   Ap = Ap - q2;
	   goto Step3; }
	   
Return: /* Return v. */
	return(v);
}
