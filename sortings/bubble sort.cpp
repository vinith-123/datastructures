#include<iostream>
using namespace std;
int main()
{
	int a[5]={5,4,3,2,1},n=5,temp;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n-i;j++)
		{
			if(a[j] < a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
	for(int i=0;i<5;i++)
	cout<<a[i]<<" ";
	return 0;
}
