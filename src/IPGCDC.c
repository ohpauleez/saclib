/*======================================================================
			   IPGCDC(r,A,B; C,Ab,Bb)

Integral polynomial greatest common divisor and cofactors.

Inputs
   r : a BETA-digit, r >= 0.
   A,B : integral polynomials in r variables.

Outputs
   C : If A = B = 0 then C = 0.  Otherwise C = gcd(A,B).
   Ab,Bb : If A = B = 0 then Ab = 0 and Bb = 0.  Otherwise
           Ab = A / C and Bb = B / C.
======================================================================*/
#include "saclib.h"

void IPGCDC(r,A,B, C_,Ab_,Bb_)
       Word r,A,B, *C_,*Ab_,*Bb_;
{
       Word Ab,Ah,Ahs,Ap,As,Bb,Bh,Bhs,Bp,Bs,C,Chs,Cp,Cpp,Cs;
       Word P,Q,R,U,Us,V,Vs,W,Ws;
       Word a,ah,b,bh,c,ch,cp,cs;
       BDigit p,q,t;

Step1: /* A = B = 0. */
       if (A == 0 && B == 0) {
	  C = 0;
	  Ab = 0;
	  Bb = 0;
	  goto Return; }

Step2: /* r = 0. */
       if (r == 0) {
	  C = IGCD(A,B);
	  Ab = IEQ(A,C);
	  Bb = IEQ(B,C);
	  goto Return; }

Step3: /* A = 0 or B = 0. */
       if (A == 0) {
	  C = IPABS(r,B);
	  Ab = 0;
	  Bb = PINV(0,IPSIGN(r,B),r);
	  goto Return; }
       if (B == 0) {
	  C = IPABS(r,A);
	  Bb = 0;
	  Ab = PINV(0,IPSIGN(r,A),r);
	  goto Return; }
       
Step4: /* Compute integer contents and primitive parts. */
       IPICPP(r,A,&a,&Ah);
       IPICPP(r,B,&b,&Bh);
       c = IGCD(a,b);

Step5: /* Compute normalization factor. */
       ah = PLBCF(r,Ah);
       bh = PLBCF(r,Bh);
       ch = IGCD(ah,bh);

Step6: /* Compute degree vectors. */
       U = PDEGV(r,Ah);
       V = PDEGV(r,Bh);

Step7: /* Initialize prime list and degree vector. */
       P = LPRIME;
       W = COMP(FIRST(U) + 1,RED(U));

Step8: /* Obtain next prime. */
       if (P == NIL)
	  FAIL("IPGCDC","Prime list exhausted",r,A,B);
       ADV(P,&p,&P);

Step9: /* Map normalization factor. */
       cs = MDHOM(p,ch);
       if (cs == 0)
	  goto Step8;

Step10: /* Map Ah and Bh. */
       As = MPHOM(r,p,Ah);
       Us = PDEGV(r,As);
       if (!EQUAL(U,Us))
	  goto Step8;
       Bs = MPHOM(r,p,Bh);
       Vs = PDEGV(r,Bs);
       if (!EQUAL(V,Vs))
	  goto Step8;

Step11: /* Compute g.c.d. */
	if (r == 1)
	   Cs = MUPGCD(p,As,Bs);
	else
           MPGCDC(r,p,As,Bs,&Cs,&Ahs,&Bhs);

Step12: /* Test for constant g.c.d. */
       if (IPONE(r,Cs) == 1) {
	  C = PINV(0,c,r);
	  Ab = IPIQ(r,A,c);
	  Bb = IPIQ(r,B,c);
	  goto Return; }

Step13: /* Conditional initialization of chinese remainder process. */
       Ws = PDEGV(r,Cs);
       t = VCOMP(W,Ws);
       if (t >= 2) {
	  Q = 1;
	  Ap = 0;
	  Bp = 0;
	  Cp = 0;
	  W = VMIN(W,Ws); }

Step14: /* Test for unlucky prime. */
       if (t == 1 || t == 3)
	  goto Step8;

Step15: /* Apply chinese remainder algorithm. */
       Chs = MPMDP(r,p,cs,Cs);
       q = MDINV(p,MDHOM(p,Q));
       Cpp = IPCRA(Q,p,q,r,Cp,Chs);
       Q = IPROD(Q,p);
       
Step16: /* Test for completion. */
        if (! EQUAL(Cp,Cpp)) {
	   Cp = Cpp;
	   goto Step8; }
	IPICPP(r,Cpp,&cp,&C);
	IPQR(r,A,C, &Ab,&R);
	if (R != 0)
	   goto Step8;
	IPQR(r,B,C, &Bb,&R);
        if (R != 0)
           goto Step8;

Step17: /* Restore content. */
       C = IPIP(r,c,C);

Return: /* Return C, Ab and Bb. */
       *C_ = C;
       *Ab_ = Ab;
       *Bb_ = Bb;
       return;
}
