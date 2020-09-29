#include<iostream>
#include<string>
using namespace std;
struct stack{
	int top;
	int size;
	string a[20];
};
bool sfull(stack s)
{
	return s.top==s.size-1?true:false;
}
bool sempty(stack s)
{
	return s.top==-1?true:false;
}
void push(stack &s,string str)
{
	if(sfull(s))
	cout<<"error stack is full\n";
	else
	s.a[++s.top]=str;
}
string pop(stack &s)
{
	if(sempty(s))
	cout<<"stack is empty\n";
	else
	return s.a[s.top--];
}
int main()
{
	string o1,o2,a,str="";
	stack *s;
	s=new(stack);
	s->size=20;s->top=-1;
	cout<<"enter the pre fix expression:";
	cin>>a;
	for(int i=a.length()-1;i>=0;i--)
	{
		if(a[i]=='+' ||a[i]=='-'||a[i]=='*'||a[i]=='/')
		{
			o1=pop(*s);
			o2=pop(*s);
			push(*s,o1+o2+a[i]);
		}
		else
		{
			str="";
			str=str+a[i];
			push(*s,str);
		}
	}
	str=pop(*s);
	cout<<str;
	return 0;
}
