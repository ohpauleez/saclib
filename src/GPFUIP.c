/*======================================================================
                      A <- GPFUIP(A1,A2)

Gaussian polynomial from univariate integral polynomials.

Inputs
   A_1, A_2 : univariate integral polynomials.
  
Outputs
   A : A_1 + i A_2.  a univariate polynomial with Gaussian
       integer coefficients. 

======================================================================*/
#include "saclib.h"

Word GPFUIP(A1,A2)
       Word A1,A2;

{
        Word A;
        Word B1,B2,a,a1,a2,e,e1,e2;

Step1:  /* Case A = 0. */ 
	if (A1 == 0 && A2 == 0) {
	   A = 0; 
	   goto Return; }

Step2:  /* Case A nonzero. */ 
	A = NIL; 
	if (A1 == 0) 
	   B1 = NIL; 
	else 
	   B1 = A1; 
	if (A2 == 0)
	   B2 = NIL;
	else
	   B2 = A2;
           do { 
	      if (B1 == NIL) 
	         e1 = -1; 
	      else 
	         e1 = FIRST(B1);
              if (B2 == NIL) 
	         e2 = -1; 
	      else 
	         e2 = FIRST(B2); 
	      if (e1 > e2) {
                 ADV2(B1,&e,&a1,&B1); 
	         a2 = 0; } 
	      else if (e2 > e1) { 
	         ADV2(B2,&e,&a2,&B2);
                 a1 = 0; } 
	      else { ADV2(B1,&e,&a1,&B1); 
	             ADV2(B2,&e,&a2,&B2); } 
	      a = LIST2(a1,a2);
              A = COMP2(a,e,A); } 
	   while (!((B1 == NIL && B2 == NIL))); 
	A = INV(A); 

Return: /* Return. */
        return(A);
}
