#include<iostream>
using namespace std;
int a[10],n;
class MaxMin
{
	int max1,min1;
	public:
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
	void MaMi(int i, int j, int &max, int &min)
	{
		if(i==j)
		{
			max=min=a[i];
		}
		else if(i==j-1)
		{
			if(a[i]>a[j])
			{
				max=a[i];
				min=a[j];
			}
			else
			{
				max=a[j];
				min=a[i];
			}
		}
		else
		{
			int mid=(i+j)/2,max1,min1;
			MaMi(i,mid,max,min);
			MaMi(mid+1,j,max1,min1);
			if(max1>max)
				max=max1;
			if(min1<min)
				min=min1;
		}
	}
};

int main()
{
	int max,min;
	MaxMin z;
	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
	z.readArray();
	printf("\nSo, the array is:\n");
	z.printArray();
	z.MaMi(0,n-1,max,min);
	printf("\nMaximum element is: %d\nMinimum element is: %d",max,min);
}
