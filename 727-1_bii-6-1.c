
#include<stdio.h>
#include<malloc.h>

int sorting_function(int *arr, int arr_len)
{
    int step, count, tmp;
    step = arr_len/1.247;
    while(step >= 1)
    {
        for (int i = 0; i + step < arr_len; ++i)
                        {
                                if (arr[i] > arr[i + step])
                                {
                                        tmp=arr[i];
                                    arr[i]=arr[i+step];
                                arr[i+step]=tmp;
                                        count++;
                                }
                        }
                step /= 1.247;
    }
    for (int i = 0; i < arr_len - 1; i++)
                {
                        int s = 0;
                        for (int j = 0; j < arr_len - i - 1; j++)
                        {
                                if (arr[j] > arr[j + 1]) {
                                        tmp=arr[i];
                                    arr[i]=arr[i+step];
                                arr[i+step]=tmp;
                                        s = 1;
                                        count++;
                                }
                        }
                        if (s = 0)
                                break;
                }
                return count;
}

int main() {
    int arr_len;
    scanf("%d",&arr_len);
    int *arr = (int*)malloc(sizeof(int) * arr_len);
    for(int i = 0; i < arr_len; i++)
    {
        scanf("%d",&arr[i]);
    }
sorting_function(arr, arr_len);
    for(int i = 0; i < arr_len; i++)
    {
        printf("%d", arr[i]);
        if(i<arr_len-1)
        printf(" ");
    }
    free(arr);
    printf("\n");
}

