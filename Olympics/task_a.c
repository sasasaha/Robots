#include <stdio.h>
#include <conio.h>
void main (void)
{
  FILE *F;
  int FldOneH = 0, FldOneW = 0, FldTwoH = 0, FldTwoW = 0, FldThreeH = 0, FldThreeW = 0, S, n;

  if ((F = fopen ("Olympics.txt", "rb")) == NULL)
	printf ("Error with reading file");

  fscanf (F, "%i%i%i%i%i%i", &FldOneH, &FldOneW, &FldTwoH, &FldTwoW, &FldThreeH, &FldThreeW);

  printf ("FldOneH: %i, FldOneW: %i, FldTwoH: %i, FldTwoW: %i, FldThreeH: %i, FldThreeW: %i \n", FldOneH, FldOneW, FldTwoH, FldTwoW, FldThreeH, FldThreeW);

  if (FldOneH >= FldTwoH && FldOneH >= FldTwoW)
  {
	n = FldTwoH;
    FldTwoH = FldTwoW;
	FldTwoW = n;
  }
  else if (FldOneH <= FldTwoH && FldOneH <= FldTwoW)
  {
	n = FldOneH;
    FldOneH = FldOneW;
	FldOneW = n;
  }

  if (FldOneW >= FldTwoW)
    if (FldOneH >= FldTwoH)
      S = FldOneH * FldOneW;
	else 
	  S = FldOneH * FldOneW + (FldTwoH * FldTwoW - FldOneH * FldTwoW);
  else 
	if (FldOneH < FldTwoH)
      S = FldTwoH * FldTwoW;
    else 
	  S = FldTwoH * FldTwoW + (FldOneH * FldOneW - FldTwoH * FldOneW);
  
 
  printf ("%i \n", S);

  getch();
}
