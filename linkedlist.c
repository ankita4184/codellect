#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}list;
void print(list* head)
{
    while(head != NULL)
    {
        printf(" %d ",head->data);
        head = head->next;
    }
    printf("\n");
}
list* push_end(list* head, int data)
{
    list* a = (list*)malloc(sizeof(list));
    a->data = data;
    a->next = NULL;
    if(head == NULL){
        head = a;
    }
    else{
        list* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = a;
    }
    return head;
}
list* push_front(list* head, int data)
{
    list* a = (list*)malloc(sizeof(list));
    a->data = data;
    if(head == NULL){
        a->next = NULL;
        head = a;
    }
    else{
        a->next = head;
        head = a;
    }
    return head;
}
list* push_at(list* head, int data, int pos)
{
    if(pos == 0)
        head = push_front(head, data);
    else{
        int i = 0;
        list* temp = head;
        while(i < pos-1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if(temp != NULL)
        {
            list* a = (list*)malloc(sizeof(list));
            a->data = data;
            a->next = temp->next;
            temp->next = a;
        }
    }
    return head;
}
list* reverse(list *head)
{
    list* prev = NULL;
    list* curr = head;
    list* next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
list* recursive(list* head)
{
    list* first = head;
    list* second = NULL;
    if(first != NULL)
        second = first->next;
    if(second == NULL)
        return first;
    list* temp = recursive(first->next);
    first->next = NULL;
    second->next = first;
    return temp;
}
list* reversepair(list* head)
{
    list* prev = head;
    list** curr = &head;
    list* next = NULL;
    if(prev != NULL)
          next = prev->next;
    while(next->next != NULL )
    {
        prev->next = next->next;
        next->next = prev;
        *curr = next;
        curr = &(prev->next);
        prev = prev->next;
        next = prev->next;
    }
    return head;
}   
list* delete_front(list* head)
{
    list* a = head;
    head = head->next;
    free(a);
    return head;
}
list* delete_end(list* head)
{
    list* a = head;
    list* b = NULL; 
    while(a->next != NULL)
    {
        b = a;
        a = a->next;
    }
    b->next = NULL;
    return head;
}
list* delete_at(list* head, int pos)
{
    if(pos == 0)
        delete_front(head);
    else{
        list* a = head;
        list* b = NULL;
        int i = 0;
        while(i < pos - 1 && a != NULL){
            b = a;
            a = a->next;
            i++;
        }
        if(a != NULL)
            b->next = a->next;
    }
    return head;
}
list* reversing(list* head)
{
    list* curr = head;
    if(curr->next == NULL)
        return curr;
    list* temp = curr->next;
    curr->next = temp->next;
    list* temp1 = reversing(curr->next);
    temp1->next = temp;
    temp->next = NULL;
    return temp;
}
int main()
{
    list* head = NULL;
    head = push_end(head, 3);
    head = push_front(head, 5);
    //head = push_end(head, 1);
    head = push_at(head, 2, 1);
    head = push_at(head, 6, 4);
    head = push_at(head, 8, 3);
    print(head);
    head = reverse(head);
    print(head);
    head = recursive(head);
    print(head);
    //head = reversepair(head);
   // print(head);
    list* temp = reversing(head);
    print(head);
    head = delete_front(head);
    head = delete_end(head);
    head = delete_at(head, 3);
    print(head);
    return 0;
}
