#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}list;
list* front = NULL, *end = NULL; //front par add, end par delete
void print()
{
    list *temp = front;
    while(temp != end)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}
void push(int i)
{
    list *n = (list*)malloc(sizeof(list));
    n->data = i;
    n->next = NULL;
    if(front == NULL && end == NULL) //list is empty
    {
        front = n;
        end = n;
    }
    else
    {
        end->next = n;
        end = end->next;
    }
    print();
}
void pop()
{
    list *temp = front;
    front = front->next;
    free(temp);
    print();
}
int main()
{
    push(1);
    push(2);
    pop();
    push(3);
    print();
    return 0;
}
