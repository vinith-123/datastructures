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
void inorder(BTPTR T)
{
	if(T==NULL)
	return;
	else
	{
		inorder(T->lchild);
		cout<<T->data<<" ";
		inorder(T->rchild);
	}
}
void iterative_inorder(BTPTR T)
{
	BTPTR ptr;
	while(T!=NULL)
	{
		push(s1,T);
		T=T->lchild;
	}
	while(s1.top!=-1)
	{
		T=pop(s1);
		cout<<T->data<<" ";
		ptr=T->rchild;
		while(ptr!=NULL)
		{
			push(s1,ptr);
			ptr=ptr->lchild;
		}
	}
}
int main()
{
	BTPTR T=NULL;s1.size=50;s1.top=-1;s2.size=50;s2.top=-1;
	cout<<"enter the tree as string:";
	cin>>s;
	create(T);
	cout<<"inorder ::";
	inorder(T);
	cout<<"iterative_inorder::";
	iterative_inorder(T);
	cout<<endl;
	return 0;
}
