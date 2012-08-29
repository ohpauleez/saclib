/*======================================================================
  FILE
    product.c

  PURPOSE
    Times execution of IPROD.
======================================================================*/
#include "saclib.h"

int sacMain(argc,argv)

        int argc;
        char *argv[];
{
        Word A,R,T;
        int  i,j,iterations,samples,N,n,n_start,n_end,t;

Step1:  /* Parameters. */
	iterations = 10000;
	samples = 1;
	n_start = 1;
	n_end = 100;
	n = n_start;

Step2:  /* Prepare next test. */
	N = n * ZETA;
	T = 0;

Step3:  /* IPROD. */
	for (i=0; i<samples; i++) {
	  A = IRAND(N);
	  t = ACLOCK();
	  for (j=0; j<iterations; j++)
	    R = IEXP(A,10);
	  t = ACLOCK() - t;
	  T = ISUM(T,t); }

Step4: /* Print timings. */
       AWRITE(n);
       SWRITE("   ");
       RNDWRITE(RNRED(IPROD(1000,T),IPROD(iterations,samples)),2); /* mms.*/
       SWRITE("\n");

Step5:  /* Next BETA-length. */
	if (n < n_end) {
	  n = n + 1;
	  goto Step2; }

Step6:  /* Some statistics. */
        STATSACLIB();

Return:
       return(0);
}
