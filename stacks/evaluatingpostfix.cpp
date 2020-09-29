#include<iostream>
using namespace std;
struct stack{
	int size;
	int top;
	int elements[50];
};
bool isfull(stack s)
{
	if(s.top==s.size-1)
	return true;
	else
	return false;
}
bool isempty(stack s)
{
	if(s.top==-1)
	return true;
	else
	return false;
}
void push(stack &s,int x)
{
	if(isfull(s))
	cout<<"stack full\n";
	else
	s.elements[++s.top]=x;
}
int pop(stack &s)
{
	if(isempty(s))
	return -1;
	else
	return s.elements[s.top--];
}
int main()
{
	int n,a,b,ele;char ch;
	stack *s;
	s=new(stack);
	s->size=50;s->top=-1;
	cout<<"enter length of expression to be evaluated:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ch;
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%')
		{
			b=pop(*s);
			a=pop(*s);
			if(ch=='+')
			{
				a=a+b;
				push(*s,a);
			}
			else if(ch=='-')
			{
				a=a-b;
				push(*s,a);
			}
			else if(ch=='*')
			{
				a=a*b;
				push(*s,a);
			}
			else
			{
				a=a%b;
				push(*s,a);
			}	
		}
		else
		{
			ele=(int)ch-48;
			push(*s,ele);
		}	
	}
	cout<<"="<<pop(*s)<<"\n";
	return 0;
}
