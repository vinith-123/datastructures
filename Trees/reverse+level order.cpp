#include<iostream>
using namespace std;
typedef struct btnode{
	struct btnode *lchild;
	char data;
	struct btnode *rchild;
}*BTPTR;
string str;int i=0;
struct stack{
	int top;
	int size;
	BTPTR elements[50];
}s,s1;
bool sfull()
{
	return (s.top==s.size-1)?true:false;
}
bool sempty()
{
	return (s.top==-1)?true:false;
}
void push(stack &s,BTPTR T)
{
	if(sfull())
	cout<<"error stack overflow\n";
	else
	s.elements[++s.top]=T;
}
BTPTR pop(stack &s)
{
	if(sempty())
	cout<<"error stack underflow\n";
	else
	return s.elements[s.top--];
}
struct queue{
	int front;
	int rear;
	BTPTR elements[50];
	int size;
}q;
bool qfull()
{
	return (q.rear+1)%q.size==q.front?true:false;
}
bool qempty()
{
	return (q.front==-1)?true:false;
}
void enqueue(BTPTR T)
{
	if(qfull())
	cout<<"error queue full";
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.elements[q.rear]=T;
	}
}
BTPTR dequeue()
{
	if(qempty())
	cout<<"error queue empty";
	else
	{
		int index=q.front;
		if(q.front==q.rear)
		{
			q.front=-1;q.rear=-1;
		}
		else
		q.front=(q.front+1)%q.size;
		return q.elements[index];
	}
}
void levelorder(BTPTR &T)
{
	enqueue(T);
	BTPTR dm=new(btnode),temp;
	dm->data='/';
	enqueue(dm);
	while(!qempty())
	{
		temp=dequeue();
		if(temp->data!='/')
		{
			push(s,temp);
			if(temp->lchild!=NULL)
			enqueue(temp->lchild);
			if(temp->rchild!=NULL)
			enqueue(temp->rchild);
		}
		else
		{
			push(s,temp);
			if(!qempty())
			enqueue(dm);
			else
			break;
		}
	}
}
void create(BTPTR &T)
{
	T=new(btnode);
	T->data=str[i++];
	T->lchild=NULL;
	T->rchild=NULL;
	if(str[i]!='.')
	create(T->lchild);
	else
	i++;
	if(str[i]!='.')
	create(T->rchild);
	else
	{
		i++;
		return;
	}
}
int main()
{
	BTPTR T,temp;
	q.front=-1;q.rear=-1;q.size=50;
	s.top=-1;s.size=50;s1.top=-1;s.size=50;
	cout<<"enter the tree as string::";
	cin>>str;
	create(T);
	levelorder(T);
	temp=pop(s);
	while(s.top!=-1)
	{
		temp=pop(s);
		if(temp->data!='/')
		push(s1,temp);
		else
		{
			while(s1.top!=-1)
			cout<<pop(s1)->data<<" ";
			cout<<endl;
		}
	}
	cout<<temp->data<<endl;
	return 0;
}

