#include "stdio.h"
#include "stdlib.h"
#define MAX 50




int S[50];
int TOP = -1;

void push(int x);
int pop();
int peek(); // display
int peep(int i);
void change(int i, int x);
void disply_Stack();

int main()
{
    int c, x, i;

    printf("\t\t\t\tWelcome To The Menu Driven Progrram Of STACK \n");

    do
    {
        printf("\nENTER - '1' : Push()\n");
        printf("ENTER - '2' : Pop()\n");
        printf("ENTER - '3' : Peek()\n");
        printf("ENTER - '4' : Peep() \n");
        printf("ENTER - '5' : Change()\n");
        printf("ENTER - '6' : display_Stack()\n");
        printf("ENTER - '0' : To Exit The Progrram\n\n");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("ENTER THE VALUE to PUSH :");
            scanf("%d", &x);
            push(x);
            break;

        case 2:
            i = pop();
            printf("Poped element = %d",i);
            break;

        case 3:
            i = peek();
            printf("Peeked element = %d",i);
            break;

        case 4:
            printf("ENTER THE value of I to peep :");
            scanf("%d", &i);
            i = peep(i);
            printf("Peeped element = %d",i);
            break;

        case 5:
            printf("ENTER THE value of I to change:");
            scanf("%d", &i);
            printf("ENTER THE VALUE to PUSH :");
            scanf("%d", &x);
            change(i, x);
            break;

        case 6:
            disply_Stack();
            break;

        case 0:
            printf("Exiting...\n");
            break;
        default:
            break;
        }
    } while (c != 0);

    return 0;
}

void push(int x)
{ // insrt element at the top of stack
    if (TOP >= MAX - 1)
    {
        printf("OVERFLOW !!!");
        return;
    }
    else
    {
        S[++TOP] = x;
        return;
    }
}

int pop()
{ // removes and returns the element at top of stack
    if (TOP <= -1)
    {
        printf("UNDERFLOW !!!");
        return -1;
    }
    else
    {
        return S[TOP--];
    }
}

int peek() // display
{          // only returns element on top
    if (TOP <= -1)
    {
        printf("UNDERFLOW !!!");
        return -1;
    }
    else
    {
        return S[TOP];
    }
}

int peep(int i)
{ // return element on i-th position
    if ((TOP - i + 1) <= -1)
    {
        printf("UNDERFLOW !!!");
        return -1;
    }
    else
    {
        return S[TOP - i + 1];
    }
}

void change(int i, int x)
{ // changes the value of element on i-th position
    if ((TOP - i + 1) <= -1)
    {
        printf("UNDERFLOW !!!");
        return;
    }
    else
    {
        S[TOP - i + 1] = x;
        return;
    }
}

void disply_Stack() {
    for(int i=0;i<=TOP;i++) {
        printf("%d\t",S[i]);
    }
    printf("\n");
}