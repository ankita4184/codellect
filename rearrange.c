#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}n;
void add_at_end(n** h, int j)
{
    n* a = (n*)malloc(sizeof(n));
    a->data = j;
    a->next = NULL;
    if((*h) == NULL)
        *h = a;
    else
    {
        n* p = *h;
        while(p->next != NULL)
            p = p->next;
        p->next = a;
    }
}
void rearr(n* h)
{
    n* p = h;
    while(p != NULL && p->next != NULL)
    {
        n* q = p, *w = NULL, *t = NULL;
        while(q->next != NULL)
        {
            w = q;
            q = q->next;
        }
        w->next = NULL;
        t = p->next;
        p->next = q;
        q->next = t;
        p = t;
    }
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
    int size, j;
    scanf("%d", &size);
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &j);
        add_at_end(&head, j);
    }
    rearr(head);
    print(head);
    return 0;
}
