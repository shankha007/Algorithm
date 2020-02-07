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

void heapify(int n, int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && a[l]>a[largest])
		largest=l;
	if(r<n && a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(n,largest);
	}
}

void HeapSort()
{
	for(int i=n/2;i>=0;i--)
	{
		heapify(n,i);
	}
	for(int i=n-1;i>=0;i--)
	{
		int temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		heapify(i,0);
	}
}


int main()
{
	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
	readArray();
	printf("\nSo, Before sorting the array is:\n");
	printArray();
	HeapSort();
	printf("\nSo, After sorting the array is:\n");
	printArray();
}
