#include<iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
}*lptr;
struct queue{
	lptr front;
	lptr rear;
}q;
void enqueue(int x)
{
	lptr temp;
	temp=new(lnode);
	temp->data=x;
	temp->next=NULL;
	if(q.front==NULL)
	{
		q.front=temp;
		q.rear=temp;
	}
	else
	{
		while(q.rear->next!=NULL)
		q.rear=q.rear->next;
		q.rear->next=temp;
		q.rear=temp;
	}
}
int dequeue()
{
	lptr temp=NULL;
	if(q.front==NULL)
	{
		cout<<"error queue is empty:(";
		return -1;
	}
	else
	{
		temp=q.front;
		if(q.front==q.rear)
		{
			q.front=NULL;
			q.rear=NULL;
		}
		else
		q.front=temp->next;
		return 	temp->data;
	}
}
int main()
{
	int n,ele;q.front=NULL;q.rear=NULL;
	cout<<"enter no of elements:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		enqueue(ele);
	}
	//while(q.front!=NULL)
	for(int i=0;i<n;i++)
	cout<<dequeue()<<" ";
	return 0;
}
