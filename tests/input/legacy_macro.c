//Don't include stdio.h and print nice message since stdio.h confuses C backend.
//#include <stdio.h>

int one() 
{ 
  return 1; 
}
int two() 
{
  return 2; 
}
int three() 
{
  return 3; 
}
int four() 
{
  return 4; 
}
int sixth() 
{
  return 6; 
}
int seventh(int a, int b) 
{
  return (a + b); 
}

#define A -1
#define B -2
#define D -3
#define F -4
#include "legacy_macro.h"
#define H -6
#define I(a, b) -(a + b)

int main()
{
  //printf ("First advice: %d\nSecond advice: %d\nThird advice: %d\nFourth advice: %d\nFifth advice: %d\nSixth advice: %d\nSeventh advice: %d\n", A, B, D, F, G, H, I(3, 4));
  return 0;
}
