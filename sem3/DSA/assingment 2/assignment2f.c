#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    char data;
    struct stack *next;
} *top = NULL;
void push(char x)
{
    if (top == NULL)
    {
        top = (struct stack *)malloc(sizeof(struct stack));
        top->data = x;
        top->next = NULL;
    }
    else
    {
        struct stack *p = (struct stack *)malloc(sizeof(struct stack));
        p->data = x;
        p->next = top;
        top = p;
    }
}
char pop()
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        struct stack *p = top;
        char x = p->data;
        top = top->next;
        free(p);
        return x;
    }
}
void operation(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            push(s[i]);
        }
        else
        {
            printf("%c", pop());
        }
    }
}
int main()
{
    char s[100];
    printf("Enter the Expresion:");
    gets(s);
    operation(s);

    return 0;
}