#include<stdio.h>
#include<stdlib.h>
FILE *f;
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
void readGraph()
{
	f=fopen("graph2","r");
	fscanf(f, "%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			fscanf(f, "%d",&cost[i][j]);
}

void printGraph()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",cost[i][j]);
		printf("\n");
	}
}
void main()
{
	printf("\n\tImplementation of Kruskal's algorithm\n");
	readGraph();
	printf("\nThe cost adjacency matrix:\n");
	printGraph();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
