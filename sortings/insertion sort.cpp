#include<iostream>
using namespace std;
int main()
{
	int a[10],ele,j;
	for(int i=0;i<10;i++)
	cin>>a[i];
	for(int i=1;i<10;i++)
	{
		ele=a[i];
		j=i;
		while(j>0 && a[j-1]>ele)
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=ele;
	}
	for(int i=0;i<10;i++)
	cout<<a[i]<<" ";
	return 0;
}
