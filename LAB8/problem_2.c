#include "stdio.h"
#include "stdlib.h"
struct node
{
    int info;
    struct node *link;
};
struct node *FIRST = NULL;
void main()
{
    int c = 1;
    do
    {
        struct node *newNode, *save;
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newNode->info);
        newNode->link = NULL;
        if (FIRST == NULL)
        {
            FIRST = newNode;
        }
        else
        {
            save = FIRST;

            while (save->link != NULL)
            {
                save = save->link;
            }
            save->link = newNode;
        }
        printf("0. To exit\n");
        printf("1. To insert node at first\n");
        scanf("%d", &c);

    } while (c != 0);

    struct node *save, *pred;
    save = FIRST->link;
    pred = FIRST;
    while (save != NULL)
    {
        if (save->info == pred->info)
        {
            pred->link = save->link;
            free(save);
            save = pred->link;
        }
        else
        {
            pred = save;
            save = save->link;
        }
    }
    save = FIRST;
    while (save != NULL)
    {
        printf("%d->", save->info);
        save = save->link;
    }
}
