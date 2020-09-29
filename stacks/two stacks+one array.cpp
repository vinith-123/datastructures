#include<iostream>
using namespace std;
struct stack{
	int top1,top2;
	int size;
	int elements[50];
}s;
bool sfull()
{
	return (s.top1+1==s.top2)?true:false;
}
bool sempty()
{
	return (s.top1==-1 && s.top2==s.size)?true:false;
}
void push1(int x)
{
	if(sfull())
	cout<<"error stack is full\n";
	else
	s.elements[++s.top1]=x;
}
void push2(int x)
{
	if(sfull())
	cout<<"error stack is full\n";
	else
	s.elements[--s.top2]=x;
}
int pop1()
{
	if(sempty())
	cout<<"error stack is empty\n";
	else
	return s.elements[s.top1--];
}
int pop2()
{
	if(sempty())
	cout<<"error stack is empty\n";
	else
	return s.elements[s.top2++];
}
int main()
{
	s.size=50;
	int ch,n,e=1;

	while(e!=0)	
	{
		cout<<"select your choice of stack 1.stack1 2.stack2";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"select the operation 1.push 2.pop::";
				cin>>ch;
				if(ch==1)
				{
					cout<<"enter the element::";
					cin>>n;
					push1(n);
				}
				else
				cout<<pop1()<<endl;
				break;
			default:
				cout<<"select the operation 1.push 2.pop::";
				cin>>ch;
				if(ch==1)
				{
					cout<<"enter the element::";
					cin>>n;
					push2(n);
				}
				else
				cout<<pop2()<<endl;
				break;
		}
		cout<<"if you want to exit enter 0";
		cin>>e;
	}
	return 0;
}
