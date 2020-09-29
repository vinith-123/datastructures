#include<iostream>
using namespace std;
struct stack{
	int top;
	int size;
	int elements[50];
};
bool sfull(stack s)
{
	return (s.top==s.size-1)?true:false;
}
bool sempty(stack s)
{
	return (s.top==-1)?true:false;
}
void push(stack &s,int x)
{
	if(sfull(s))
	cout<<"stack overflow:(\n";
	else
	s.elements[++s.top]=x;
}
int pop(stack &s)
{
	if(sempty(s))
	cout<<"stack underflow:(\n";
	else
	return s.elements[s.top--];
}
int peep(stack s)
{
	if(sempty(s))
	cout<<"stack underflow:(\n";
	else
	return s.elements[s.top];
}
int main()
{
	stack *s1=new(stack),*s2=new(stack);
	s1->top=-1;s2->top=-1;
	s1->size=50;s2->size=50;
	int n,ele,flag=0;
	cout<<"enter the no of elements in 1st LL:";
	cin>>n;
	cout<<"enter elements of list:";
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		push(*s1,ele);
	}
	cout<<"enter no of elements of 2nd LL:";
	cin>>n;
	for(int j=0;j<n;j++)
	{
		cin>>ele;
		push(*s2,ele);
	}
	if(peep(*s1)==peep(*s2))
	{
		while(s1->top!=-1 && s2->top!=-1)
		{
			if( peep(*s1)==peep(*s2))
			{
				ele=pop(*s1);
				ele=pop(*s2);
				flag++;
			}
			else
			break;
		}
		if( flag > 0 )
		cout<<"common element::"<<ele<<endl;
		else
		cout<<"no common point"<<endl;
	}
	else
	cout<<"no common point\n";
	return 0;
}
