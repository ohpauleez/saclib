/*======================================================================
                      c <- MDPROD(m,a,b)

Modular digit product.  

Inputs
  m   : a positive BETA-integer.  
  a,b : elements of Z_m.  

Otuputs
  c   : a * b.
======================================================================*/
#include "saclib.h"

Word MDPROD(m,a,b)
        Word m,a,b;
{
        Word c,i;
	DWord C,P,Q,T;

Step1: /* Multiply. */
	P = a;
	P = P * b;

Step2: /* Divide. */
	Q = P / m;

Step3: /* Compute the remainder. */
	T = Q * m;
	C = P - T;
	c = (Word)C;

Return: /* Return c. */
        return(c);
}
