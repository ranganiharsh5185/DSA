#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main()
{
    int n;
    printf("Enter no of words : ");
    scanf("%d", &n);
    char a[n][20];
    for (int i = 0; i < n; i++)
    {
        printf("Enter word no.%d : ", i + 1);
        scanf("%s", a[i]);
    }
    srand(time(NULL));
    int index = rand() % n;
    printf("Enter anagram of word %s\n", a[index]);
    char b[20];
    scanf("%s", b);
    char ch;
    int count = 0, scount = 0, mcount = 0;
    for (int i = 0; i < strlen(a[index]); i++)
    {
        ch = a[index][i];
        for (int j = 0; j < strlen(a[index]); j++)
        {
            if (ch == a[index][j])
            {
                count++;
            }
        }
        for (int j = 0; j < strlen(b); j++)
        {
            if (ch == b[j])
            {
                scount++;
            }
        }
        if (count != scount)
        {
            printf("Not Anagram.");
            break;
        }
        else
        {
            count = 0;
            scount = 0;
            mcount++;
        }
    }
    if (mcount == strlen(b))
    {
        printf("Anagram.");
    }
}
