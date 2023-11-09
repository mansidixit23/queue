/*	Static implementation of linear queue	*/
#include<iostream>
using namespace std;
#define MAX 5
int IsFull();
int IsEmpty();
void Enqueue();
void Dequeue();
void F_element();
void R_element();
void Traversal();
int q[MAX], front = - 1, rear = - 1;
int main()
{
    int choice;
    while (1)
    {
        printf("\n\n--------- LINEAR QUEUE OPERATIONS ---------\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display \n");
        printf("4. Front Element \n");
        printf("5. Rear Element \n");
        printf("6. Exit \n");
		printf("------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:{Enqueue();break;}
            case 2:{Dequeue();break;}
            case 3:{Traversal();break;}
            case 4:{F_element();break;}
            case 5:{R_element();break;}
            case 6:exit(0);
            default:printf("Inavlid choice \n");
        } /*End of switch*/
    } /*End of while*/
} /*End of main()*/

int IsEmpty()
{
	if (front == - 1)	return 1;
	else return 0;
}
int IsFull()
{
	if (rear == MAX - 1)	return 1;
	else return 0;
}
void F_element()
{
	if (IsEmpty())
		printf("\nQueue is empty");
	else
		printf("\nFront Element is : %d", q[front]);
}
void R_element()
{
	if (IsEmpty())
		printf("\nQueue is empty");
	else
		printf("\nRear Element is : %d", q[rear]);
}
void Enqueue()
{
    int val;
    if (IsFull())
    printf("Queue Overflow \n");
    else
    {
        printf("Inset the element in queue : ");
        scanf("%d", &val);
		if (IsEmpty()) /*If queue is initially empty */
        	front = rear = 0;
        else        
        	rear = rear + 1;
        q[rear] = val;
    }
} /*End of Enqueue()*/
void Dequeue()
{
    if (IsEmpty())
        printf("Queue Underflow \n");
    else
    {
        printf("Deleted Element is : %d\n", q[front]);
        if(front==rear)	//Q has single element only
        	front=rear=-1;
        else
        	front = front + 1;
    }
} /*End of Dequeue() */
void Traversal()
{
    int i;
    if (IsEmpty())
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : ");
        for (i = front; i <= rear; i++)
            printf("%d\t ", q[i]);
    }
} /*End of Traversal() */


