#include<iostream>
using namespace std;
int isheap(int *a,int n)
{
	int i,j;
	for(int i=0;i<n;i++)
	{
		j=2*i+1;
		if(j<=n-1)
		if(a[i]>a[j])
		return 0;
		j=2*i+2;
		if(j<=n-1)
		if(a[i]>a[j])
		return 0;
	}
	return 1;
}
int main()
{
	int n,temp,j;
	cout<<"enter no of elements:";
	cin>>n;
	int a[n],flag=0;
	cout<<"enter elements:";
	for(int i=0;i<n;i++)
	cin>>a[i];
		while(flag==0)
		{
			for(int i=0;i<n;i++)
			{
				j=2*i+1;
				if(j<=n-1)
				{
					if(a[j]<a[i])
					{
						temp=a[i];
						a[i]=a[j];
						a[j]=temp;
					}
				}
				j=2*i+2;
				if(j<=n-1)
				{
					if(a[j]<a[i])
					{
						temp=a[i];
						a[i]=a[j];
						a[j]=temp;
					}
				}
			}
			flag=isheap(a,n);
			if(flag==1)
			{
				cout<<a[0]<<" ";
				a[0]=a[n-1];
				n=n-1;
				flag=isheap(a,n);
			}
		}
		for(int i=0;i<n;i++)
		cout<<a[i]<<" ";		
	return 0;
}
