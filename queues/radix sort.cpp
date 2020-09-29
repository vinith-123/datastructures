#include<iostream>
using namespace std;
struct queue{
	int front;
	int rear;
	int size;
	int elements[50];
}q[10];
bool qfull(int index)
{
	return ((q[index].rear+1)%q[index].size)==q[index].front?true:false;
}
bool qempty(int index)
{
	return (q[index].front==-1)?true:false;
}
void enqueue(int index,int ele)
{
	if(qfull(index))
	cout<<"error queue is full";
	else
	{
		if(q[index].front==-1)
		q[index].front=0;
		q[index].rear=(q[index].rear+1)%(q[index].size);
		q[index].elements[q[index].rear]=ele;
	}
}
int dequeue(int index)
{
	int ind;
	if(qempty(index))
	cout<<"error queue is empty";
	else
	{
		ind=q[index].front;
		if(q[index].front==q[index].rear)
		{
			q[index].front=-1;
			q[index].rear=-1;
		}
		else
		q[index].front=(q[index].front+1)%(q[index].size);
		return q[index].elements[ind];
	}
}
int cou(int x)
{
	int c=0;
	while(x!=0)
	{
		c++;
		x=x/10;
	}
	return c;
}
int main()
{
	int n,count=0,max=0,j,v,r;
	for(int i=0;i<10;i++)
	{
		q[i].front=-1;
		q[i].rear=-1;
		q[i].size=50;
	}
	cout<<"enter no of elements:";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(max<cou(a[i]))
		max=cou(a[i]);
	}
	for(int i=1;i<=max;i++)
	{
		for(j=0;j<n;j++)
		{
			count=0;
			v=a[j];
			while(count!=i)
			{
				count++;
				r=v%10;
				v=v/10;
			}
			enqueue(r,a[j]);
		}
		j=0;
		for(int i=0;i<10;i++)
		{
		  while(q[i].front!=-1)
			a[j++]=dequeue(i);
		}
	}
	cout<<"sorted order::";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
