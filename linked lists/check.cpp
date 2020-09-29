#include<iostream>
#include<cmath>
using namespace std;
typedef struct btnode{
	struct btnode *lchild;
	char data;
	struct btnode *rchild;
}*BTPTR;
struct stack{
	int top;
	int size;
	BTPTR elements[50];
};
void push(BTPTR &T,stack &st)
{
	st.elements[++st.top]=T;
}
BTPTR pop(stack &st)
{
	return st.elements[st.top--];
}
string s;int i=0;
int height(BTPTR T)
{
	if(T==NULL)
	return -1;
	else
	return 1+max(height(T->lchild),height(T->rchild));
}
bool balanced(BTPTR T)
{
	return (abs(height(T->lchild)-height(T->rchild))<=1)?true:false;
}
void avlcheck(stack &st,BTPTR &T);
void createavl(BTPTR &T,stack &st)
{
	BTPTR ptr=T,t;
	if(i!=s.length())
	{
		if(s[i]!='.')
		{
			while(1)
			{
				if(ptr==NULL)
				{
					BTPTR temp=new(btnode);
					temp->lchild=NULL;
					temp->rchild=NULL;
					temp->data=s[i++];
					if(t->data > temp->data)
					t->lchild=temp;
					else
					t->rchild=temp;
					avlcheck(st,T);
					createavl(T,st);
					return;
				}
				else
				{
					if(ptr->data<s[i])
					{
						push(ptr,st);
						t=ptr;
						ptr=ptr->rchild;
					}
					else
					{
						push(ptr,st);
						t=ptr;
						ptr=ptr->lchild;
					}
				}	
			}
		}
		else
		{
			i++;
			createavl(T,st);
			return;
		}
	}
}
void avlcheck(stack &st,BTPTR &T)
{
	BTPTR t;
	BTPTR ptr;
	while(st.top!=-1)
	{
		ptr=pop(st);
		if(balanced(ptr))
		continue;
		else
		{
			if(ptr->rchild!=NULL && ptr->rchild->rchild!=NULL)
			{
			
				if(st.top!=-1)
				{
					t=ptr->rchild;
					ptr->rchild=t->lchild;
					t->lchild=ptr;
					pop(st)->rchild=t;
				}
				else
				{
					t=T->rchild;
					T->rchild=t->lchild;
					t->lchild=T;
					T=t;
				}
			}
			else if(ptr->lchild!=NULL && ptr->lchild->lchild!=NULL)
			{
				if(st.top!=-1)
				{
					t=ptr->lchild;
					ptr->lchild=t->rchild;
					t->rchild=ptr;
					pop(st)->lchild=t;
				}
				else
				{
					t=T->lchild;
					T->lchild=t->rchild;
					T=t;
				}
			}
			else if(ptr->lchild!=NULL && ptr->lchild->rchild!=NULL)
			{
				BTPTR k1,k2,k3;
				if(st.top!=-1)
				{
					k3=ptr;k1=ptr->lchild;k2=k1->rchild;
					k1->lchild=k2->rchild;
					k3->rchild=k2->lchild;
					k2->rchild=k1;k2->lchild=k3;
					t=pop(st);
					if(t->data<k2->data)
					t->rchild=k2;
					else
					t->lchild=k2;
				}
				else
				{
					k3=ptr;k1=ptr->lchild;k2=k1->rchild;
					k1->rchild=k2->lchild;
					k3->lchild=k2->rchild;
					k2->lchild=k1;k2->rchild=k3;
					T=k2;
				}
			}
			else
			{
				BTPTR k1,k2,k3;
				if(st.top!=-1)
				{
					k1=ptr;k3=ptr->rchild;k2=k3->lchild;
					k1->rchild=k2->lchild;
					k3->lchild=k2->rchild;
					k2->lchild=k1;k2->rchild=k3;
					t=pop(st);
					if(t->data<k2->data)
					t->rchild=k2;
					else
					t->lchild=k2;
				}
				else
				{
					k1=ptr;k3=ptr->rchild;k2=k3->lchild;
					k1->rchild=k2->lchild;
					k3->lchild=k2->rchild;
					k2->lchild=k1;k2->rchild=k3;
					T=k2;
				}
			}
		}
	}
}
void preorder(BTPTR T)
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
int main()
{
	stack *st;
	st=new(stack);
	st->size=50;st->top=-1;
	BTPTR T=new(btnode);
	cout<<"enter tree as string:";
	cin>>s;
	T->data=s[i++];
	T->lchild=NULL;T->rchild=NULL;
	createavl(T,*st);
	preorder(T);
}
