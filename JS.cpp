#include<iostream>
using namespace std;

typedef struct data
{
	int p;
	int t;
}data;


class JS
{
	public:
	data d[10];
	int n,x[10];
	bool slot[10];
	void readData()
	{
		cout << "\nEnter the no. of Jobs: ";
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cout << "\nEnter the Profit and Deadline of " << i+1 << "th Job: ";
			cin >> d[i].p;
			cin >> d[i].t;
		}
	}
	int min(int a, int b)
	{
		if(a>b) return b;
		else	return a;
	}
	void swap(int & a, int & b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	void sortProfit()
	{
		for(int i=0;i<n-1;i++)
			for(int j=0;j<n-i-1;j++)
				if(d[j].p<d[j+1].p)
				{
					swap(d[j].p,d[j+1].p);
					swap(d[j].t,d[j+1].t);
				}
		cout << "\nTable after Sorting:\n";
		cout << "Profit: ";
		for(int i=0;i<n;i++)
			cout << d[i].p << "\t";
		cout << "\nDeadline: ";
		for(int i=0;i<n;i++)
			cout << d[i].t << "\t";
		cout << "\n";
	}
	void jsd()
	{
		int profit=0;
		int i,j;
		for(i=0;i<n;i++)
		{
			x[i]=0;
			slot[i]=false;
		}
		for(i=0;i<n;i++)
		{
			for(j=min(n,d[i].t)-1;j>=0;j--)
			{
				if(slot[j]==false)
				{
					x[j]=i+1;
					slot[j]=true;
					profit+=d[i].p;
					break;
				}
			}
		}
		cout << "\nSo, the sequenced Jobs are:\n";
		cout << "Jobs: ";
		for(i=0;i<n;i++)
		{
			cout << x[i] << " ";
		}
		cout << "\nTotal profit: " << profit;
	}
};

int main()
{
	JS a;
	a.readData();
	a.sortProfit();
	a.jsd();
}
