#include<iostream>
using namespace std;
typedef struct lnode{
	int data;
	struct lnode *link;
	struct lnode *next;
}*LPTR;
void addend(LPTR &L,int k)
{
	LPTR temp=new(lnode),ptr=L;
	temp->data=k;
	temp->link=NULL;
	temp->next=NULL;
	if(L==NULL)
	L=temp;
	else
	{
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=temp;
	}
}
void subroute(LPTR &L,int k)
{
	LPTR temp=new(lnode),ptr=L;
	temp->data=k;
	temp->link=NULL;
	temp->next=NULL;
	int ch=0,n;
	while(ch!=3)
	{
		cout<<"select 1.append 2.subroute 3.exit::";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter the data:";
				cin>>n;
				addend(temp->link,n);
				break;
			case 2:
				cout<<"enter the data:";
				cin>>n;
				subroute(L->link,n);
			default:
				break;
		}		
	}
	if(L==NULL)
	L=temp;
	else
	{
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=temp;
	}
}
void print(LPTR L)
{
	if(L==NULL)
	return;
	else
	{
		while(L!=NULL)
		{
			cout<<L->data<<" ";
			print(L->link);
			L=L->next;
		}
	}
}
int main()
{
	int ch=0,n;
	LPTR T=NULL;
	while(ch!=3)
	{
		cout<<"select 1.append 2.subroute 3.exit::";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter the data:";
				cin>>n;
				addend(T,n);
				break;
			case 2:
				cout<<"enter the data:";
				cin>>n;
				subroute(T,n);
				break;
			default:
				break;
		}
	}
	print(T);
	return 0;
}
