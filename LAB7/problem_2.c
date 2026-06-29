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
    void insert_at_first();
    void display();
    void delete_first();
    void insert_at_last();
    void delete_last();
    void delete_specified_pos();
    void count_node();

    int c = 1;
    while (c != 0)
    {
        printf("1.to insert node at first\n");
        printf("2.to display the nodes\n");
        printf("3.to delete the first node\n");
        printf("4.to insert node at last\n");
        printf("5.to delete the last node\n");
        printf("6.to delete the specified node\n");
        printf("7.to count the number of nodes\n");
        printf("0.to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert_at_first();
            break;
        case 2:
            display();
            break;
        case 3:
            delete_first();
            break;
        case 4:
            insert_at_last();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            delete_specified_pos();
            break;
        case 7:
            count_node();
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

void insert_at_first()
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->info);
    newNode->link = FIRST;
    FIRST = newNode;
}

void display()
{
    struct node *save;
    if (FIRST == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        save = FIRST;
        while (save != NULL)
        {
            printf("%d  ", save->info);
            printf("add:%p  ", save);
            save = save->link;
            printf("\n");
        }
    }
}
void delete_first()
{
    struct node *save;
    if (FIRST == NULL)
    {
        printf("listnis empty\n");
    }
    else
    {
        save = FIRST;
        FIRST = FIRST->link;
        free(save);
    }
}
void insert_at_last()
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
}
void delete_last()
{
    struct node *save, *pred;
    if (FIRST == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        save = FIRST;
        while (save->link != NULL)
        {
            pred = save;
            save = save->link;
        }
        pred->link = NULL;
        free(save);
    }
}
void delete_specified_pos()
{
    struct node *save, *pred;
    int x;
    printf("Enter the data to delete: ");
    scanf("%d", &x);
    save=FIRST;
    while (save->info != x)
    {
        pred = save;
        save = save->link;
    }
    pred->link = save->link;
    free(save);
}
void count_node()
{
    struct node *save;
    int count = 0;
    save = FIRST;
    while (save != NULL)
    {
        count++;
        save = save->link;
    }
    printf("Number of nodes in the list: %d\n", count);
}