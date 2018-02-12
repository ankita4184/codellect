#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}n;
void add_at_end(n** head, int k)
{
    n* a = (n*)malloc(sizeof(n));
    a->data = k;
    if((*head) == NULL)
    {
        a->next = NULL;
        *head = a;
    }
    else
    {
        n* p = *head;
        while(p->next != NULL)
            p = p->next;
        a->next = NULL;
        p->next = a;
    }
}
void rotate(n** h, int k)
{
    n* p = *h, *r = *h;
    int i;
    n* q = NULL;
    for(i = 0; i < k; i++)
    {
        q = p;
        p = p->next;
    }
    *h = p;
    q->next = NULL;
    while(p->next != NULL)
        p = p->next;
    p->next = r;
}
void print(n* h)
{
    while(h != NULL)
    {
        printf("%d", h->data);
        h = h->next;
    }
}
int main()
{
    n* head = NULL;
    int i, size, k;
    scanf("%d", &size);
    for(i = 0; i < size; i++)
    {
        scanf("%d", &k);
        add_at_end(&head, k);
    }
    scanf("%d", &k);
    rotate(&head, k);
    print(head);
    return 0;
}
