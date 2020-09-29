#include<iostream>
using namespace std;
typedef struct btnode{
	struct btnode *firstchild;
	char data;
	struct btnode *nextsibling;
}*GTPTR;
void createsibling(GTPTR &T);
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
		cout<<"select the choice 1.firstchild 2.nextsibling 3.end::";
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
				break;
		}
	}
	return;
}
void createsibling(GTPTR &T)
{
	GTPTR temp=new(btnode),ptr=T;temp->firstchild=NULL;temp->nextsibling=NULL;
	cout<<"enter the element:";
	cin>>temp->data;
	if(T==NULL)
	T=temp;
	else
	{
		while(ptr->nextsibling!=NULL)
		ptr=ptr->nextsibling;
		ptr->nextsibling=temp;
	}
}
void print(GTPTR T,string s)
{
	if(T->firstchild==NULL && T->nextsibling==NULL)
	{
		s+=T->data;
		cout<<s<<endl;
		return;
	}
	else
	{
		if(T->firstchild!=NULL)
		{
			s+=T->data;
			print(T->firstchild,s);
		}
		else
		s+=T->data;
		if(T->nextsibling!=NULL)
		print(T->nextsibling,s);
	}
}
void preorder(GTPTR T)
{
	if(T==NULL)
	return ;
	cout<<T->data<<" ";
	preorder(T->firstchild);
	preorder(T->nextsibling);
}
int main()
{
	int ch=0;GTPTR T=NULL;string s1="";
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
//	print(T,s1);
	preorder(T);
	return 0;
}
