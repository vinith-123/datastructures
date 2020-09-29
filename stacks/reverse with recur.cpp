#include<iostream>
using namespace std;
struct stack{
	int size;
	int top;
	int elements[50];
};
bool isfull(stack &s)
{
	if(s.top==s.size-1)
	return true;
	else
	return false;
}
bool isempty(stack &s)
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
	return 0;
	else
	return s.elements[s.top--];
}
void recur(stack &s,stack &temp)
{
	if(s.top==-1)
	{
		s=temp;
		return ;
	}
	else
	{
		temp.elements[++temp.top]=s.elements[s.top--];
		recur(s,temp);
	}
}
int main(){
	int n,ele;
	stack *s1,*s2,*temp;
	s1=new(stack);
	s2=new(stack);
	temp=new(stack);
	s1->size=50;s1->top=-1;
	s2->size=50;s2->top=-1;
	temp->size=50;temp->top=-1;
	cout<<"enter no of elements\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		push(*s1,ele);
		push(*s2,ele);
	}
	cout<<"original stack\n";
	for(int i=0;i<n;i++)
	{
		cout<<pop(*s2)<<" ";
	}
	cout<<endl;
	recur(*s1,*temp);
	s1=temp;
	cout<<"reversed stack\n";
	for(int i=0;i<n;i++)
	{
		cout<<pop(*s1)<<" ";
	}
	cout<<endl;
	return 0;
}
