#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void add_at_end(struct node **h, int j)
{
    struct node *a = (struct node*)malloc(sizeof(struct node));
    a->data = j;
    if((*h) == NULL){
        a->next = NULL;
        *h = a;
    }
    else
    {
        struct node *p = *h;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = a;
        a->next = NULL;
    }
}
void reverse(struct node **h)
{
    struct node *prev = NULL;
    struct node *curr = *h;
    struct node *next = NULL;
    while(curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    *h = prev;
}       
void delLesser(struct node **head)
{
    reverse(head);
    struct node *p = *head;
    struct node *q = NULL;
    struct node *r = NULL;
    int max = p->data;
    q = p;
    r = q;
    p = p->next;
    while(p != NULL)
    {
        while(p!= NULL && p->data < max)
        {
            p = p->next;  
        }
        if(p != NULL)
        {
          q->next = p;
          q = q->next;
          max = p->data;
          p = p->next;
        }
        else
        {
            q->next = NULL;
        } 
    }
    *head = r;

    reverse(head);
}
void print(struct node* h)
{
    while(h != NULL)
    {
        printf("%d", h->data); 
        h = h->next;
    }
}
int main()
{
    struct node *head = NULL;
    int size, i, j;
    scanf("%d", &size);
    for(i = 0; i < size; i++)
    {
        scanf("%d", &j);
        add_at_end(&head, j);
    }
    delLesser(&head);
    print(head);
    return 0;
}
