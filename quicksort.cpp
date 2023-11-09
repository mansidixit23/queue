/* Write a program to implement quick sort algorithm */
#include<iostream>
using namespace std;
void  quick_sort(int a[], int beg, int end)
{
	int pivot;
	if(beg<end)
	{
		pivot=partition(a,beg,end);
		quick_sort(a,beg,pivot-1);
		quick_sort(a,pivot+1,end);
	}
}
void swap(int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int partition(int a[], int beg, int end)
{
	int left, right, pivot;
	pivot=left=beg;
	right=end;
	while((a[pivot]<=a[right])&&(pivot!=right))
	right--;
	if(a[pivot]>a[right])
	{
		swap(&a[pivot], &a[right]);
		pivot=right;
	}
	while((a[pivot]>=a[left]) && (pivot!=left))
	left++;
	if (a[pivot]<a[left])
	{
		swap(&a[pivot], &a[left]);
		pivot=left;
	}
	return pivot;
}
int main()
{
	int arr[20],i,n;
	printf("\nEnter the number of elements in the array : ");
	scanf("%d",&n);
	printf("\nEnter the elements of the array : ");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	quick_sort(arr,0,n-1);
	printf("\nThe sorted array is : \n");
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
}