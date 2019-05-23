#include <stdio.h>

int main()
{
int n, x, tmp = 1;
scanf("%d", &n);
for(int i = 1; i <= n; i++)
{
scanf("%d", &x);
tmp *=(x-i);
}
printf("%d", tmp);
return 0;
}
