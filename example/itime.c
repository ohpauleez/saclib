/*======================================================================
  FILE
    itime.c

  PURPOSE
    Computes timings for ISUM, IDIF, IPROD, and IQR.
======================================================================*/
#include "saclib.h"

int sacMain(argc,argv)

        int argc;
        char *argv[];
{
        Word I,J,Q,R,t;
        int  i,j,iterations,integers,n;

Step0:  /* Process our own command line parameters. */
        if (argc != 4) {
          printf("Usage:\n%s [SACLIB parameters] <# of iterations> ",argv[0]);
          printf("<# of integers> <bitlength>\n");
	  goto Return;
	}
	else {
	  sscanf(argv[1],"%d",&iterations);
	  sscanf(argv[2],"%d",&integers);
	  sscanf(argv[3],"%d",&n);
	}

Step1:  /* Setup. */
	printf("\n==========================================================");
	printf("\n                         itime                            ");
        printf("\n                                                          ");
        printf("\n   This program does the following:                       ");
        printf("\n      (1) Randomly generates two integers.                ");
        printf("\n      (2) Adds, subtracts, multiplies, and divides them.  ");
        printf("\n   Usage:                                                 ");
        printf("\n      %s [SACLIB parameters] <# of iterations>    ",argv[0]);
        printf("\n        <# of integers> <bitlength>                       ");
        printf("\n==========================================================");

Step2:  /* Main loop. */
	for (i=0; i<integers; i++) {

Step2a:   /* Generate random integers. */
	  I = IRAND(n); J = IRAND(n/2);
	  SWRITE("\n\nI = "); IWRITE(I);
	  SWRITE("\nJ = "); IWRITE(J);
	  SWRITE("\nbitlength = "); GWRITE(n); CWRITE('\n');

Step2b:   /* ISUM. */
	  SWRITE("\n\nI + J = ");
	  t = ACLOCK();
	  for (j=0; j<iterations; j++)
	    R = ISUM(I,J);
	  t = ACLOCK() - t;
	  IWRITE(R);
	  SWRITE("\nTime for ISUM: ");
	  GWRITE(t/iterations); CWRITE('.');
	  GWRITE((Word)((float)((t%iterations)*1000)/(float)iterations));
	  SWRITE(" milliseconds.");

Step2c:   /* IDIF. */
	  SWRITE("\n\nI - J = ");
	  t = ACLOCK();
	  for (j=0; j<iterations; j++)
	    R = IDIF(I,J);
	  t = ACLOCK() - t;
	  IWRITE(R);
	  SWRITE("\nTime for IDIF: ");
	  GWRITE(t/iterations); CWRITE('.');
	  GWRITE((Word)((float)((t%iterations)*1000)/(float)iterations));
	  SWRITE(" milliseconds.");

Step2d:   /* IPROD. */
	  SWRITE("\n\nI * J = ");
	  t = ACLOCK();
	  for (j=0; j<iterations; j++)
	    R = IPROD(I,J);
	  t = ACLOCK() - t;
	  IWRITE(R);
	  SWRITE("\nTime for IPROD: ");
	  GWRITE(t/iterations); CWRITE('.');
	  GWRITE((Word)((float)((t%iterations)*1000)/(float)iterations));
	  SWRITE(" milliseconds.");

Step2e:   /* IQR. */
	  SWRITE("\n\nI / J = ");
	  t = ACLOCK();
	  for (j=0; j<iterations; j++)
	    IQR(I,J,&Q,&R);
	  t = ACLOCK() - t;
	  IWRITE(Q); SWRITE("\nI % J = "); IWRITE(R);
	  SWRITE("\nTime for IQR: ");
	  GWRITE(t/iterations); CWRITE('.');
	  GWRITE((Word)((float)((t%iterations)*1000)/(float)iterations));
	  SWRITE(" milliseconds.\n");
	}

Step3:  /* Some statistics. */
        STATSACLIB();

Return:
       return(0);
}
