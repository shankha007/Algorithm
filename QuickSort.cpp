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

int partition(int low, int high)
{
	int pivot=a[high];
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			int temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	int temp=a[i+1];
	a[i+1]=a[high];
	a[high]=temp;
	return (i+1);
}

void QuickSort(int low, int high)
{
	if(low<high)
	{
		int q=partition(low,high);
		QuickSort(low,q-1);
		QuickSort(q+1,high);
	}
}


int main()
{
	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
	readArray();
	printf("\nSo, Before sorting the array is:\n");
	printArray();
	QuickSort(0,n-1);
	printf("\nSo, After sorting the array is:\n");
	printArray();
}
