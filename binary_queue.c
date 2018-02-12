#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}que;
que* t;
que* first = NULL; //delete from here
que* end = NULL; // add here
int pop()
{
    return first->data;
}
void push(int i)
{
    que* a = (que*)malloc(sizeof(que));
    a->data = i;
    a->next = NULL;
    if(first == NULL && end == NULL)
    {
        first = a;
        end = a;
        t = first;
    }
    else
    {
        end -> next = a;
        end = a;
    }
}
void create(int i)
{
    int a = pop();
    int b;
    if(i % 2 != 0)
    {
        b = (a * 10) + 0;
        push(b);
    }
    if(i % 2 == 0)
    {
        b = (a * 10) + 1;
        push(b);
        first = first->next;
    }
  
}     
void print()
{
    que* temp = t;
    while(temp != end)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}
int main()
{
    int n, i;
    scanf("%d", &n);
    push(1);
    for(i = 1; i < n; i++)
    {
        create(i);
    }
    print();
    return 0;
}
