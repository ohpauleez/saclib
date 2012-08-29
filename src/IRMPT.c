/*===========================================================================
                       s <- IRMPT(n,x)

Integer Rabin-Miller primality test.  

Inputs
   n : an odd integer, >= 3.
   x : an integer, 1 < x < n.

Output
   s : 0 or 1.  If s = 0 then n is composite.  If s = 1 then n is
       probably prime.
===========================================================================*/
#include "saclib.h"

BDigit IRMPT(n,x)
	Word n,x;
{
	BDigit j;
	Word k,m,q,s,y;

Step1: /* Compute k and q such that n = 1 + 2^k q. */
	m = IDIF(n,1);
	k = IORD2(m);
	q = IDP2(m,k);

Step2: /* Set j = 0 and  y = x^q mod n. */
	j = 0;
	y = MIEXP(n,x,q);
	
Step3: /* Test for completion. */
	if ((j == 0 && y == 1) || ICOMP(y,m) == 0) {
	   s = 1;
	   goto Return; }
	if (j > 0 && y == 1) {
	   s = 0;
	   goto Return; }

Step4: /* Increase j by 1.  If j < k set y = y^2 mod n and return
          to Step 3. */
	j = j + 1;
	if (j < k) {
	   y = MIPROD(n,y,y);
	   goto Step3; }

Step5: /* Set s = 0. */
	s = 0;

Return: /* Return s. */
	return(s);
}
