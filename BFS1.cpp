#include<stdio.h>
FILE *f;
#define MAX 10
int a[10][10],n;
int rear=-1,front=-1,q[10];
void readGraph()
{
	f=fopen("graphBFS","r");
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fscanf(f,"%d",&a[i][j]);
}

void printGraph()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}

void insert(int s)
{
	q[++rear]=s;
}

int del()
{
	return q[++front];
}

int isFull()
{
	if(rear==MAX-1)
		return 1;
	return 0;
}

int isEmpty()
{
	if(front==rear)
		return 1;
	return 0;
}

void BFS(int s)
{
	int visited[10]={0};
	insert(s);
	visited[s]=1;
	while(!isEmpty())
	{
		int p=del();
		printf("%c\t",p+'A');
		for(int j=0;j<n;j++)
		{
			if(!visited[j] && a[p][j]==1)
			{
				insert(j);
				visited[j]=1;
			}
		}
	}
}

int main()
{
	readGraph();
	printf("\nThe Adjacency Matrix of the graph is:\n");
	printGraph();
	printf("\nEnter the source node: ");
	char s;
	scanf("%c",&s);
	s=s-'A';
	BFS(s);
}
