#include "stdio.h"
#include "stdlib.h"

struct node
{
    int info;
    struct node *link;
};
struct node *FIRST = NULL;
void main(){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newNode->info);
    newNode->link=NULL;
    FIRST=newNode;
    printf("info:%d add:%p ",newNode->info,newNode);
    
}