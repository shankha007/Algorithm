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
	for(int i=0;i<n-1;i++)
	{
		printf("\nPass %d: ",i+1);
		int key=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[key]>a[j])
				key=j;
		}
		if(key!=i)
		{
			int temp=a[i];
			a[i]=a[key];
			a[key]=temp;
		}
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
