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

void sortArray()
{
	for(int i=1;i<n;i++)
	{
		printf("\nPass %d: ",i);
		int j=i-1;
		int key=a[i];
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
		printArray();
	}
}


void main()
{
	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
	readArray();
	printf("\nSo, Before sorting the array is:\n");
	printArray();
	sortArray();
	printf("\nSo, After sorting the array is:\n");
	printArray();
}
