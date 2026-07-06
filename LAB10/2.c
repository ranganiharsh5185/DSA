#include"stdio.h"
#include"stdlib.h"
struct node{
    int info;
    struct node *link;
};
struct node *FIRST=NULL;
void insert_at_last();
void display();
void replace();
void main(){
    int c=0;
    while(1){

        printf("1.to insert node\n");
        printf("0.to exit\n");
        scanf("%d", &c);
        if (c == 1)
        {
            insert_at_last();
        }
        else{
            c=0;
            break;
        }
    }
    replace();
    display();
}
void insert_at_last(){
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
int count_node();

void replace(){
    int k=0,n,i=1,temp;
    struct node *save,*save2=FIRST;
    save=FIRST;
    printf("Enter the node no:");
    scanf("%d",&k);
    n = count_node()-k;
    while(i<k){
        save=save->link;
        i++;
    }
   
    temp = save->info;
    i = 1;
    while(i <= n){
        save2= save2->link;
        i++;
    }

    save->info = save2->info;
    save2->info = temp;
}
int count_node()
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
    return count;
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
            printf("%d ", save->info);
            save = save->link;
        }
        printf("\n");
    }
}