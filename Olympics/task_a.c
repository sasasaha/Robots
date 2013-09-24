#include <stdio.h>
#include <conio.h>
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
  int SumFldOTW, SumFldTTW;

  if ((F = fopen ("Olympics.txt", "rb")) == NULL)
	printf ("Error with reading file");

  fscanf (F, "%i%i%i%i%i%i", &FldOneH, &FldOneW, &FldTwoH, &FldTwoW, &FldThreeH, &FldThreeW);
  printf ("1st: FldOneH: %i, FldOneW: %i, FldTwoH: %i, FldTwoW: %i, FldThreeH: %i, FldThreeW: %i \n", FldOneH, FldOneW, FldTwoH, FldTwoW, FldThreeH, FldThreeW);

  //positioning
  if (FldOneH < FldOneW) 
    swap (&FldOneH, &FldOneW);
  if (FldTwoH < FldTwoW)
    swap (&FldTwoH, &FldTwoW);
  if (FldThreeH < FldThreeW)
    swap (&FldThreeH, &FldThreeW);

  printf ("2nd: FldOneH: %i, FldOneW: %i, FldTwoH: %i, FldTwoW: %i, FldThreeH: %i, FldThreeW: %i \n", FldOneH, FldOneW, FldTwoH, FldTwoW, FldThreeH, FldThreeW);

  //first has the biggest height, third - the smallest
  if (FldOneH < FldTwoH)
  {
    swap (&FldOneH, &FldTwoH);
	swap (&FldOneW, &FldTwoW);
  }
  if (FldOneH < FldThreeH)
  {
    swap (&FldOneH, &FldThreeH);
	swap (&FldOneW, &FldThreeW);
  }
  if (FldThreeH > FldTwoH)
  {
    swap (&FldThreeH, &FldTwoH);
	swap (&FldThreeW, &FldTwoW);
  }

  printf ("3rd: FldOneH: %i, FldOneW: %i, FldTwoH: %i, FldTwoW: %i, FldThreeH: %i, FldThreeW: %i \n\n", FldOneH, FldOneW, FldTwoH, FldTwoW, FldThreeH, FldThreeW);

  if ((FldTwoW - FldOneW) < 0)
    SumFldOTW = 0;
  else
	SumFldOTW = FldTwoW - FldOneW;

  if ((FldThreeW - FldTwoW) < 0)
	SumFldTTW = 0;
  else
	SumFldTTW = FldThreeW - FldTwoW;


  S = FldOneH * FldOneW + FldTwoH * SumFldOTW + FldThreeH * SumFldTTW;

  
  printf ("Field min area: %i \n", S);

  getch();
}
