#include<iostream>
using namespace std;
typedef struct btnode
{
	struct btnode *lchild;
	char data;
	struct btnode *rchild;
}*BTPTR;
struct stack{
	BTPTR elements[50];
	int top;
	int size;
}s1,s2;
void push(stack &s,BTPTR T)
{
	s.elements[++s.top]=T;
}
BTPTR pop(stack &s)
{
	return s.elements[s.top--];
}
BTPTR peep(stack s)
{
	return s.elements[s.top];
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
void postorder(BTPTR T)
{
	if(T==NULL)
	return;
	else
	{
		postorder(T->lchild);
		postorder(T->rchild);
		cout<<T->data<<" ";
	}
}
void iterative_postorder(BTPTR T)
{
	push(s1,T);push(s2,T);
	if(T->rchild!=NULL)push(s2,T->rchild);
	if(T->lchild!=NULL)push(s2,T->lchild);
	while(s2.top!=-1)
	{
		T=peep(s2);
		if(T->data==peep(s1)->data)
		{
			cout<<pop(s2)->data<<" ";
			pop(s1);
		}
		else if(T->lchild!=NULL || T->rchild!=NULL)
		{
			push(s1,T);
			if(T->rchild!=NULL)
			push(s2,T->rchild);
			if(T->lchild!=NULL)
			push(s2,T->lchild);
		}
		else
		{
			T=pop(s2);
			cout<<T->data<<" ";
		}
	}
}
int main()
{
	BTPTR T=NULL;s1.size=50;s1.top=-1;s2.size=50;s2.top=-1;
	q.front=-1;q.rear=-1;q.size=50;
	cout<<"enter the tree as string:";
	cin>>s;
	create(T);
	cout<<"postorder ::";
	postorder(T);
	cout<<endl;
	cout<<"post_order iterative:";
	iterative_postorder(T);
	cout<<endl;
	return 0;
}
