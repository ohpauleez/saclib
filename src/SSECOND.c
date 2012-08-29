/*======================================================================
 	              	  SSECOND(L,a)

Set second element.

Inputs
   L  : a list of length two or more.
   a  : object.

Effect
   The list L is modified by changing its second element to a.
======================================================================*/
#include "saclib.h"

void SSECOND(L,a)
       Word L,a;
{

Step1: /* Use SFIRST and RED, */
	SFIRST(RED(L),a);

Return: /* Return. */
	return;
}
