#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char s[50];
int TOP = -1;
void push(char x);
char pop();
int main()
{
    char str[50];
    int i = 0, b = 0;
    printf("enter the string:");
    scanf("%s", str);
    while (str[i] != '\0')
    {
        if (str[i] == '*')
        {
            pop();
        }
        else
        {
            push(str[i]);
        }

        i++;
    }
    for (int i = 0; i <= TOP; i++)
    {
        printf("%c", s[i]);
    }
}

void push(char x)
{
    if (TOP >= 49)
    {
        printf("OVERFLOW !!!");
        return;
    }
    else
    {
        s[++TOP] = x;
    }
}

char pop()
{

    if (TOP <= -1)
    {
        printf("UNDERFLOW !!!");
        return -1;
    }
    else
    {
        return s[TOP--];
    }
}