#include<iostream>
using namespace std;
typedef struct btnode
{
	struct btnode *lchild;
	char data;
	struct btnode *rchild;
}*BTPTR;
struct queue{
	BTPTR elements[50];
	int front;
	int rear;
	int size;
}q;
bool qfull()
{
	return (q.rear+1)%(q.size)==q.front?true:false;
}
bool qempty()
{
	return (q.front==-1)?true:false;
}
void enqueue(BTPTR  T)
{
	if(qfull())
	cout<<"error queue is full\n";
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
	int index;
	if(qempty())
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
string s;
static int i=0;
void create(BTPTR &T)
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
void preorder(BTPTR &T)
{
	if(T==NULL)
	return;
	else
	{
		cout<<T->data<<" ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
void subtree(BTPTR &T)
{
	if(T!=NULL)
	{
		preorder(T);
		cout<<endl;
		if(T->lchild!=NULL)
		subtree(T->lchild);
		if(T->rchild!=NULL)
		subtree(T->rchild);
		return ;
	}
	return;
}
int main()
{
	BTPTR T=NULL;
	q.front=-1;q.rear=-1;q.size=50;
	cout<<"enter the tree as string:";
	cin>>s;
	create(T);
	cout<<"ALL SUBTREES\n";
	subtree(T);
	cout<<endl;
	cout<<endl;
	return 0;
}
