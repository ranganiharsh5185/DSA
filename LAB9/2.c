#include "stdio.h"
#include "stdlib.h"
struct node
{
    int info;
    struct node *link;
};
struct node *FIRST = NULL;
void insert_at_last();
void reverse_linked();
void display();

void main()
{
    int ch = 0;

    do
    {
        printf("1. to enter node in linked list\n");
        printf("2. to exit\n");
        scanf("%d", &ch);
        
        if (ch == 1)
            insert_at_last();

    } while (ch != 2);
    reverse_linked();
    display();
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
void reverse_linked(){
    struct node *curr,*prev,*next;
    curr = FIRST;
    prev = NULL;
    while(curr != NULL){
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;

    }
}

void display()
{
    struct node *save;

    save = FIRST;
    while (save != NULL)
    {
        printf("%d  %p \n", save->info, save);
        save = save->link;
    }
}
