#include<stdio.h>
#include<stdlib.h>
int x[20], arr[50][50],n;
void readGraph()
{
	int i,j;
	FILE *fp;
	fp=fopen("graphC", "r");
	if(fp==NULL)
	{
		printf("File doesn't exist.");
		exit(0);
	}
	else
	{
		fscanf(fp, "%d", &n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				fscanf(fp, "%d", &arr[i][j]);
	}
}

void showGraph()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%3d", arr[i][j]);
		printf("\n");
	}
}

void nextValue(int k)
{
	int j,m=3;
	while(1)
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		for(j=0;j<n;j++)
			if(arr[k][j]!=0 && x[k]==x[j])
				break;
		if(j==n)
			return;
	}
}

void print(int x[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ", x[i]);
	printf("\n");
}

void mColoring(int k)
{
	while(1)
	{
		nextValue(k);
		if(x[k]==0)
			return;
		if(k==n)
			print(x,n);
		else
			mColoring(k+1);
	}
}

int main()
{
	int i,s;
	readGraph();
	showGraph();
	for(i=0;i<n;i++)
		x[i]=0;
	printf("\nEnter source vertex: ");
	scanf("%d",&s);
	mColoring(s);
	return 0;
}
