#include<iostream>
using namespace std;
struct stack{
	int top;
	int size;
	int elements[50];
};
bool sfull(stack s)
{
	return (s.top==s.top-1)?true:false;
}
bool sempty(stack s)
{
	return (s.top==-1)?true:false;
}
void push(stack &s,int x)
{
	if(sfull(s))
	cout<<"error stack is full:(";
	else
	s.elements[++s.top]=x;
}
int pop(stack &s)
{
	if(sempty(s))
	cout<<"error stack is empty:(";
	else
	return s.elements[s.top--];
}
int main()
{
	stack *s1,*s2;int n,temp1,temp2;
	s1=new(stack);s2=new(stack);
	s1->top=-1;s2->top=-1;
	s1->size=50;s2->size=50;
	cout<<"enter no of elements:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp1;
		push(*s1,temp1);
	}
	for(int i=0;i<n;i++)
	{
		temp1=pop(*s1);
		while(s1->top!=i-1)
		{
			temp2=pop(*s1);
			if(temp2>temp1)
			{
				n=temp1;
				temp1=temp2;
				temp2=n;
			}
			push(*s2,temp2);
		}
		push(*s1,temp1);
		while(s2->top!=-1)
		push(*s1,pop(*s2));
	}
	cout<<"sorted order using only two stacks:) ";
	while(s1->top!=-1)
	cout<<pop(*s1)<<" ";
	return 0;	
}
