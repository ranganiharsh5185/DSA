#include <stdio.h>
#include <stdlib.h>

struct node
{
    char info[50];
    struct node *lptr;
    struct node *rptr;
};

struct node *FIRST = NULL;

void insert_at_last();
void play();

int main()
{
    int c;

    while (1)
    {
        printf("\n----- PLAYLIST MENU -----\n");
        printf("1. Add Song\n");
        printf("2. Play Music\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            insert_at_last();
            break;

        case 2:
            play();
            break;

        case 0:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}

void insert_at_last()
{
    struct node *newnode, *save;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter song name: ");
    scanf(" %s", newnode->info);

    newnode->rptr = NULL;
    newnode->lptr = NULL;

    if (FIRST == NULL)
    {
        FIRST = newnode;
        return;
    }

    save = FIRST;

    while (save->rptr != NULL)
    {
        save = save->rptr;
    }

    save->rptr = newnode;
    newnode->lptr = save;
}

void play()
{
    struct node *save;
    int c;

    if (FIRST == NULL)
    {
        printf("\nPlaylist is empty!\n");
        return;
    }

    save = FIRST;

    while (1)
    {
        printf("\n----------------------------\n");
        printf("Currently Playing : %s\n", save->info);
        printf("----------------------------\n");
        printf("1. Previous Song\n");
        printf("2. Next Song\n");
        printf("0. Stop Player\n");
        printf("Enter choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            if (save->lptr == NULL)
            {
                printf("No previous song.\n");
            }
            else
            {
                save = save->lptr;
            }
            break;

        case 2:
            if (save->rptr == NULL)
            {
                printf("No next song.\n");
            }
            else
            {
                save = save->rptr;
            }
            break;

        case 0:
            printf("Music player closed.\n");
            return;

        default:
            printf("Invalid choice!\n");
        }
    }
}