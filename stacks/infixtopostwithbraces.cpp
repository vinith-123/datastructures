#include<iostream>
using namespace std;
struct stack{
	int size;
	int top;
	char elements[50];
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
void push(stack &s,char c)
{
	if(isfull(s))
	cout<<"error stack is full";
	else
	s.elements[++s.top]=c;
}
char pop(stack &s)
{
	if(isempty(s))
	cout<<"error stack is empty";
	else
	return s.elements[s.top--];
}
char peep(stack &s)
{
	if(isempty(s))
	cout<<"error stack is empty";
	else
	return s.elements[s.top];
}
int main()
{
	int n,index;char ch,ele;
	stack *s;
	s=new(stack);
	s->size=50;s->top=-1;
	cout<<"enter no of elements:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ch;
		if(ch=='('||ch=='{'||ch=='[')
		push(*s,ch);
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
		{
			push(*s,ch);
		}
		else if(ch==')'||ch=='}'||ch==']')
		{
			if(ch==')')
			{
				ele=pop(*s);
				while(ele!='(')
				{
					cout<<ele;
					ele=pop(*s);
				}
			}
			else if(ch=='}')
			{
				ele=pop(*s);
				while(ele!='{')
				{
					cout<<ele;
					ele=pop(*s);
				}
			}
			else if(ch==']')
			{
				ele=pop(*s);
				while(ele!='[')
				{
					cout<<ele;
					ele=pop(*s);
				}
			}
		}
		else
		{
			cout<<ch;
		}
	}
}
