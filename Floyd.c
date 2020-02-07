#include<stdio.h>
#include<stdlib.h>
FILE *f;
int n,g[100][100],d[100][100],p[100][100];
#define NIL 99999

void PrintAllPairShortestPath(int i, int j)
{
	if(i==j)
		printf("%d ",i+1);
	else if(p[i][j]==NIL)
		printf("\nNo path exist.");
	else
	{
		PrintAllPairShortestPath(i,p[i][j]);
		printf("%d ",j+1);
	}
}

void FloydWarshall()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				d[i][j]=0;
			else
			{
				if(g[i][j]==0)
					d[i][j]=99999;
				else
					d[i][j]=g[i][j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[i][j]==99999 || i==j)
				p[i][j]=NIL;
			else
				p[i][j]=i;
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(d[i][j]>d[i][k]+d[k][j])
				{
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=p[k][j];
				}
			}
		}
	}
	printf("\nSo, the Distance Matrix is:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",d[i][j]);
		printf("\n");
	}
	printf("\nSo, the Predecessor Matrix is:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",p[i][j]);
		printf("\n");
	}
}

void main()
{
	f=fopen("graph1","r");
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fscanf(f,"%d",&g[i][j]);
	printf("\nSo, The Graph is:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",g[i][j]);
		printf("\n");
	}
	FloydWarshall();
	printf("\nSo The All Pair Shortest Path is:\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{	if(i!=j)
			{
				printf("\nShortest path from %d to %d:\n",i+1,j+1);
				PrintAllPairShortestPath(i,j);
				printf(" Weight: %d\n",d[i][j]);
			}
		}
}
