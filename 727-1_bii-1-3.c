#include <stdio.h>
#include <math.h> 

int main ()
{
  double a, b;
  scanf ("%lf%lf", &a, &b);
  if(a <= 2147483647 && a >= -2147483647 && b <= 2147483647 && b >= -2147483647)
  {
    printf ("%.20Lf\n", powl (a, b));
  }
  return 0;
}
