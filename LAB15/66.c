#include <stdio.h>
#include <string.h>

#define MAX 50

struct STACK
{
    char S[MAX];
    int TOP;
};

int G(char c);
int F(char c);
int R(char c);
void push(struct STACK *stack, char x);
char pop(struct STACK *stack);
void change_bracket(char *s);
void reverse(char *s);

int main()
{
    struct STACK stack;
    stack.TOP = 0;
    stack.S[0] = '(';

    char infix[50], polish[50], next;
    int rank = 0, i = 0, p = 0;

    printf("Enter An Infix Expression : ");
    scanf("%s", infix);

    reverse(infix);
    change_bracket(infix);

    int len = strlen(infix);
    infix[len] = ')';
    infix[len + 1] = '\0';

    next = infix[0];

    while (next != '\0')
    {
        if (stack.TOP < 0)
        {
            printf("Invalid Infix Expression !!!");
            return 0;
        }

        while (G(stack.S[stack.TOP]) > F(next))
        {
            polish[p++] = pop(&stack);
            polish[p] = '\0';

            rank += R(polish[p - 1]);

            if (rank < 1)
            {
                printf("Invalid Infix Expression !!!");
                return 0;
            }
        }

        if (G(stack.S[stack.TOP]) != F(next))
        {
            push(&stack, next);
        }
        else
        {
            pop(&stack);
        }

        next = infix[++i];
    }

    if (stack.TOP != -1 || rank != 1)
    {
        printf("Invalid Infix Expression !!!");
        return 0;
    }

    reverse(polish);

    printf("POLISH EXPRESSION : %s\n", polish);

    return 0;
}

int G(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 3;

    case '^':
        return 6;

    case '(':
        return 0;

    default:
        return 8;
    }
}

int F(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;

    case '*':
    case '/':
        return 4;

    case '^':
        return 5;

    case '(':
        return 9;

    case ')':
        return 0;

    default:
        return 7;
    }
}

int R(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return -1;

    default:
        return 1;
    }
}

void push(struct STACK *stack, char x)
{
    if (stack->TOP >= MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack->S[++stack->TOP] = x;
}

char pop(struct STACK *stack)
{
    if (stack->TOP < 0)
    {
        printf("Stack Underflow\n");
        return '\0';
    }

    return stack->S[stack->TOP--];
}

void change_bracket(char *s)
{
    while (*s != '\0')
    {
        if (*s == '(')
            *s = ')';
        else if (*s == ')')
            *s = '(';

        s++;
    }
}

void reverse(char *s)
{
    int i = 0;
    int j = strlen(s) - 1;

    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}