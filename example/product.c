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
        Word I,J,R,T;
        int  i,j,iterations,samples,N,n,n_start,n_end,t;

Step1:  /* Parameters. */
	iterations = 1000000;
	samples = 10;
	n_start = 1;
	n_end = 50;
	n = n_start;

Step2:  /* Prepare next test. */
	N = n * ZETA;
	T = 0;

Step3:  /* IPROD. */
	for (i=0; i<samples; i++) {
	  I = IRAND(N);
	  J = IRAND(N);
	  t = ACLOCK();
	  for (j=0; j<iterations; j++)
	    R = IPROD(I,J);
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
