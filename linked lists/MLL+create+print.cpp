#include<iostream>
using namespace std;
union u1{
	char c;
	struct lnode *link;
};
typedef struct lnode{
	int tag;
	u1 u;
	struct lnode *next;
}*lptr;
void append(lptr &l,char x)
{
	lptr ptr=l,temp=new(lnode);
	temp->tag=1;
	temp->u.c=x;
	temp->next=NULL;
	if(ptr==NULL)
	l=temp;
	else
	{
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=temp;
	}
}
void sublist(lptr &l)
{
	lptr ptr=l,temp=new(lnode);
	temp->tag=2;
	temp->next=NULL;
	temp->u.link=NULL;
    int ch=0;char c;
	while(ch!=3)
	{
		cout<<"select the operation:1.character 2.sub-list 3.exit::";
		cin>>ch;
		if(ch==1)
		{
			cout<<"enter the character:";
			cin>>c;
			append(temp->u.link,c);
		}
		else if(ch==2)
		sublist(temp->u.link);
		else
		break;
	}	
	if(l==NULL)
	l=temp;
	else
	{
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=temp;
	}
}
void print(lptr l)
{
	while(l!=NULL)
	{
		if(l->tag==1)
		cout<<l->u.c<<" ";
		else
		{
			print(l->u.link);
		}
		l=l->next;
	}
}
int main()
{
	lptr L=NULL;
	int ch=0;char c;
	while(ch!=3)
	{
		cout<<"select the operation:1.character 2.sub-list 3.exit::";
		cin>>ch;
		if(ch==1)
		{
			cout<<"enter the character:";
			cin>>c;
			append(L,c);
		}
		else if(ch==2)
		sublist(L);
		else
		break;
	}
	print(L);
	return 0;
}
