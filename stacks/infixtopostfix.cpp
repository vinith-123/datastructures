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
	cout<<"error stack is full\n";
	else
	s.elements[++s.top]=c;
}
char pop(stack &s)
{
	if(isempty(s))
	{
		cout<<"error stack is empty";
		return 0;
	}
	else
	return s.elements[s.top--];
}
char peep(stack s)
{
	if(isempty(s))
	return -1;
	else
	return s.elements[s.top];
}
int main()
{
	stack *s;int n;char ch,ele;
	s=new(stack);
	s->size=50;s->top=-1;
	cout<<"enter no of elements:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ch;
		if(ch=='+'|| ch=='-'||ch=='*'||ch=='/' )
		{
			if(ch=='+'|| ch=='-')
			{
				while(s->top!=-1)
				{
					ele=pop(*s);
					cout<<ele;
				}
				push(*s,ch);
			}
			else
			{
				ele=peep(*s);
				if(ele=='+'||ele=='-')
				{
					push(*s,ch);
				}
				else
				{
					if(ele!=-1)
					cout<<pop(*s);
					push(*s,ch);
				}
			}
		}
		else
		cout<<ch;
	}
	while(s->top!=-1)
	cout<<pop(*s);
	return 0;
}
