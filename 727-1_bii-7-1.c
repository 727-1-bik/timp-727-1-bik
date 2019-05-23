#include<stdio.h>
#include<malloc.h>

void qsort(int *arr, int begin, int end)
{
    int left = begin, right = end, base;
    base = arr[(left + right)/2];
    do
    {
        while(arr[left] < base) left++;
        while(arr[right] > base) right--;
        if(left <= right)
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    } while(left <= right);
    if ( begin < right )
        qsort(arr, begin, right);
    if ( end > left )
        qsort(arr, left, end);
}
void sorting_function(int *arr, int arr_len)
{
    qsort(arr, 0, arr_len-1);
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

