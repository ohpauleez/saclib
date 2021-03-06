/*=========================================================================
		       FIRST7(L; a1,a2,a3,a4,a5,a6,a7)

First 7.

Inputs
  L  : list of length 7 or more.

Outputs
  a1, a2, a3, a4, a5, a6, a7 : the first seven elements of L.
=========================================================================*/
#include "saclib.h"

void FIRST7(L, a1_,a2_,a3_,a4_,a5_,a6_,a7_)
       Word L, *a1_,*a2_,*a3_,*a4_,*a5_,*a6_,*a7_;
{
       Word Lp,a1,a2,a3,a4,a5,a6,a7;

Step1: /* Compute. */
       ADV3(L,&a1,&a2,&a3,&Lp);
       ADV4(Lp,&a4,&a5,&a6,&a7,&Lp);

Return: /* Prepare for return. */
       *a1_ = a1;
       *a2_ = a2;
       *a3_ = a3;
       *a4_ = a4;
       *a5_ = a5;
       *a6_ = a6;
       *a7_ = a7;
       return;
}
