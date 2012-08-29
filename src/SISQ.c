/*======================================================================
                        J <- SISQ(I)

Software interval square.  

Input
   I : a software interval.

Output
   J : the square of I.
======================================================================*/
#include "saclib.h"

BDigit *SISQ(I)
	BDigit *I;

{
	BDigit *J,p,q,s1,s2,s;

Step1: /* Get an array for J. */
	p = I[2];
	q = p + 3;
	J = GETARRAY(q + q);

Step2: /* I >= 0. */
	s1 = I[1];
	if (s1 >= 0) {
	   FPROD(I,I,-1,J);
	   FPROD(I + q,I + q,+1,J + q);
	   goto Return; }

Step3: /* I <= 0. */
	s2 = I[q + 1];
	if (s2 <= 0) {
	   FPROD(I + q,I + q,-1,J);
	   FPROD(I,I,+1,J + q);
	   goto Return; }

Step4: /* Otherwise. */
	I[1] = +1;
	s = FCOMP(I,I + q);
	I[1] = -1;
	if (s < 0) {
	   FPROD(I,I,-1,J);
	   FPROD(I + q,I + q,+1,J + q); }
	else {
	   FPROD(I + q,I + q,-1,J);
	   FPROD(I,I,+1,J + q); }

Return: /* Return J. */
	return(J);
}
