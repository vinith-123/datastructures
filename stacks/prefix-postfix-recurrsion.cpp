#include<iostream>
using namespace std;
struct stack{
	int top;
	int size;
	string str[20];
}s;
bool sfull()
{
	return (s.top==s.size-1)?true:false;
}
bool sempty()
{
	return (s.top==-1)?true:false;
}
void push(string a)
{
	if(sfull())
	cout<<"error stack is full\n";
	else
	s.str[++s.top]=a;
}
string pop()
{
	if(sempty())
	cout<<"error stack is empty\n";
	else
	return s.str[s.top--];
}
void recur(string a,int index)
{
	string op1="",op2="";
	if(index==-1)
	return;
	else
	{
		if(a[index]=='+'||a[index]=='-'||a[index]=='*'||a[index]=='/')
		{
			op1=op1+pop();
			op2=op2+pop();
			push(op1+op2+a[index]);
			recur(a,--index);
		}
		else
		{
			push(op1+a[index]);
			recur(a,--index);
		}
	}
	
}
int main()
{
	s.size=20;s.top=-1;
	string a;int i;
	cout<<"enter the prefix expression::";
	cin>>a;i=a.length();
	recur(a,i-1);
	cout<<"post fix expression::"<<pop();
	return 0;
}
