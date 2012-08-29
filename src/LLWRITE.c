/*======================================================================
                      LLWRITE(L,s)

Labeled list write.

Inputs
   L : a list.
   s : a label for L.

Effect
   The label is writen, followed by an equal sign, followed by the 
   list L, followed by an end of line character.
======================================================================*/
#include "saclib.h"

void LLWRITE(L,s)
       Word L;
       char *s;
{

Step1: /* Write the parts. */
       SWRITE(s);
       SWRITE(" = ");
       LWRITE(L);
       SWRITE("\n");

Return: /* Return. */
       return;
}
