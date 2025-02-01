#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
int count()
{
    int i = 0;
    struct Node *p = head;
    while (p != NULL)
    {
        i = i + 1;
        p = p->next;
    }
    return i;
}
void delete_middle(int count)
{
    int mid;
    if (head == NULL)
    {
        printf("Linked List is empty\n");
    }
    else if (head->next == NULL)
    {
        struct Node *p = head;
        head = NULL;
        printf("%d is deleted and the list is empty\n", p->data);
        free(p);
    }
    else
    {
        mid = (count / 2);
        struct Node *p = head->next;
        struct Node *q = head;
        for (int i = 1; i < mid; i++)
        {
            p = p->next;
            q = q->next;
        }
        q->next = p->next;
        printf("%d is deleted from LL\n", p->data);
        free(p);
    }
}
void create(int arr[], int n)
{
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        last->next = t;
        t->next = NULL;
        last = t;
    }
}
void display()
{
    struct Node *p = head;
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
int main()
{
    int n;
    printf("Enter lenght of Linked List:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element:");
        scanf("%d", &arr[i]);
    }
    create(arr, n);
    display();
    int length = count();
    printf("%d\n", length);
    delete_middle(length);
    display();
    return 0;
}