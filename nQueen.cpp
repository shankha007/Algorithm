#include<iostream>
using namespace std;
bool canbeplaced(int *x,int k,int i)
{
	for(int j=1;j<=(k-1);j++)
	{
		if((x[j]==i) || (abs(j-k)==abs(x[j]-i)))
			return false;
	}
	return true;
}
void print(int *x,int n)
{	
	cout<<"The solution vector is : ";
	for(int i=1;i<=n;i++)
		cout<<x[i]<<" ";
	cout<<endl;
}
void nqueen(int *x,int n,int k)
{
	for(int i=1;i<=n;i++)
	{
		if(canbeplaced(x,k,i))
		{
			x[k]=i;
			if(k==n)
				print(x,n);
			else
				nqueen(x,n,k+1);
		}
	}
}
int main()
{
	int n;
	cout<<"Enter the number of queens\n";
	cin>>n;
	int *x=new int[n+1];
	nqueen(x,n,1);
}
