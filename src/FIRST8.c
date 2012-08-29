/*=========================================================================
		       FIRST8(L; a1,a2,a3,a4,a5,a6,a7,a8)

First 8.

Inputs
  L  : a list of length 8 or more.

Outputs
  a1, a2, a3, a4, a5, a6, a7, a8 : the first eight elements of L.
=========================================================================*/
#include "saclib.h"

void FIRST8(L, a1_,a2_,a3_,a4_,a5_,a6_,a7_, a8_)
       Word L, *a1_,*a2_,*a3_,*a4_,*a5_,*a6_,*a7_,*a8_;
{
       Word Lp,a1,a2,a3,a4,a5,a6,a7,a8;

Step1: /* Compute. */
       ADV4(L,&a1,&a2,&a3,&a4,&Lp);
       ADV4(Lp,&a5,&a6,&a7,&a8,&Lp);

Return: /* Prepare for return. */
       *a1_ = a1;
       *a2_ = a2;
       *a3_ = a3;
       *a4_ = a4;
       *a5_ = a5;
       *a6_ = a6;
       *a7_ = a7;
       *a8_ = a8;
       return;
}
