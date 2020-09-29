#include<iostream>
using namespace std;
struct stack{
	int top;
	int size;
	char elements[50];
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
void push(stack &s,char x)
{
	if(isfull(s))
	return;
	else
	s.elements[++s.top]=x;
}
char pop(stack &s)
{
	if(isempty(s))
		return 0;
	else
	return s.elements[s.top--];
}
int main()
{
	stack *s;int n,index;char ch,ele;
	char opensymbol[3]={'(','{','['},closesymbol[3]={')','}',']'};
	s=new(stack);
	s->top=-1;s->size=50;
	cout<<"enter the no of elements in expression:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ch;
		if(ch==opensymbol[0] || ch== opensymbol[1] || ch==opensymbol[2])
		push(*s,ch);
		else if(ch == closesymbol[0] || ch==closesymbol[1] || ch==closesymbol[2])
		{
			if(ch==closesymbol[0])index=0;
			else if(ch ==closesymbol[1])index=1;
			else index=2;
			ele=pop(*s);
			if(ele!=opensymbol[index])
			{
				cout<<"not balanced\n";
				return 0;
			}
		}
	}
	if(isempty(*s))
	cout<<"balanced\n";
	else
	cout<<"not balanced\n";
	return 0;
}
