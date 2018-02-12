#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int top;
    char arr[50];
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
void print()
{
    while(s.top != -1)
    {
        printf(" %c", pop());
    }
}
void convert(char *p)
{
    int i = 0, j, k;
    char q[50], d;
    while(p[i] != '\0')
    {
        if(p[i] == '(')
            i = bracket(p, i);
        else if(p[i] == '^' || p[i] == '*' || p[i] == '/' || p[i] == '+' || p[i] == '-')
        {
            if(p[i+1] == '(')
                i = bracket(p,i);
            else
            {
                push(p[i+1]);
                push(p[i]);
                i++;
            }
        }
        else
            push(p[i]);    
        i++;
    }
    print();
}
int bracket(char *p, int i)
{
    int k, j;
    char q[50];
     k = 0;
     for(j = i+1; p[j] != ')'; j++,k++)
        q[k] = p[j];
     q[k] = '\0';
     convert(q);
     return j+1;
}

int main()
{
    s.top = -1;
    char p[50];
    scanf("%s", p);
    convert(p);
    return 0;
}
