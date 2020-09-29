#include<iostream>
using namespace std;
typedef struct btnode{
	struct btnode *lchild;
	char data;
	struct btnode *rchild;
}*BTPTR;
string s;static int i=0;
struct queue{
	int front;
	int rear;
	int size;
	BTPTR elements[50];
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
	cout<<"stack overflow\n";
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%(q.size);
		q.elements[q.rear]=T;
	}
}
BTPTR dequeue()
{
	int index;
	if(qempty())
	cout<<"stack underflow\n";
	else
	{
		index=q.front;
		if(q.front==q.rear)
		{
			q.rear=-1;
			q.front=-1;
		}
		else
		q.front=(q.front+1)%(q.size);
		return q.elements[index];
	}
}
void levelorder(BTPTR &T)
{
	enqueue(T);
	BTPTR dm=new(btnode),temp;
	dm->data='/';
	dm->lchild=NULL;
	dm->rchild=NULL;
	enqueue(dm);
	while(!qempty())
	{
		temp=dequeue();
		if(temp->data!='/')
		 {
			cout<<temp->data<<" ";
			if(temp->lchild!=NULL)
			enqueue(temp->lchild);
			if(temp->rchild!=NULL)
			enqueue(temp->rchild);
		  }
		else
		{
			cout<<endl;
			if(qempty())
			break;
			enqueue(dm);
		}
	}
}
void create(BTPTR &T)
{
	if(i!=s.length())
	{
		T=new(btnode);
		T->lchild=NULL;
		T->rchild=NULL;
		T->data=s[i++];
		if(s[i]!='.')
		create(T->lchild);
		else
		i++;
		if(s[i]!='.')
		create(T->rchild);
		else
		{
			i++;
			return;
		}
	}
}
int main()
{
	BTPTR T=NULL;
	q.front=-1;q.rear=-1;q.size=50;
	cout<<"enter the tree as a string::";
	cin>>s;
	create(T);
	levelorder(T);
	return 0;
}
