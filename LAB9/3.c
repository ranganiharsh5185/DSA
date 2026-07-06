#include "stdio.h"
#include "stdlib.h"
struct node
{
    int info;
    struct node *link;
};
struct node *FIRST = NULL;
void insert_at_last();
void display();
void insert_between();
void main()
{
    int c = 0;
    while (1)
    {

        printf("1.to insert node\n");
        printf("0.to exit\n");
        scanf("%d", &c);
        if (c == 1)
        {
            insert_at_last();
        }
        else
        {
            c = 0;
            break;
        }
    }
    insert_between();
    display();
}
int gcd(int a, int b)
{
    int ans = 1;
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            ans = i;
        }
    }
    return ans;
}
void insert_at_last()
{
    struct node *newnode, *save;
    newnode = (struct node *)malloc(sizeof(struct node));
    save = FIRST;
    printf("Enter the data: ");
    scanf("%d", &newnode->info);
    newnode->link = NULL;
    if (FIRST == NULL)
    {
        FIRST = newnode;
    }
    else
    {
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newnode;
    }
}
void display()
{
    struct node *save;
    save = FIRST;
    if (FIRST == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (save != NULL)
        {
            printf("%d->", save->info);
            save = save->link;
        }
        printf("\n");
    }
}
void insert_between()
{
    struct node *newnode, *save, *pred;
    pred = FIRST;
    save = pred->link;
    while (save != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->info = gcd(pred->info, save->info);
        newnode->link = save;
        pred->link = newnode;
        pred = save;
        save = save->link;
    }
}