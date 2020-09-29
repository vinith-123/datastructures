#include<iostream>
using namespace std;
typedef struct lnode{
	int data;
	struct lnode *next;
}*lptr;
lptr top=NULL;
void push(int x)
{
	lptr temp;
	temp=new(lnode);
	temp->data=x;
	temp->next=top;
	top=temp;
}
int pop()
{
	if(top==NULL)
	{
		cout<<"error no elements in stack:(";
		return -1;
	}
	else
	{
		int x;
		x=top->data;
		top=top->next;
		return x;
	}
}
int main()
{
	int ele,n;
	cout<<"enter no of elements:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		push(ele);
	}
	while(top!=NULL)
	cout<<pop()<<" ";
	return 0;
}
