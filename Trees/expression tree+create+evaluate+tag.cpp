#include<iostream>
using namespace std;
union u{
	char c;
	int n;
};
struct arr{
	int tag;
	union u e;
}a[50];
typedef struct btnode{
	struct btnode *lchild;
	arr data;
	struct btnode *rchild;
}*BTPTR;
struct stack{
	int top;
	int size;
	BTPTR elements[50];
}s;
bool sfull()
{
	return (s.top==s.size-1)?true:false;
}
bool sempty()
{
	return (s.top==-1)?true:false;
}
void push(BTPTR ch)
{
	if(sfull())
	cout<<"stack overflow\n";
	else
	s.elements[++s.top]=ch;
}
BTPTR pop()
{
	if(sempty())
	cout<<"stack underflow\n";
	else
	return s.elements[s.top--];
}
BTPTR peep()
{
	if(sempty())
	cout<<"stack underflow\n";
	else
	return s.elements[s.top];
}
void create(arr ch)
{
     BTPTR T=new(btnode);
     T->data.tag=1;
     T->data.e.n=ch.e.n;
     push(T);
     return;
}
int evaluate(BTPTR T)
{
	if(T!=NULL)
	{
		if(T->data.tag==1)
		{
			switch(T->data.e.c)
			{
				case '+':
					return evaluate(T->lchild)+evaluate(T->rchild);
					break;
				case '-':
					return evaluate(T->lchild)-evaluate(T->rchild);
					break;
				case '*':
					return evaluate(T->lchild)*evaluate(T->rchild);
					break;
				default:
					return evaluate(T->lchild)/evaluate(T->rchild);
			}
		}
		else
		{
			return T->data.e.n;
		}
	}
}
int main()
{
	BTPTR T=NULL,temp1,temp2;
	s.top=-1;s.size=50;
	int t,i=0,j;
	while(1)
	{
		cout<<"enter the choice 0.integer 1.character 2.exit::";
		cin>>t;
		if(t==0)
		{
			a[i].tag=0;
			cout<<"enter the integer::";
			cin>>a[i].e.n;
		}
		else if(t==1)
		{
			a[i].tag=1;
			cout<<"enter the character::";
			cin>>a[i].e.c;
		}
		else
		break;
	}
	for(j=0;j<i;j++)
	{
		if(a[j].tag==0)
		create(a[j]);
		else
		{
			BTPTR temp=new(btnode);
			temp->data.tag=a[j].tag;
			temp->data.e.c=a[j].e.c;
			temp->rchild=pop();
			temp->lchild=pop();
			push(temp);
		}
	}
	T=pop();
	cout<<evaluate(T)<<endl;
	return 0;
}

