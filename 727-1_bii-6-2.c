#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 
void shell(int n, int a[])
{
    int i, j, step, tmp, exchange, compare;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = a[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp > a[j - step])
                {
                    a[j] = a[j - step];
                    exchange = exchange + 1;
                    compare = compare + 1;
                }
                else
                {
                  compare = compare + 1;
                    break;
                }
            }
            a[j] = tmp;
        }
}
 
int main()
{
    int n;
    scanf("%d",&n);
    int *a = (int *) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    shell(n, a);
    for(int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if(i < n - 1)
        printf(" ");
    }
    free(a);
    printf("\n");
    return 0;
}
