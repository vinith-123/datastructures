#include<iostream>
using namespace std;
struct queue{
	int front;
	int rear;
	int size;
	char elements[50];
};
bool qfull(queue &q)
{
	return (q.rear+1)%(q.size)==q.front?true:false;
}
bool qempty(queue &q)
{
	return q.front==-1?true:false;
}
void enqueue(queue &q,int  c)
{
	if(qfull(q))
	cout<<"error queue is full\n";
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.elements[q.rear]=c;
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
		{
			q.front=-1;
			index=q.rear;
			q.rear=-1;
			return q.elements[index];
		}
		else
		{
			index=q.front;
			q.front=(q.front+1)%(q.size);
			return q.elements[index];
		}
	}
}
struct stack{
	int top;
	int size;
	int elements[50];
};
bool sfull(stack &s)
{
	return s.top==s.size-1?true:false;
}
bool sempty(stack &s)
{
	return s.top==-1?true:false;
}
void push(stack &s,int c)
{
	if(sfull(s))
	cout<<"error stack is full\n";
	else
	s.elements[++s.top]=c;
}
int pop(stack &s)
{
	if(sempty(s))
	{
		cout<<"error stack is empty\n";
		return -1;
	}
	else
	return s.elements[s.top--];
}
int main()
{
	queue *q;stack *s;
	s=new(stack);
	q=new(queue);
	q->front=-1;q->rear=-1;q->size=50;
	s->size=50;s->top=-1;
	int n;int ch;
	cout<<"enter no of elements\n";
	cin>>n;
	cout<<"enter integers";
	for(int i=0;i<n;i++)	
	{
		cin>>ch;
		enqueue(*q,ch);	
	}
	for(int i=0;i<n;i++)
	{
		push(*s,dequeue(*q));
	}
	for(int i=0;i<n;i++)
	{
		enqueue(*q,pop(*s));
	}
	for(int i=0;i<n;i++)
	cout<<dequeue(*q)<<" ";
	return 0;
}
