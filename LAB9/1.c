#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *FIRST = NULL;
struct node *SECOND = NULL;

void insert_at_last();
void linked_copy();
void display();

int main()
{
    int ch;

    do
    {
        printf("\n1. Insert node\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_at_last();
            break;

        case 2:
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (ch != 2);

    linked_copy();

    printf("\nCopied Linked List:\n");
    display();

    return 0;
}

void insert_at_last()
{
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newNode->info);

    newNode->link = NULL;

    if (FIRST == NULL)
    {
        FIRST = newNode;
    }
    else
    {
        temp = FIRST;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = newNode;
    }
}

void linked_copy()
{
    struct node *temp1, *temp2 = NULL, *newNode;

    temp1 = FIRST;

    while (temp1 != NULL)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }

        newNode->info = temp1->info;
        newNode->link = NULL;

        if (SECOND == NULL)
        {
            SECOND = newNode;
        }
        else
        {
            temp2->link = newNode;
        }

        temp2 = newNode;
        temp1 = temp1->link;
    }
}

void display()
{
    struct node *temp;

    if (SECOND == NULL)
    {
        printf("Copied list is empty.\n");
        return;
    }

    temp = SECOND;

    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }

    printf("NULL\n");
}
