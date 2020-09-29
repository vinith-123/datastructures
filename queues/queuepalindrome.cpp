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
	return (q.front==-1)?true:false;
}
void enqueue(queue &q,char c)
{
	if(qfull(q))
	cout<<"error queue is full\n";
	else
	{
		if(q.front==-1)
		q.front=0;
		q.elements[++q.rear]=c;
	}
}
char dequeue(queue &q)
{
	int index;
	if(qempty(q))
	{
		cout<<"error queue is empty\n";
		return 0;
	}
	else
	{
		if(q.front==q.rear)
		{
			index=q.front;
			q.front=-1;q.rear=-1;
			return q.elements[index];
		}
		else
		{
			index=q.front;
			q.front=(q.front+1)%q.size;
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
void push(stack &s,char c)
{
	if(sfull(s))
	cout<<"error stack is full\n";
	else
	s.elements[++s.top]=c;
}
char pop(stack &s)
{
	if(sempty(s))
	cout<<"error stack is empty";
	else
	return s.elements[s.top--];
}
int main()
{
	string str;char ch;int flag=0;
	stack *s;queue *q;
	s=new(stack);
	q=new(queue);
	s->size=50;s->top=-1;
	q->size=50;q->front=-1;q->rear=-1;
	cout<<"enter the string to be checked::";
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		ch=str[i];
		enqueue(*q,ch);
		push(*s,ch);
	}
	while(flag==0 && s->top!=-1)
	{
		if(pop(*s)!=dequeue(*q))
		flag=1;
	}
	if(flag==1)
	cout<<"Not palindrome!\n";
	else
	cout<<"palindrome!\n";
	return 0;	
}
