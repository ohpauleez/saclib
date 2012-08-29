/*=========================================================================
                    L <- LIST8(a1,a2,a3,a4,a5,a6,a7,a8)

List, 8 elements.

Inputs
  a1, a2, a3, a4, a5, a6, a7, a8 : objects.

Output
  L : the list (a1,a2,a3,a4,a5,a6,a7,a8).
=========================================================================*/
#include "saclib.h"

Word LIST8(a1,a2,a3,a4,a5,a6,a7,a8)
       Word a1,a2,a3,a4,a5,a6,a7,a8;
{
       Word L;

Step1: /* Construct. */
       L = COMP(a1,COMP(a2,COMP(a3,COMP(a4,COMP(a5,COMP(a6,COMP(a7,COMP(a8,NIL))))))));

Return: /* Return L. */
	return(L);
}

