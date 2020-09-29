#include<iostream>
using namespace std;
struct stack{
	int top;
	int size;
	char elements[50];
};
bool sfull(stack s)
{
	return (s.top==s.size-1)?true:false;
}
bool sempty(stack s)
{
	return (s.top==-1)?true:false;
}
void push(stack &s,char c)
{
	if(sfull(s))
	cout<<"error stack is full\n";
	else
	s.elements[++s.top]=c;
}
char pop(stack &s)
{
	if(sempty(s))
	cout<<"error stack is empty\n";
	else
	return s.elements[s.top--];
}
int main()
{
	stack *s;unsigned char ch,c1,c2,temp;int op1,op2;
	string str;
	s=new(stack);
	s->size=50;s->top=-1;
	cout<<"enter the infix expression with braces::";
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		ch=str[i];
		if(ch==')')
		{
			c2=pop(*s);
			op2=c2-48;
			ch=pop(*s);
			c1=pop(*s);
			op1=c1-48;
			switch(ch)
			{
				case '+':
					temp=pop(*s);
					push(*s,op1+op2+48);
					break;
				case '-':
					temp=pop(*s);
					push(*s,op1-op2+48);
					break;
				case '*':
					ch=pop(*s);
					push(*s,op1*op2+48);
					break;
				default:
					ch=pop(*s);
					push(*s,op1/op2+48);
					break;
			}
		}
		else
		{		
			push(*s,ch);
		}
	}
	ch=pop(*s);
	op1=ch-48;
	cout<<op1;
	return 0;
}
