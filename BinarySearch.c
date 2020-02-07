#include<stdio.h>
#include<stdlib.h>
int a[10],n;

void readArray()
{
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the %dth  element: ",i+1);
		scanf("%d",&a[i]);
	}
}

void printArray()
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}

void searchKey(int low, int high, int key)
{
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==key)
		{
			printf("\n%d found at position %d.",key,mid+1);
			return;
		}
		else if(a[mid]>key)
			searchKey(low,mid-1,key);
		else
			searchKey(mid+1,high,key);
	}
	if(low>high)
		printf("\n%d not found in the array.",key);
}


void main()
{
	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
	readArray();
	printf("\nSo, the array is:\n");
	printArray();
	int key;
	printf("\nEnter the element to found: ");
	scanf("%d",&key);
	searchKey(0,n-1,key);
}
