/*======================================================================
  FILE
    simple.c

  PURPOSE
    Initializes SACLIB directly, generates two random integers, adds,
    subtracts, multiplies, and divides them.
======================================================================*/
#include "saclib.h"

int main(ac,av)

        int ac;
        char *av[];
{
        Word stack;
        int  argc;
        char **argv;
        Word I,J,Q,R,n;

Step0:  /* Process SACLIB command line parameters and initialize SACLIB. */
        ARGSACLIB(ac,av,&argc,&argv);
        BEGINSACLIB(&stack);

Step1:  /* Process our own command line parameters. */
        if (argc != 2) {
	  n = 10;
	}
	else
	  sscanf(argv[1],"%d",&n);

Step2:  /* Setup. */
	printf("\n==========================================================");
	printf("\n                        simple                            ");
        printf("\n                                                          ");
        printf("\n   This program does the following:                       ");
        printf("\n      (1) Randomly generates two integers.                ");
        printf("\n      (2) Adds, subtracts, multiplies, and divides them.  ");
        printf("\n   Usage:                                                 ");
        printf("\n      %s [SACLIB parameters] [bitsize]            ",argv[0]);
        printf("\n==========================================================");

Step3:  /* Generate random integers. */
	I = IRAND(n); J = IRAND(n);
	SWRITE("\n\nI = "); IWRITE(I);
	SWRITE("\nJ = "); IWRITE(J);

Step4:  /* Do computations. */
	SWRITE("\nI + J = "); IWRITE(ISUM(I,J));
	SWRITE("\nI - J = "); IWRITE(IDIF(I,J));
	SWRITE("\nI * J = "); IWRITE(IPROD(I,J));
	IQR(I,J,&Q,&R);
	SWRITE("\nI / J = "); IWRITE(Q);
	SWRITE("\nI % J = "); IWRITE(R);
	CWRITE('\n');
       
Step5:  /* Some statistics. */
        STATSACLIB();

Return: /* Cleanup. */
        ENDSACLIB(SAC_FREEMEM);
        return(0);
}
