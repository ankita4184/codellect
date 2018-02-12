#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* Insert(struct node* head, int d)
{
    struct node* a = (struct node*)malloc(sizeof(struct node));
    a->data = d;
    if(head == NULL)
    {
        head = a;
        a->next = NULL;
    }
    else
    {
        struct node *temp = head;
        head = a;
        a->next = temp;
    }
    return head;
}
void print_forward(struct node* head)
{
    if(head ==  NULL)
        return;
    print_forward(head->next);
    printf(" %d ",head->data);
}
void print_backward(struct node* head)
{
    if(head == NULL)
        return;
    printf(" %d ", head->data);
    print_backward(head->next);
}
int main()
{
    struct node* head = NULL;
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,8);
    print_forward(head);
    printf("\n");
    print_backward(head);
    return 0;
}
