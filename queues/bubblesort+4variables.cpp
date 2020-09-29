#include<iostream>
using namespace std;
struct queue{
	int front;
	int rear;
	int size;
	int elements[50];
};
bool qfull(queue q)
{
	return ((q.rear+1)%(q.size)==q.front)?true:false;
}
bool qempty(queue q)
{
	return q.front==-1?true:false;
}
void enqueue(queue &q,int x)
{
	if(qfull(q))
	cout<<"error queue is full\n";
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%(q.size);
		q.elements[q.rear]=x;
	}
}
int dequeue(queue &q)
{
	int index;
	if(qempty(q))
	cout<<"error queue is empty\n";
	else
	{
		if(q.front==q.rear)
		q.rear=-1;
		index=q.front;
		q.front=(q.front+1)%(q.size);
		return q.elements[index];
	}
}
int main()
{
	queue *q;int n,temp,e1,e2;
	q=new(queue);
	q->front=-1;q->rear=-1;q->size=50;
	cout<<"enter no of elements:";
	cin>>n;
	cout<<"\nenter the elements to be sorted:";
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		enqueue(*q,temp);
	}
	for(int i=0;i<n-1;i++)
	{
		e1=dequeue(*q);
		for(int j=0;j<n-1;j++)
		{
			e2=dequeue(*q);
			if(e1<e2)
			{
				temp=e1;
				e1=e2;
				e2=temp;
			}
			enqueue(*q,e2);
		}
		enqueue(*q,e1);
	}
	cout<<"sorted order:";
	for(int i=0;i<n;i++)
	cout<<dequeue(*q)<<" ";
	return 0;
}
