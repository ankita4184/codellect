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
    if((*h) == NULL){
        a->next = NULL;
        *h = a;
    }
    else{
        n* p = *h;
        while(p->next != NULL){
            p = p->next;
        }
        a->next = NULL;
        p->next = a;
    }
}
n* findele(n* h1, n* h2)
{
    n* a = NULL;
    while(h1 != NULL && h2 != NULL)
    {
        if(h1->data == h2->data)
        {
            add_at_end(&a, h1->data);
            h1 = h1->next;
            h2 = h2->next;
        }
        else
        {
            while(h2 != NULL && h1->data >= h2->data)
            {
                if(h1->data == h2->data)
                    add_at_end(&a, h1->data);
                h2 = h2->next;
            }
            while(h1 != NULL && h1->data <= h2->data)
            {
                if(h1->data == h2->data)
                    add_at_end(&a, h1->data);
                h1 = h1->next;
            }
        }
    }   
    return a;
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
    n* head1 = NULL;
    n* head2 = NULL;
    int i, s1, s2, j;
    scanf("%d %d", &s1, &s2);
    for(i = 0; i < s1; i++){
        scanf("%d", &j);
        add_at_end(&head1, j);
    }
    for(i = 0; i < s2; i++){
        scanf("%d", &j);
        add_at_end(&head2, j);
    }
    n* a = findele(head1, head2);
    print(a);
    return 0;
}
