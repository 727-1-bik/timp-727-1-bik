#include <stdio.h>

int main ()
{
  int a, b;
  int r = scanf ("%d%d", &a, &b);
  if(a <= 2147483647 && a >= -2147483647 && b <= 2147483647 && b >= -2147483647)
  {
    printf ("%d\n", a + b);
  }
  return 0;
}
