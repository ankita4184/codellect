#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int top;
    int arr[30];
}stack;
stack s;
void push(int a)
{
    s.arr[++s.top] = a;
    printf("  %d\n", a);
}
int pop()
{
    return s.arr[s.top--];
}
void push1(char d)
{
    int a = ((int)d) % 48;
    if(d != '+' && d!= '-' && d!= '*' && d != '/')
        {
            push(a); return;
        }
    switch(d)
    {
        case '+':
            push((pop() + pop()));
            break;
        case '-':
            push((pop() - pop()));
            break;
        case '*':
            push((pop() * pop()));
            break;
        case '/':
            push((pop() / pop()));
            break;
    }
}
int main()
{
    s.top = -1;
    char d;
    int i = 0;
    while( i < 7)
    {
        scanf(" %c", &d);
        push1(d);
        i++;
    }
    printf("%d", pop());
    return 0;
}
