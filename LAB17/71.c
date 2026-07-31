#include "stdio.h"
#include "string.h"
#include "stdlib.h"
void display();
void enqueue();
int dequeue();
struct node
{
    int info;
    struct node *link;
};
struct node *FIRST = NULL;
int main()
{

    int c = 1;
    while (c != 0)
    {
        printf("\n1.to perform enqueue\n");
        printf("2.to perform dequeue\n");
        printf("3.to dislay queue\n");
        printf("0.to exit\n");
        printf("enter choice:");
        scanf("%d", &c);
        if (c == 0)
        {
            return 0;
        }
        else
        {
            switch (c)
            {
            case 1:
                enqueue();
                break;

            case 2:
                printf("the dequeue element=%d",dequeue());
                break;
            case 3:
                display();
                break;
            }
        }
    }

    return 0;
}
void enqueue()
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
int dequeue()
{
    int y=0;
    struct node *save;
    
    if (FIRST == NULL)
    {
        printf("list is empty\n");
    }
    else
    { 
        save = FIRST;
        y=save->info;
        FIRST = FIRST->link;
        free(save);
    }
    return y;
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
