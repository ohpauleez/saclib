/*======================================================================
                      b <- MDEXP(m,a,n)

Modular digit exponentiation.  

Inputs
   m : a BETA-integer, m >= 2.
   a : an element of Z/(m). 
   n : a non-negative BETA-integer. 


Output
   b : a^n.
======================================================================*/
#include "saclib.h"

Word MDEXP(m,a,n)
        BDigit m,a,n;
{
        BDigit b,c;

Step1: /* n <= 1. */
        if (n == 0) {
           b = 1;
           goto Return; }
	if (n == 1) {
	   b = a;
	  goto Return; }

Step2: /* a = 0. */
	if (a == 0) {
	   b = 0;
	   goto Return; }

Step3: /* Otherwise. */
        b = 1;
	c = a;
	while (n != 0) {
	   if (n & 1 == 1)
	      b = MDPROD(m,b,c);
	   c = MDPROD(m,c,c);
	   n = n >> 1; }

Return: /* Return b. */
        return(b);
}
