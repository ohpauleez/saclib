/*======================================================================
 	              	  STHIRD(L,a)

Set third element.

Inputs
   L  : a list of length three or more.
   a  : object.

Effect
   The list L is modified by changing its third element to a.
======================================================================*/
#include "saclib.h"

void STHIRD(L,a)
       Word L,a;
{

Step1: /* Use SFIRST and RED2, */
	SFIRST(RED2(L),a);

Return: /* Return. */
	return;
}
