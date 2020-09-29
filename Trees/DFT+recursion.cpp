#include<iostream>
using namespace std;
typedef struct btnode{
	struct btnode *firstchild;
	char data;
	struct btnode *nextsibling;
}*GTPTR;
void createsibling(GTPTR &T);
void print(GTPTR T);
void createchild(GTPTR &T)
{
	T->firstchild=new(btnode);
	T->firstchild->firstchild=NULL;
	T->firstchild->nextsibling=NULL;
	cout<<"enter the element:";
	cin>>T->firstchild->data;
	int ch=0;
	while(ch!=3)
	{
		cout<<"select the choice 1.firstchild 2.nextsibling 3.exit::";
		cin>>ch;
		switch(ch)
		{
			case 1:
				createchild(T->firstchild);
				break;
			case 2:
				createsibling(T->firstchild);
				break;
			default:
				return;
		}
	}
	return;
}
void createsibling(GTPTR &T)
{
	GTPTR temp=new(btnode),ptr=T;temp->firstchild=NULL;temp->nextsibling=NULL;
	cout<<"enter the element:";
	cin>>temp->data;
	if(T->nextsibling==NULL)
	T->nextsibling=temp;
	else
	{
		while(ptr->nextsibling!=NULL)
		ptr=ptr->nextsibling;
		ptr->nextsibling=temp;
	}
}
void print(GTPTR T)
{
	if(T!=NULL)
	{
		if(T->firstchild==NULL && T->nextsibling==NULL)
		{
			cout<<T->data<<" ";
			return;
		}
		else
		{
				cout<<T->data<<" ";
				print(T->firstchild);
				while(T!=NULL)
				{
					cout<<T->data<<" ";
					T=T->nextsibling;
				}
		}		
	}
}
int main()
{
	int ch=0;GTPTR T=NULL;
	T=new(btnode);T->firstchild=NULL;T->nextsibling=NULL;
	cout<<"enter the element:";
	cin>>T->data;
	while(ch!=3)
	{
		cout<<"select the choice 1.firstchild 2.nextsibling 3.end::";
		cin>>ch;
		switch(ch)
		{
			case 1:
				createchild(T);
				break;
			case 2:
				createsibling(T);
				break;
			default:
				break;
		}
	}	
	print(T);
	return 0;
}
