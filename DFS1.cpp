#include<stdio.h>
FILE *f;
#define MAX 10
int a[10][10],n;
int top=-1,st[10];
void readGraph()
{
	f=fopen("graphDFS","r");
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

void push(int s)
{
	st[++top]=s;
}

int pop()
{
	return st[top--];
}

int isFull()
{
	if(top==MAX-1)
		return 1;
	return 0;
}

int isEmpty()
{
	if(top==-1)
		return 1;
	return 0;
}

void DFS(int s)
{
	int visited[10]={0};
	push(s);
	visited[s]=1;
	while(!isEmpty())
	{
		int p=pop();
		printf("%c\t",p+'A');
		for(int j=0;j<n;j++)
		{
			if(!visited[j] && a[p][j]==1)
			{
				push(j);
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
	DFS(s);
}
