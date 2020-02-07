#include<stdio.h>
static int count=0;
void TOH(int n, char S, char D, char A)
{
	if(n==1)
	{
		printf("\nMove from %c to %c",S,D);
		count++;
		return;
	}
	else
	{
		TOH(n-1,S,A,D);
		TOH(1,S,D,A);
		TOH(n-1,A,D,S);
	}
}

void main()
{
	printf("\n--------Tower of Hanoi--------");
	int n;
	printf("\nEnter the no. of disks: ");
	scanf("%d",&n);
	TOH(n,'A','C','B');
	printf("\nTotal no. of moves: %d",count);
}
