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

void Merge(int low, int mid, int high)
{
	int n1,n2,i,j,k;
	n1=mid-low+1;
	n2=high-mid;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=a[low+i];
	for(j=0;j<n2;j++)
		R[j]=a[mid+j+1];
	i=0,j=0,k=low;
	while(i<n1 && j<n2)
	{
		if(L[i]>R[j])
		{
			a[k]=R[j];
			j++;
		}
		else
		{
			a[k]=L[i];
			i++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}

void MergeSort(int low, int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		MergeSort(low,mid);
		MergeSort(mid+1,high);
		Merge(low,mid,high);
	}
}


int main()
{
	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
	readArray();
	printf("\nSo, Before sorting the array is:\n");
	printArray();
	MergeSort(0,n-1);
	printf("\nSo, After sorting the array is:\n");
	printArray();
}
