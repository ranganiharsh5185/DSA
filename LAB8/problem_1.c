#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *FIRST = NULL;
struct node *SECOND = NULL;

int main()
{
    int c = 1, w = 1, count = 0, count2 = 0, n = 0;

    do
    {
        struct node *newNode;
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter the data: ");
        scanf("%d", &newNode->info);

        newNode->link = FIRST;
        FIRST = newNode;

        printf("0. To exit\n");
        printf("1. To insert node at first\n");
        scanf("%d", &c);

        count2++;
    } while (c != 0);

    printf("\nEnter data for the second linked list:\n");

    do
    {
        struct node *newNode2;
        newNode2 = (struct node *)malloc(sizeof(struct node));

        printf("Enter the data: ");
        scanf("%d", &newNode2->info);

        newNode2->link = SECOND;
        SECOND = newNode2;

        printf("0. To exit\n");
        printf("1. To insert node at first\n");
        scanf("%d", &w);

        count++;
    } while (w != 0);

    if (count == count2)
    {
        struct node *save = FIRST;
        struct node *save2 = SECOND;

        while (save != NULL && save2 != NULL &&
               save->info == save2->info && n != count)
        {
            n++;
            save = save->link;
            save2 = save2->link;
        }

        if (n == count)
        {
            printf("The linked lists are identical.\n");
        }
        else
        {
            printf("The linked lists are not identical.\n");
        }
    }
    else
    {
        printf("The linked lists are not identical.\n");
    }

    return 0;
}