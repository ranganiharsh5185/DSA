#include <stdio.h>
#include <string.h>

#define MAX 50

struct STACK
{
    char S[MAX];
    int TOP;
};

struct STACKint
{
    int S[MAX];
    int TOP;
};

int G(char c);
int F(char c);
int R(char c);

void push(struct STACK *stack, char x);
char pop(struct STACK *stack);

void pushint(struct STACKint *eval, int m);
int popint(struct STACKint *eval);

int evaluation(struct STACKint *eval, char polish[]);

int main()
{
    struct STACK stack;
    struct STACKint eval;

    stack.TOP = -1;
    push(&stack, '(');

    char infix[50], polish[50], next;
    int rank = 0, i = 0, p = 0;

    printf("Enter An Infix Expression : ");
    scanf("%s", infix);

    int len = strlen(infix);
    infix[len] = ')';
    infix[len + 1] = '\0';

    polish[0] = '\0';

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
            push(&stack, next);
        else
            pop(&stack);

        next = infix[++i];
    }

    if (stack.TOP != -1 || rank != 1)
    {
        printf("Invalid Infix Expression !!!");
        return 0;
    }

    printf("\nPOSTFIX EXPRESSION : %s", polish);

    printf("\nResult : %d", evaluation(&eval, polish));

    return 0;
}

int G(char c)
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
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
        return 6;
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
        printf("OVERFLOW");
        return;
    }

    stack->S[++stack->TOP] = x;
}

char pop(struct STACK *stack)
{
    if (stack->TOP < 0)
    {
        printf("UNDERFLOW");
        return '\0';
    }

    return stack->S[stack->TOP--];
}

void pushint(struct STACKint *eval, int m)
{
    if (eval->TOP >= MAX - 1)
    {
        printf("OVERFLOW");
        return;
    }

    eval->S[++eval->TOP] = m;
}

int popint(struct STACKint *eval)
{
    if (eval->TOP < 0)
    {
        printf("UNDERFLOW");
        return 0;
    }

    return eval->S[eval->TOP--];
}

int evaluation(struct STACKint *eval, char polish[])
{
    eval->TOP = -1;

    int i = 0;

    while (polish[i] != '\0')
    {
        if (polish[i] >= '0' && polish[i] <= '9')
        {
            pushint(eval, polish[i] - '0');
        }
        else
        {
            int op2 = popint(eval);
            int op1 = popint(eval);

            switch (polish[i])
            {
            case '+':
                pushint(eval, op1 + op2);
                break;

            case '-':
                pushint(eval, op1 - op2);
                break;

            case '*':
                pushint(eval, op1 * op2);
                break;

            case '/':
                pushint(eval, op1 / op2);
                break;
            }
        }

        i++;
    }

    return popint(eval);
}
