#include <stdio.h>

int main()
{
int n, x, tmp = 0;
scanf("%d", &n);
for(int i = 0; i < n; i++)
{
scanf("%d", &x);
tmp +=x;
}
printf("%d", -1*tmp);
return 0;
}
