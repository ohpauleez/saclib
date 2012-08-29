/*======================================================================
                             LBRNHI(r; t,I)

Logarithmic binary rational number to hardware interval.

Input
   r : a logarithmic binary rational number.

Outputs
   t : 0 or 1. 
   I : if t = 0, the smallest hardware interval containing r.
       Otherwise I is undefined due to exponent limitation.
======================================================================*/
#include "saclib.h"

void LBRNHI(r, t_,I_)
	Word r;
	BDigit *t_;
	interval *I_;
{
	BDigit t;
	interval I;
	ieee f1,f2;

Step1: /* Apply LBRNIEEE. */
	LBRNIEEE(r,-1, &f1,&t);
	t = 1 - t;
	if (t != 0)
           goto Return;
	LBRNIEEE(r,+1, &f2,&t);
	t = 1 - t;
        if (t != 0)
           goto Return;
	I.left = f1.num;
	I.right = f2.num;

Return: /* Return t and I. */
	*t_ = t;
	*I_ = I;
}
