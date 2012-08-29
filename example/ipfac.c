/*======================================================================
  FILE
    ipfac.c

  PURPOSE
    The program generates random reducible polynomials, factorizes them,
    and checks the correctness of the factorization by computing the 
    product of the factors and comparing it with the original polynomial.
======================================================================*/
#include "saclib.h"
#include <stdio.h>

int sacMain(argc,argv)

       int argc;
       char *argv[];
{
       Word A,A1,A2,B,F,F1,Fp,N,V,c,e,f,i,j,k,m,q,r,s,a1,a2,b1,b2;

Step0: /* Process command line parameters. */
       if (argc != 2)
	 m = 1;
       else
	 sscanf(argv[1],"%d",&m);

Step1: /* Setup. */
       i = 1;
       r = 3;
       k = 3;
       q = RNRED(1,10);
       N = LIST3(2,2,2);
       V = LIST3(LFS("x"),LFS("y"),LFS("z"));
       printf("\n==========================================================");
       printf("\n                        ipfac                             ");
       printf("\n                                                          ");
       printf("\n   This program does the following:                       ");
       printf("\n      (1) Randomly generate a reducible polynomial.       ");
       printf("\n      (2) Factorize the polynomial.                       ");
       printf("\n      (3) Check the correctness of the factorization by   ");
       printf("\n          computing the product of the factors.         \n");
       printf("\n   Usage:                                                 ");
       printf("\n      %s [SACLIB parameters] [# of polynomials]           ",
              argv[0]);
       printf("\n==========================================================");

Step2: /* Generate a random reducible polynomial. */
       printf("\n\n======================== %2d th ===========================",i);
       printf("\n\nGenerating a random polynomial ...");
       do
         {
         a1 = IPRAN(r,k,q,N);
         b1 = ABS(IRAND(2))+1;
         A1 = IPEXP(r,a1,b1);
         a2 = IPRAN(r,k,q,N);
         b2 = ABS(IRAND(2))+1;
         A2 = IPEXP(r,a2,b2);
         A  = IPPROD(r,A1,A2);
         } 
       while (A == 0);
       IPSCPP(r,A,&s,&c,&A);
       printf("\nRandom polynomial:\n "); IPDWRITE(r,A,V); 

Step3: /* Factorize it. */
       printf("\n\nFactorizing it ...");
       IPFAC(r,A,&s,&c,&F);
       printf("\nIts factors:");
       Fp = F;
       while (Fp != NIL)
         {
         ADV(Fp,&F1,&Fp);
         FIRST2(F1,&e,&f);
         printf("\n(");
         IPDWRITE(r,f,V);
         printf(")^%d",e);
         }
       
Step4: /* Check the correctness of the result. */
       printf("\n\nChecking the correctness ...");
       B = 1; for (j=1; j <= r; j++) B = LIST2(0,B);
       Fp = F;
       while (Fp != NIL)
         {
         ADV(Fp,&F1,&Fp);
         FIRST2(F1,&e,&f);
         B = IPPROD(r,B,IPEXP(r,f,e));
         }
       if (! EQUAL(A,B)) 
         {
         printf("\nSomething is wrong!\n");
         printf("A = "); OWRITE(A); printf("\n");
         printf("F = "); OWRITE(F); printf("\n"); 
         }
       else
         {
         printf("\nCorrect!");
         }

Step5: /* Loop. */
       i++;
       if (i <= m)
         goto Step2;

Step6: /* Some statistics. */
       STATSACLIB();

Return: /* Prepare for return. */
       return(0);
}
