#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int top;
    char arr[100];
}stack;
stack s;
void push(char a)
{
    s.arr[++s.top] = a;
}
char pop()
{
    return s.arr[s.top--];
}
int main()
{
    s.top = -1;
    char s1[100];
    scanf("%s",s1);
    int i = 0;
    while(s1[i] != 'c')
    {
        push(s1[i]);
        i++;
    }
    i++;
    while(s1[i] != '\0' && s1[i] == pop())
    {
        i++;
    }
    if(s1[i] == '\0')
        printf("true");
    else 
        printf("false");
    return 0;
}
