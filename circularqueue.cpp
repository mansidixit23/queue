/*	Static implementation of circular queue	*/
#include<iostream>
using namespace std;
#define max 5
/* Function Prototypes */
int IsFull();
int IsEmpty();
void Enqueue();
void Dequeue();
void F_element();
void R_element();
void Traversal();
int cq[max],front=-1,rear=-1;

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
	if (front==(rear+1)%max)	return 1;
	else return 0;
}
void F_element()
{
	if (IsEmpty())
		printf("\nQueue is empty");
	else
		printf("\nFront Element is : %d", cq[front]);
}
void R_element()
{
	if (IsEmpty())
		printf("\nQueue is empty");
	else
		printf("\nRear Element is : %d", cq[rear]);
}
void Enqueue()	//Inserting an element in the circular queue
{
	int val;
	if (IsFull())
		printf("Queue Overflow");
	else
	{
		printf("Enter the element to be inserted : \t");
		scanf("%d",&val);
		if (IsEmpty())
			front = rear = 0;
		else
			rear=(rear+1)%max;
		cq[rear]=val;
	}
}//End of insert
void Dequeue()	//Deleting an element from the circular queue
{
	if (IsEmpty())
		printf("Queue underflow\n");
	else
	{
		printf("The deleted element is : \t%d", cq[front]);
		if(front==rear)	//Q has single element
			front = rear = -1;
		else
			front=(front+1)%max;
	}	
}	//End of del()

void Traversal()	//To display the queue elements
{
	int i;
	for(i=front; i!=rear; (i=(i+1)%max))
        printf("%d\t",cq[i]);
	printf("%d\t",cq[rear]);
}//End of display() 


