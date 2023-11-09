/*To	implement	input	restricted	deque */
#include<iostream>
using namespace std;
#define max 5 
int dq[max], front = -1, rear = -1; 
/* Function Prototypes */
int IsFull();
int IsEmpty();
void insert_rear(); 
void delete_front(); 
void delete_rear(); 
void traversal(); 
int main() 
{ 
int option; 
do 
{  
printf("\n INPUT RESTRICTED DEQUE");  
printf("\n 1.Insert at rear");  
printf("\n 2.Delete from front");  
printf("\n 3.Delete from rear");  
printf("\n 4.Traversal");  
printf("\n 5.Exit");  
printf("\n Enter your option : ");  
scanf("%d",&option);  
switch(option)  
{   
case 1:{insert_rear();break;} 
case 2:{delete_front();break;}
case 3:{delete_rear();break;}
case 4:{traversal();break;}   
} 
} while(option!=5);
} 
int IsFull()
{
	if(front==(rear+1)%max)
	return 1;
	else return 0;
}
int IsEmpty()
{
	if(front==-1)
	return 1;
	else return 0;
}
void insert_rear() 
{ 
int val; 
if(IsFull()) 
printf("\n OVERFLOW");  
else
{
printf("\n Enter the value to be added:"); 
scanf("%d", &val);
if (IsEmpty())// if queue is initially empty
front = rear = 0; 
else
	rear=(rear+1)%max;
dq[rear] = val ; 
} 
}
void delete_front() 
{ 
if (IsEmpty())  
printf("\n UNDERFLOW");
else
{
printf("\n The deleted element is : %d", dq[front]); 
if(front==rear)	//Q has single element
	front = rear = -1;
else
	front=(front+1)%max;
}
}
void delete_rear() 
{ 
if (IsEmpty())  
printf("\n UNDERFLOW"); 
else
{
printf("\n The element deleted is : %d", dq[rear]); 
if(front == rear) /*queue has only one element*/ 
front = rear = -1;
else if(rear == 0)   
rear=max-1;  
else   
rear=rear-1;  	
}
}
void traversal() 
{ 
	int i;
	if (IsEmpty())  
	printf("\n Deque is empty"); 
	else
	{
		for(i=front; i!=rear; (i=(i+1)%max))
        printf("%d\t",dq[i]);
		printf("%d\t",dq[rear]);
	}
}






