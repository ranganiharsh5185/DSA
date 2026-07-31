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
int cqdelete(struct queue *q1);
void cqinsert(struct queue *q1, int y);
int main()
{

    struct queue q1;
    q1.F = -1;
    q1.R = -1;
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
                cqinsert(&q1, y);
                break;

            case 2:
                printf("the element is dequeue=%d", cqdelete(&q1));
                break;
            case 3:
                display(&q1);
                break;
            }
        }
    }

    return 0;
}

void cqinsert(struct queue *q1, int y)
{

    if (((q1->R) + 1) % MAX == q1->F)
    {
        printf("Queue overflow!!!");
        return;
    }
    else
    {
        (q1->R) = ((q1->R) + 1) % MAX;
        q1->s[(q1->R)] = y;

        if (q1->F == -1)
        {
            q1->F = 0;
        }
    }
}

int cqdelete(struct queue *q1)
{
    if (q1->F == -1)
    {
        printf("Queue underflow!!!");
        return 0        ;
    }
        int y = q1->s[q1->F];
        if (q1->F == q1->R)
        {
            q1->F = -1;
            q1->R = -1;
        }
        else
        {
            q1->F=(q1->F+1)%MAX;
        }
        return y;
    }


    void display(struct queue * q1)
    {
        
    if((q1->F) == -1)
    {
        printf("\n!!! UNDERFLOW !!!\n");
        return;
    }
    int i = q1->F;
    printf("\nQUEUE : ");
    while (i != q1->R)
    {
        printf("%d ",q1->s[i]);

        if(i == MAX-1)
        {
            i = (i+1) % MAX;
        }
        else
        {
            i++;
        }
    }
    printf("%d \n",q1->s[q1->R]);
    return;
    }