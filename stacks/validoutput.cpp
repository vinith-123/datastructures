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
	cout<<"error stack is full\n";
	else
	s.elements[++s.top]=x;
}
int pop(stack &s)
{
	if(isempty(s))
	cout<<"error stack is empty1\n";
	else
	return s.elements[s.top--];
}
int peep(stack &s)
{
	if(isempty(s))
	cout<<"error stack is empty2\n";
	else
	return s.elements[s.top];
}
int main()
{
	stack *s;
	s=new(stack);
	s->size=50;
	s->top=-1;
	int n,ele,j=0,i;
	cout<<"enter no of elements:";
	cin>>n;
	int output[n],input[n];
	cout<<"enter the input sequence:";
	for( i=0;i<n;i++)
	cin>>input[i];
	cout<<"enter the output sequence:";
	for( i=0;i<n;i++)
		cin>>output[i];
	for(i=0;i<n;)
	{
		if(input[i]==output[j])
		{
			ele=peep(*s);
			while(ele==output[++j])
			{
				ele=pop(*s);
				if(s->top!=-1)
				ele=peep(*s);
			}
			i++;
		}
		else
		{
			push(*s,input[i]);
			i++;
		}
	}
	while(s->top!=-1)
	{
		ele=pop(*s);
		if(ele!=output[j++])
		break;
	}
	if(s->top==-1)
	cout<<"valid output\n";
	else
	cout<<"invalid input\n";
	return 0;
}
