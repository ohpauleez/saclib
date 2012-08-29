/*======================================================================
  FILE
    ftest.c

  PURPOSE
    Test FPHAND and FPCATCH.
======================================================================*/
#include "saclib.h"

int sacMain(argc,argv)

        int argc;
        char *argv[];
{
        double a,b,c;

Step0:  /* Do it. */
	FPCATCH();
	SWRITE("FPFLAG before = "); AWRITE(FPFLAG); SWRITE("\n");
	a = 1.0;
        b = 0.0;
        c = a/b;
        printf("a/b=%f\n",c);
	SWRITE("FPFLAG after = "); AWRITE(FPFLAG); SWRITE("\n");

Return:
       return(0);
}
