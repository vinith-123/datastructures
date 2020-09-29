#include<iostream>
using namespace std;
void swap(int A[],int a,int b)
{
	int temp=A[a];
	A[a]=A[b];
	A[b]=temp;
}
int partition(int a[],int low,int high)
{
	if(low>=high)
	return -1;
	if(low<high)
	{
		int p=a[low],l=low+1,h=high;
		while(l<h)
		{
			while(a[l]<p)
			l++;
			while(a[h]>p)
			h--;
			if(l<h)
			swap(a,l,h);
		}
		swap(a,low,h);
		return h;
	}
}
void quicksort(int a[],int low,int high)
{
	int j=partition(a,low,high);
	if(j==-1)
	return;
	quicksort(a,low,j-1);
	quicksort(a,j+1,high);
}

int main()
{
	int n,low,high,l,h,p,count=0,j;
	int a[9]={15,8,1,27,32,9,4,22,11};
	low=0;
	high=8;
	n=9;
	quicksort(a,low,high);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
}
