#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int top;
    int *arr;
}stack;
stack s;
void push(int a)
{
    s.arr[++s.top] = a;
}
int pop()
{
    return s.arr[s.top];
}
int area(int n, int a[n])
{
    s.arr = (int*)malloc(n * sizeof(int));
    int i = 0;
    int l = 0, b = 0, area = a[i], c;
    push(a[i]);
    for(i = 1; i < n; i++)
    {
        if(a[i] < pop() && a[i] > l)
        {
            l = a[i]; b = 2;
        }
        else if(a[i] >= pop())
            b++;
        else
        {
            l = 0; b = 0;
        }
        if((l *b) > area)
            area = l * b;
        push(a[i]);
    }
    return area;
}
int main()
{
    s.top = -1;
    int n,i;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d", area(n, a));
    return 0;
}
