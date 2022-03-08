/* plik modul.c nie jest potrzebny w
przypadku gdy zmienimy extern na static
w deklaracji stałych pi  i e 
stałe zostały po prostu przeniesione do maina */

#include <stdio.h>

static const double PI = 3.141593;
static const double E  = 2.718282;


int main()
{
  printf("  PI: %lf\n",PI);
  printf("   E: %lf\n",E);
  return 0;
}
