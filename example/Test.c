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
        Word n;
	BDigit I,j,m,mp;
	Word P,Pp,T,Tp,t,tp,t1,t2,u1,u2;

Step0:  /* Process SACLIB command line parameters and initialize SACLIB. */
        ARGSACLIB(ac,av,&argc,&argv);
        BEGINSACLIB(&stack);

Step1:  /* Process our own command line parameters. */
        if (argc != 2) {
	  n = 10;
	}
	else
	  sscanf(argv[1],"%d",&n);

Step2:  /* Initialize: I=1 internal node. */
	I = 1;
	t = LIST1(1);
	m = 1;
	T = LIST1(LIST2(m,t));

Step3:  /* Generate all full binary trees with I+1 internal nodes. */
	I++;
	Tp = NIL;
	while (T != NIL) {
	  ADV(T,&P,&T);
	  FIRST2(P,&m,&t);
	  tp = LCOPY(t);
	  SFIRST(tp,FIRST(tp)+1);
	  Pp = LIST2(m,tp);
	  Tp = COMP(Pp,Tp);
	  t1 = NIL;
	  t2 = LCOPY(t);
	  while (t2 != NIL) {
	    ADV(t2,&j,&t2);
	    t1 = CONC(t1,LIST1(j));
	    u1 = LCOPY(t1);
	    u2 = LCOPY(t2);
	    SFIRST(u1,FIRST(u1)+1);
	    SFIRST(LASTCELL(u1),LAST(u1)-1);
	    if (u2 != NIL) {
	      SFIRST(u2,FIRST(u2)+1); }
	    else
	      u2 = LIST1(1);
	    tp = CONC(u1,u2);
	    mp = m * j;
	    Pp = LIST2(mp,tp);
	    Tp = COMP(Pp,Tp); } }
	T = Tp;
	    
Step5:  /* Test output. */
	SWRITE("internal = "); AWRITE(I); SWRITE("\n");
	LWRITE(T); SWRITE("\n");
	    
Step6:  /* Loop back. */
	if (I < n)
	  goto Step3;

Return: /* Cleanup. */
	OW(NIL);
        STATSACLIB();
        ENDSACLIB(SAC_FREEMEM);
        return(0);
}
