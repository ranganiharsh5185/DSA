#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 50
struct queue
{
    int s[MAX];
    int F;
    int R;
};
void display(struct queue *q1);
int dequeue( struct queue *q1);
void enqueue(struct queue *q1,int y);
int main()
{

    struct queue q1;
    q1.F=-1;
    q1.R=-1;
    int c = 1, y = 0;
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
                printf("enter the value to insert:");
                scanf("%d", &y);
                enqueue(&q1,y);
                break;

            case 2:
              printf("the element is dequeue=%d",dequeue(&q1));
                break;
            case 3:
                display(&q1);
                break;
            }
        }
    }

    return 0;
}


void enqueue(struct queue *q1,int y){

    
    if(q1->R>=MAX-1){
        printf("Queue overflow!!!");
        return;
    }
    else{

        q1->s[++(q1->R)]=y;
        if(q1->F==-1){
            q1->F=0;
            
        }c
    }
}

int dequeue( struct queue *q1){
    if(q1->F==-1){
        printf("Queue underflow!!!");
        return 0;
    }
    int y=q1->s[q1->F];
    if(q1->F==q1->R){
        q1->F=-1;
        q1->R=-1;
    }
    else{
        q1->F++;
    }
    return y;
}

void display(struct queue *q1){
   if(q1->F==-1 && q1->R==-1){
    printf("queue is empty");
   }
    for(int i=q1->F;i<=q1->R;i++){
        printf("%d  ",q1->s[i]);
    }

}
