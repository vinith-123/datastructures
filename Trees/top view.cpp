#include<iostream>
using namespace std;
typedef struct btnode{
	struct btnode *lchild;
	char data;
	int x;
	struct btnode *rchild;
}*BTPTR;
struct queue{
	int front;
	int rear;
	int size;
	BTPTR elements[50];
}q;
bool qfull()
{
	return (q.rear+1)%(q.size)==q.front?true:false;
}
bool qempty()
{
	return (q.front==-1)?true:false;
}
void enqueue(BTPTR T)
{
	if(qfull())
	cout<<"error queue overflow1\n";
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
	cout<<"error queue is empty\n";
	else
	{
		int index=q.front;
		if(q.front==q.rear)
		{   
			q.front=-1;q.rear=-1;
		}
		else
		q.front=(q.front+1)%(q.size);
		return q.elements[index];
	}
}
string s;int i=0,count=1;
void create(BTPTR &T)
{
	T=new(btnode);
	T->data=s[i++];
	T->lchild=NULL;
	T->rchild=NULL;
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
void inorder(BTPTR T)
{
	if(T==NULL)
	return;
	else
	{
		if(T->lchild!=NULL)
		inorder(T->lchild);
		T->x=count++;  
		if(T->rchild!=NULL)
		inorder(T->rchild);
	}
}
void topview(BTPTR &T)
{
	int min,max,prevmin=count,prevmax=-1,flag=0;char value1,value2;
	enqueue(T);
	BTPTR dm=new(btnode),temp;
	dm->data='/';dm->lchild=NULL;dm->rchild=NULL;
	enqueue(dm);
	while(!qempty())
	{
		temp=dequeue();
		if(temp->data!='/')
		{	
			min=temp->x;
			value1=temp->data;
			if(temp->lchild!=NULL)
			enqueue(temp->lchild);
			if(temp->rchild!=NULL)
			enqueue(temp->rchild);
			temp=dequeue();
			while(temp->data!='/')
			{
				max=temp->x;
				value2=temp->data;
				if(temp->lchild!=NULL)
				enqueue(temp->lchild);
				if(temp->rchild!=NULL)
				enqueue(temp->rchild);
				temp=dequeue();
			}
			if(min<prevmin)
			{
				cout<<value1<<" ";
				prevmin=min;
			}
			if(max>prevmax)
			{
				if(flag!=0)
				cout<<value2<<" ";
				flag++;
				prevmax=max;
			}
			if(!qempty())
			enqueue(dm);
			else
			break;
		}
	}
}
int main()
{
	BTPTR T=NULL;q.front=-1;q.rear=-1;q.size=50;
	cout<<"enter the tree as string::";
	cin>>s;
	create(T);
	inorder(T);
	topview(T);
	return 0;
}
