#include<stdio.h>
int s[100][100];
void printOptimalParen(int i, int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		printOptimalParen(i,s[i][j]);
		printOptimalParen(s[i][j]+1,j);
		printf(")");
	}
}

void matrixChain(int p[], int m1)
{
	int n=m1-1;
	int m[n][n];
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			m[i][j]=99999;
			for(int k=i;k<=j-1;k++)
			{
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(m[i][j]>q)
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i<=j)
				printf("%d\t",m[i][j]);
			else
				printf("\t");
		}
		printf("\n");
	}
	printf("\nSo the Chain Multiplication is as follows:\n");
	printOptimalParen(1,n);
}

void main()
{
	int p[5],m;
	printf("\nEnter the length of the P vector: ");
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		scanf("%d",&p[i]);
	matrixChain(p,m);
}
