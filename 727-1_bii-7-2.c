
#include <stdio.h>
#include <stdlib.h>

void sift(int *arr, int root, int bottom)
{
  int maxChild, done = 0;
  while((root * 2 + 1 <= bottom) && (!done))
  {
    if(root * 2 + 2 <= bottom)
    {
        if(arr[root * 2 + 2] > arr[root * 2 + 1])
            maxChild = root * 2 + 2;
        else
            maxChild = root * 2 + 1;
    }
    else
        maxChild = root * 2 + 1;
    if(arr[root] < arr[maxChild])
    {
      int temp = arr[root];
      arr[root] = arr[maxChild];
      arr[maxChild] = temp;
      root = maxChild;
    }
    else
      done = 1;
  }
}

void sorting_function(int *arr, int arr_len)
{
  for (int i = (arr_len / 2) - 1; i >= 0; i--)
    sift(arr, i, arr_len - 1);
  for (int i = arr_len - 1; i >= 1; i--)
  {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    sift(arr, 0, i - 1);
  }
}

int main()
{
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

