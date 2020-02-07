#include<stdio.h>
#include<stdlib.h>
char T[]="abaabbabaabaabaa";
char P[]="abaaba";
int F[100];

void FailureFunction()
{
	int m = sizeof(P)/sizeof(P[0])-1;
	F[0]=0;
	int i=1,j=0;
	while(i<m)
	{
		if(P[i]==P[j])
		{
			F[i]=j+1;
			i++;
			j++;
		}
		else if(j>0)
		{
			j=F[j-1];
		}
		else
		{
			F[i]=0;
			i++;
		}
	}
	printf("\nOutput of Failure Function: ");
	for(int k=0;k<m;k++)
		printf("%d ",F[k]);
}

void KMP()
{
	int n = sizeof(T)/sizeof(T[0])-1;
	int m = sizeof(P)/sizeof(P[0])-1;
	FailureFunction(P);
	int i=0,j=0;
	while(i<n)
	{
		if(T[i]==P[j])
		{
			if(j==m-1)
			{
				printf("\nPattern found with shift %d.", (i-j));
				j=F[j-1];
			}
			else
			{
				i=i+1;
				j=j+1;
			}
		}
		else
		{
			if(j>0)
				j=F[j-1];
			else
				i=i+1;
		}
	}
}
int main()
{
	KMP();
	return 0;
}
