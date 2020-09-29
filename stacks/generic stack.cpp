#include<iostream>
using namespace std;
union u1{
	int a;
	float f;
	char c;
};
struct stack{
	int size;
	int top;
	int tag[10];
	union u1 b[10];
};
bool isempty(stack &s)
{
	if(s.top==-1)
	return true;
	else
	return false;
}
bool isfull(stack &s)
{
	if(s.top==s.size-1)
	return true;
	else
	return false;
}
void push(stack &s,int tag)
{
	if(tag==1)
	{
		if(isfull(s))
		cout<<"error stack is full\n";
		else
		{
			cout<<"enter integer:";
			cin>>s.b[++s.top].a;
		}
	}
	else if(tag==2)
	{
		if(isfull(s))
		cout<<"error stack is full\n";
		else
		{
			cout<<"enter floating point:";
			cin>>s.b[++s.top].f;
		}
	}
	else
	{
		if(isfull(s))
		cout<<"error stack is full\n";
		else
		{
			cout<<"enter character:";
			cin>>s.b[++s.top].c;
		}
	}
}
void pop(stack &s)
{
	switch(s.tag[s.top])
	{
		case 1:
			cout<<s.b[s.top--].a<<"\n";
			break;
		case 2:
			cout<<s.b[s.top--].f<<"\n";
			break;
		default:
			cout<<s.b[s.top--].c<<"\n";
			break;
	}
}
int main()
{
	stack *s;int n,i;
	s=new(stack);
	s->top=-1;s->size=10;
	cout<<"enter no of elements:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"select your entry type 1.integer 2.float 3.character::";
		cin>>s->tag[i];
		switch(s->tag[i])
		{
			case 1:
				push(*s,s->tag[i]);
				break;
			case 2:
				push(*s,s->tag[i]);
				break;
			default:
				push(*s,s->tag[i]);
				break;
		}	
	}
	while(s->top!=-1)
	{
		pop(*s);
	}
	return 0;
}
