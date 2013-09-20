#include <stdio.h>
#include <conio.h>
int min (int a, int b)
{
  if (a > b)
	return b;
  else
	return a;
}
int max (int a, int b)
{
  if (a > b)
	return a;
  else
	return b;
}
void swap (int *a, int *b)
{
  int n;

  n = *a;
  *a = *b;
  *b = n;
}
void main (void)
{
  FILE *F;
  int FldOneH = 0, FldOneW = 0, FldTwoH = 0, FldTwoW = 0, FldThreeH = 0, FldThreeW = 0, S, n;

  if ((F = fopen ("Olympics.txt", "rb")) == NULL)
	printf ("Error with reading file");

  fscanf (F, "%i%i%i%i%i%i", &FldOneH, &FldOneW, &FldTwoH, &FldTwoW, &FldThreeH, &FldThreeW);
  printf ("1st: FldOneH: %i, FldOneW: %i, FldTwoH: %i, FldTwoW: %i, FldThreeH: %i, FldThreeW: %i \n", FldOneH, FldOneW, FldTwoH, FldTwoW, FldThreeH, FldThreeW);

  if (FldOneH < FldOneW)
    swap (&FldOneH, &FldOneW);
  if (FldTwoH < FldTwoW)
    swap (&FldTwoH, &FldTwoW);
  if (FldThreeH < FldThreeW)
    swap (&FldThreeH, &FldThreeW);

  printf ("2nd: FldOneH: %i, FldOneW: %i, FldTwoH: %i, FldTwoW: %i, FldThreeH: %i, FldThreeW: %i \n\n", FldOneH, FldOneW, FldTwoH, FldTwoW, FldThreeH, FldThreeW);

  if (FldOneW >= FldTwoW) // first field + second field
    if (FldOneH >= FldTwoH)
      S = FldOneH * FldOneW;
	else 
	  S = FldOneH * FldOneW + (FldTwoH * FldTwoW - FldOneH * FldTwoW);
  else 
	if (FldOneH < FldTwoH)
      S = FldTwoH * FldTwoW;
    else 
	  S = FldTwoH * FldTwoW + (FldOneH * FldOneW - FldTwoH * FldOneW); 

  if (FldThreeH <= min (FldTwoH, FldOneH) && FldThreeH <= min (FldTwoW, FldOneW))
  {
	n = FldThreeH;
    FldThreeH = FldOneW;
	FldThreeW = n;
  }
  else if (FldThreeH <= max (FldTwoH, FldOneH) && FldThreeH <= max (FldTwoW, FldOneW))
  {
	n = FldThreeH;
    FldThreeH = FldOneW;
	FldThreeW = n;
  }

  
  printf ("Field min area: %i \n", S);

  getch();
}
