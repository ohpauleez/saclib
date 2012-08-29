/*======================================================================
                      OW(B)

Object write.

Inputs
  B : an object.

Side effects
  The input object B is written in the output stream.
======================================================================*/
#include "saclib.h"

void OW(B)
       Word B;
{
       /* hide algorithm */

Step1: /* Write. */
       if (B < BETA)
         AWRITE(B);
       else
         LWRITE(B);
       SWRITE("\n");

Return: /* Prepare for return. */
       return;
}
