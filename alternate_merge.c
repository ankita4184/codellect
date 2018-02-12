#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
void add(struct node **head, int q)
{
    struct node *a = (struct node*)malloc(sizeof(struct node));
    if(*head == NULL)
    {
        a->data = q;
        a->next = NULL;
        *head = a;
    }
    else
    {
        struct node *p = *head;
        while(p->next != NULL)
        {
            p = p -> next;
        }
        a->data = q;
        a->next = NULL;
        p->next = a;
    }
}
struct node* merge(struct node *head1, struct node *head2)
{
    struct node *c = head1;
    struct node *d = NULL;
    struct node *e = NULL;
    while(head1 != NULL && head2 != NULL)
    {
        d = head1->next;
        e = head2->next;
        head1->next = head2;
        head2->next = d;
        head1 = d;
        head2 = e;
    }
    return c;
}
void print(struct node *h)
{
    while(h!= NULL)
    {
        printf("%d",h->data);
        h = h -> next;
    }
} 
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int i,j;
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &j);
        add(&head1, j);
    }
    printf("List 2");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &j);
        add(&head2, j);
    }
    printf("End");
     head1 = merge(head1, head2);
    print(head1);
}
