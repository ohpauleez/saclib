/*======================================================================
                      LIWRITE(a,s)

Labeled integer write.

Inputs
   a : an integer.
   s : a label for a.

Effect
   The label is writen, followed by an equal sign, followed by the 
   integer a, followed by an end of line character.
======================================================================*/
#include "saclib.h"

void LIWRITE(a,s)
       Word a;
       char *s;
{

Step1: /* Write the parts. */
       SWRITE(s);
       SWRITE(" = ");
       IWRITE(a);
       SWRITE("\n");

Return: /* Return. */
       return;
}
