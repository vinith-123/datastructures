#include<iostream>
using namespace std;
int main()
{
	int n,max=0,min=0,ele;
	cout<<"enter no of elements:";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(max==0 || min==0)
		{
			if(max==0)
			max=a[i];
			else
			{
				min=a[i];
				if( max < min)
				{
					ele=min;
					min=max;
					max=ele;
				}
			}
		}
		else
		{
			ele=a[i];
			if( ele < min )
			{
				cout<<min<<" "<<max<<"\n";
				max=ele;
				min=0;
			}
			else if( ele < max && ele >min)
			{
				cout<<min<<" ";
				min=ele;
			}
			else
			{
				cout<<min<<" ";
				min=max;
				max=ele;
			}
		}
	}
	if(min!=0)cout<<min<<" ";
	if(max!=0)cout<<max<<" ";
	return 0;
}
