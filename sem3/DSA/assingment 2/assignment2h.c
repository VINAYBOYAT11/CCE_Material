#include <stdio.h>
#include <stdlib.h>
struct queue
{
    char request;
    int priority;
    int pages;
    struct queue *next;
} *front = NULL, *rear = NULL;

void enqueue()
{
    char r;
    int a, b;
    printf("Enter Request:");
    scanf("%s", &r);
    printf("Enter Priority:");
    scanf("%d", &a);
    printf("Enter Pages:");
    scanf("%d", &b);
    printf("\n");
    if (front == NULL)
    {
        front = (struct queue *)malloc(sizeof(struct queue));
        front->request = r;
        front->priority = a;
        front->pages = b;
        front->next = NULL;
        rear = front;
    }
    else
    {
        struct queue *p = (struct queue *)malloc(sizeof(struct queue));
        p->request = r;
        p->priority = a;
        p->pages = b;
        p->next = NULL;
        rear->next = p;
        rear = p;
    }
}
void sorting()
{
    struct queue *p = front;
    while (p != rear)
    {
        struct queue *q = p->next;
        while (q != NULL)
        {
            if (q->priority < p->priority)
            {
                int a = p->priority, b = p->pages;
                p->priority = q->priority;
                p->pages = q->pages;
                q->priority = a;
                q->pages = b;
                char x = p->request;
                p->request = q->request;
                q->request = x;
            }
            q = q->next;
        }
        p = p->next;
    }
}
void display()
{
    struct queue *p = front;
    while (p != rear)
    {
        printf("Request: %c\tPriority: %d\tPages: %d\n", p->request, p->priority, p->pages);
        p = p->next;
    }
    printf("Request: %c\tPriority: %d\tPages: %d\n", p->request, p->priority, p->pages);
}
void calculate_time()
{
    struct queue *p = front;
    int t1 = 0, t2 = 0;
    while (p != NULL)
    {
        t2 = t1 + p->pages;
        printf("Request: %c is printed at time %d and takes %d seconds to print\n", p->request, t1, p->pages);
        t1 = t2;
        p = p->next;
    }
}

int main()
{
    int n;
    printf("Enter no of requests:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        enqueue();
    }
    display();
    sorting();
    printf("Queue with highest priority\n");
    display();
    calculate_time();
    return 0;
}