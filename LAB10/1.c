#include "stdio.h"
#include "stdlib.h"
struct node
{
    int info;
    struct node *link;
};
struct node *FIRST = NULL;
void insert_at_last();
void sort();
void display();
void main()
{
    int c = 0;
    do
    {
        printf("1.to insert node\n");
        printf("0.to exit\n");
        scanf("%d", &c);
        if (c == 1)
        {
            insert_at_last();
        }

    } while (c != 0);
     sort();
     display();
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
void sort()
{
    struct node *save, *temp;

    save = FIRST;
    temp = save->link;
    while (save->link != NULL)
    {
        while (temp != NULL)
        {
            if (save->info > temp->info)
            {
                int t = save->info;
                save->info = temp->info;
                temp->info = t;
            }
            temp = temp->link;
        }
        save = save->link;
        temp=save->link;
    }
}
void display()
{
    struct node *save;
    save = FIRST;
    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->link;
    }
}
