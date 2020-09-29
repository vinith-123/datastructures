#include<iostream>
using namespace std;
string s1;
typedef struct btnode{
	struct btnode *lchild;
	char data;
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
void create(char ch)
{
     BTPTR T=new(btnode);
     T->data=ch;
     push(T);
     return;
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
int evaluate(BTPTR T)
{
	if(T!=NULL)
	{
		if(T->data=='+'||T->data=='-'||T->data=='*'||T->data=='/')
		{
			switch(T->data)
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
			return T->data-'0';
		}
	}
}
int main()
{
	BTPTR T=NULL;
	s.top=-1;s.size=50;
	cout<<"enter the postfix expression::";
	cin>>s1;
	for(int j=0;j<s1.length();j++)
	{
		if(s1[j]!='+'&&s1[j]!='-'&&s1[j]!='*'&&s1[j]!='/')
		create(s1[j]);
		else
		{
			BTPTR temp=new(btnode);
			temp->data=s1[j];
			temp->rchild=pop();
			temp->lchild=pop();
			push(temp);
		}
	}
	T=pop();
	cout<<evaluate(T)<<endl;
	return 0;
}

