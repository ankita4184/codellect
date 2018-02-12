#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct node{
    int frequency;
    char *str;
    struct node* left;
    struct node* right;
}tree;
int f = 0;
char *p;
tree* add(tree* head, char arr[], int len)
{
    if(strlen(arr) >= len)
    {
        tree* n = (tree*)malloc(sizeof(tree));
        n->str = (char*)malloc(strlen(arr));
        if(head == NULL)
        {
            n->frequency = 1;
            n->left = NULL;
            n->right = NULL;
            return n;
        }
        else if(strcmp(head->str, arr) == 0)
        {
            head->frequency++;
            if(head->frequency > f)
            {
                f = head->frequency;
                p = (char*)malloc(strlen(arr));
                strcpy(p, arr);
            }
        }
        else if(strcmp(head->str, arr) > 0)
        {
            head->right = add(head->right, arr, len);
        }
        else if(strcmp(head->str, arr) < 0)
        {
            head->left = add(head->left, arr, len);
        }
    }
    return head;
}
int main()
{
    tree* head = NULL;
    int line, max;
    scanf("%d %d", &line, &max);
    char arr[line][line];
    for(int i = 0; i < line; i++)
    {
        //arr[i] = (char*)malloc(51200 * sizeof(char));
        scanf("%s",arr[i]);
        head = add(head, arr[i], max);
    }
    printf("%d %s", f, p);
    return 0;
}
