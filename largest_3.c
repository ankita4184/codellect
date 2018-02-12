#include<stdio.h>
#include<stdlib.h>
int cmp(const void* e1, const void* e2)
{
    int f = *((int*)e1);
    int s = *((int*)e2);
    return f - s;
}
void largestMultiple(int *arr, int size)
{
    qsort(arr, size, 4, cmp);
    int i = size - 1, sum = 0, j = 0, k;
    int *p = (int*)malloc(size * sizeof(int));
    while(i >= 0)
    {
       if(arr[i] % 3 == 0)
            printf("%d", arr[i]);
        else
        {
            sum = sum + arr[i];
            p[j] = arr[i]; j++;
            if(sum % 3 == 0)
            {
               for(k = 0; k < j; k++)
                    printf("%d", p[k]);
               j = 0;
               sum = 0;
            }
        }
        i--;
    }
}
int main()
{
    int size, i = 0;
    scanf("%d", &size);
    int *arr = (int*)malloc(size * sizeof(int));
    while(i < size)
    {
        scanf("%d",&arr[i]);
        i++;
    }
    largestMultiple(arr, size);
    return 0;
}
