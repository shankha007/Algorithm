#include<iostream>
#include<iomanip>
using namespace std;

typedef struct Element
{
	int p;
	int w;
}data;

data d[10];

class Knapsack
{
	public:
	int n;
	float ppu[10];
	void swap(int & a, int & b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	void swap(float & a, float & b)
	{
		float temp=a;
		a=b;
		b=temp;
	}
	void readData()
	{
		cout << "\nEnter the no. of products: ";
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cout << "\nEnter the Quantity and Amount for " << i+1 << "th product: ";
			cin >> d[i].w;
			cin >> d[i].p;
		}
	}
	void perUnit()
	{
		for(int i=0;i<n;i++)
			ppu[i]=d[i].p/d[i].w;
	}
	void sortPpu()
	{
		for(int i=0;i<n-1;i++)
			for(int j=0;j<n-i-1;j++)
				if(ppu[j]<ppu[j+1])
				{
					swap(ppu[j],ppu[j+1]);
					swap(d[j].p,d[j+1].p);
					swap(d[j].w,d[j+1].w);
				}
		cout << "\nTable after Sorting:\n";
		cout << "Price: ";
		for(int i=0;i<n;i++)
			cout << d[i].p << "\t";
		cout << "\nWeight: ";
		for(int i=0;i<n;i++)
			cout << d[i].w << "\t";
		cout << "\nPPU: ";
		for(int i=0;i<n;i++)
			cout << ppu[i] << "\t";
		cout << "\n";
	}
	void knapSack()
	{
		int i;
		float req,x[10]={0.0};
		cout << "\nEnter your requirement: ";
		cin >> req;
		for(i=0;i<n;i++)
		{
			if(d[i].w>req)
				break;
			x[i]=1;
			req=req-d[i].w;
		}
		if(i<n)
			x[i]=req/d[i].w;
		cout << "\nSo the Resultant Vector is:\n";
		for(i=0;i<n;i++)
			cout << setprecision(3) << x[i] << "\t";
		float profit=0.0;
		for(i=0;i<n;i++)
			profit+=x[i]*d[i].p;
		cout << "\nTotal Profit: " << profit;
	}
};

int main()
{
	Knapsack a;
	a.readData();
	a.perUnit();
	a.sortPpu();
	a.knapSack();
}
