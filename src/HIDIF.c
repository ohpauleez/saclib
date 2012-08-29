/*======================================================================
                      K <- HIDIF(I,J)

Hardware interval difference.

Inputs
   I, J : Hardware intervals.  

Output
   K : the smallest hardware interval containing I - J.

Warning
   HIDIF is not floating-point overflow-underflow protected.
======================================================================*/
#include "saclib.h"

interval HIDIF(I,J)
	interval I,J;
{
	interval K;

Step1: /* Subtract opposite endpoints. */
	rounddown();
        K.left = I.left - J.right;
        roundup();
        K.right = I.right - J.left;

Return: /* Return K. */
	return(K);
}
