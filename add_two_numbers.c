#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void add_at_begin(struct node** h, int j)
{
    struct node *a = (struct node*)malloc(sizeof(struct node));
    a->data = j;
    if((*h) == NULL)
        a->next = NULL;
    else
        a->next = *h;
    *h = a;
}
struct node* add(struct node *h1, struct node *h2)
{
    int carry = 0, i;
    struct node *c = NULL;
    while(h1 != NULL && h2 != NULL)
    {
        i = (h1->data) + (h2->data) + carry;
        add_at_begin(&c, (i % 10));
        carry = i / 10;
        h1 = h1->next;
        h2 = h2->next;
    }
    if(h1 != NULL && h2 == NULL)
    {
        while(h1 != NULL)
        {
            i = h1->data + carry;
            add_at_begin(&c, (i % 10));
            carry = i / 10;
            h1 = h1->next;
        }
    }
    else if(h2 != NULL && h1 == NULL)
    {
        while(h2 != NULL)
        {
            i = h2->data + carry;
            add_at_begin(&c, (i % 10));
            carry = i / 10;
            h2 = h2->next;
        }
    }
    if(carry != 0)
        add_at_begin(&c, carry);
    return c;
}
void print(struct node *h)
{
    while(h != NULL)
    {
        printf("%d",h->data);
        h = h->next;
    }
}
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int l1,l2,i,j;
    scanf("%d %d",&l1, &l2);
    for(i = 0; i < l1; i++)
    {
        scanf("%d", &j);
        add_at_begin(&head1, j);
    }
    for(i = 0; i < l2; i++)
    {
        scanf("%d", &j);
        add_at_begin(&head2, j);
    }
    head1 = add(head1, head2);
    print(head1);
    return 0;
}
