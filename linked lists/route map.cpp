#include<iostream>
using namespace std;
typedef struct lnode{
	int data;
	struct lnode *link;
	struct lnode *next;
}*lptr;
void append(lptr &l);
void addend(lptr &l)
{
	int n;
	lptr ptr=l,temp=new(lnode);
	cout<<"enter the integer:";
	cin>>n;
	temp->data=n;
	temp->link=NULL;
	temp->next=NULL;
	l=temp;
	while(1)
	{
		int ch;
		cout<<"enter choice 1. sublist 2.append 3.exit:";
		cin>>ch;
		if(ch==1)
		{
			lptr temp1=new(lnode);
			cout<<"enter the integer:";
			cin>>n;
			temp1->data=n;
			temp1->link=NULL;
			temp1->next=NULL;
			addend(temp1->link);
		}
		if(ch==2)
		append(l);
		else
		break;
	}
	return;
}
void append(lptr &l)
{
	int n;
	lptr ptr=l,temp=new(lnode);
	cout<<"enter the integer:";
	cin>>n;
	temp->data=n;
	temp->link=NULL;
	temp->next=NULL;
	if(ptr==NULL)
	l=temp;
	else
	{
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=temp;
	}
	while(1)
	{
		int ch;
		cout<<"enter choice 1. sublist 2.append 3.exit:";
		cin>>ch;
		if(ch==1)
		{
			
			lptr temp1=new(lnode);
			cout<<"enter the integer:";
			cin>>n;
			temp1->data=n;
			temp1->link=NULL;
			temp1->next=NULL;
			addend(temp1->link);
		}
		if(ch==2)
		append(l);
		else
		break;
	}
	return;
}
int main()
{
	lptr L=NULL,ptr,temp;
	int ch,n;
	while(1)
	{
		cout<<"enter choice 1. sublist 2.append 3.exit:";
		cin>>ch;
		if(ch==1)
		{
			temp=new(lnode);
			cout<<"enter the integer:";
			cin>>n;
			temp->data=n;
			temp->link=NULL;
			temp->next=NULL;
			addend(temp->link);
		}
		if(ch==2)
		append(L);
		else
		break;
	}
return 0;	
}
