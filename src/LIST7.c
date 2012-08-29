/*=========================================================================
                    L <- LIST7(a1,a2,a3,a4,a5,a6,a7)

List, 7 elements.

Inputs
  a1, a2, a3, a4, a5, a6, a7 : objects.

Output
  L : the list (a1,a2,a3,a4,a5,a6,a7).
=========================================================================*/
#include "saclib.h"

Word LIST7(a1,a2,a3,a4,a5,a6,a7)
       Word a1,a2,a3,a4,a5,a6,a7;
{
       Word L;

Step1: /* Construct. */
       L = COMP(a1,COMP(a2,COMP(a3,COMP(a4,COMP(a5,COMP(a6,COMP(a7,NIL)))))));

Return: /* Return L. */
	return(L);
}

