#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define ISOVERFLOW top >= MAX - 1
int top = -1, front = 0;
int queue[MAX];
void enq(int);
void deq();
void display();
int main()
{

    int choice, val;
    while (1)
    {

        printf("\nenter \n1-enqueue\n2-dequeue\n3-display\n4-exit\n");
		printf("enter the choice\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:	printf("enter value to insert\n");
				scanf("%d",&val);
				enq(val);
				break;
		case 2: deq();
				break;
		case 3:	display();
				break;
		case 4:	exit(0);
		default:printf("enter proper choice");
        }
    }
}
void enq(int val)
{
    if (ISOVERFLOW)
        printf("QUEUE IS FULL\n");
    else
    {
        top++;
        queue[top] = val;
    }
}
void deq() 
{
    if (front > top)
        printf("QUEUE IS EMPTY CANNOT BE DEQUEUED\n");
    else
    {
        printf("deleted element is -> %d\n",queue[front]);
        front++;
    }
}
void display()
{
    int temp;
    if (front > top)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        printf("The Queue elements are as follows\n");
           for (temp = front;temp <= top;temp++)
            printf(" %d\t", queue[temp]);
    }
}
