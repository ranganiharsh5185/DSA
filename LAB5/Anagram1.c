#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void sorting(char a[], int n);
int isAnagram(char a[], char b[]);
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
    printf("Enter anagram of word : %s\n", a[index]);
    char b[20];
    scanf("%s", b);
    int check = isAnagram(a[index], b);
    if (check == 1)
    {
        printf("Anagram");
    }
    else
    {
        printf("not Anagram");
    }
}
void sorting(char a[], int n)
{
    char min;
    int tempIndex = 0;
    char temp;
    for (int i = 0; i < n; i++)
    {
        min = a[i];
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                a[j] = a[i];
                a[i] = min;
            }
        }
    }
}

int isAnagram(char a[], char b[])
{
    sorting(a, strlen(a));
    sorting(b, strlen(b));
    if (strcmp(a, b) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}