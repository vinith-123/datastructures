#include<iostream>
using namespace std;
union u1{
	int  c;
	struct lnode *link;
};
typedef struct lnode{
	int tag;
	u1 u;
	struct lnode *next;
}*lptr;
void append(lptr &l,int x)
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
int search1(lptr l,int x)
{
	int flag=0;
	while(l!=NULL)
	{
		if(l->tag==1)
		{
			if(l->u.c==x)
				return 1;
		}
		else
		return search1(l->u.link,x);
		l=l->next;
	}
	return 0;
}
int search2(lptr l,int a[],int n)
{
	int count=0,i=0;lptr temp;
	while(l!=NULL)
	{
		if(l->tag==1)
		{
			count++;
			if(count==1)
			temp=
			l=l->next;
		}
		if(count==n)
		{
			i=0;
			for(int j=0;j<n;j++)
			{
				if(temp->u.c==a[i++])
				temp=temp->next;
				else
				break;
			}
		}
		else
	}
}
void sublist(lptr &l)
{
	lptr ptr=l,temp=new(lnode);
	temp->tag=2;
	temp->next=NULL;
	temp->u.link=NULL;
    int ch=0,s,c;
	while(ch!=4)
	{
		cout<<"select the operation:1.integer 2.sub-list 3.search 4.exit::";
		cin>>ch;
		if(ch==1)
		{
			cout<<"enter the integer";
			cin>>c;
			append(temp->u.link,c);
		}
		else if(ch==2)
		sublist(temp->u.link);
		else if(ch==3)
		{
			cout<<"select search type:1.integer search 2.list search::";
			cin>>ch;
			if(ch==1)
			{
				cout<<"enter the number to be searched:";
				cin>>s;
				search1(l,s);
			}
			else
			{
				cout<<"enter no of items in the list:";
				cin>>s;
				int a[s];
				cout<<"enter the list to be searched:";
				for(int i=0;i,s;i++)
				cin>>a[i];
				if(search2(l,a,s))
				cout<<"found!\n";
				else
				cout<<"not found:(\n";	
			}
		}
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
	int ch=0,s, c;
	while(ch!=4)
	{
		cout<<"select the operation:1.integer 2.sub-list 3.search 4.exit::";
		cin>>ch;
		if(ch==1)
		{
			cout<<"enter the integer:";
			cin>>c;
			append(L,c);
		}
		else if(ch==2)
		sublist(L);
		else if(ch==3)
		{
			cout<<"select search type:1.integer search 2.list search::";
			cin>>ch;
			if(ch==1)
			{
				cout<<"enter the number to be searched:";
				cin>>s;
				if(search1(L,s))
				cout<<"found!";
				else
				cout<<"not found:(\n";
			}
			else
			{
				cout<<"enter no of items in the list:";
				cin>>s;
				int a[s];
				cout<<"enter the list to be searched:";
				for(int i=0;i,s;i++)
				cin>>a[i];
				if(search2(L,a,s))
				cout<<"found!\n";
				else
				cout<<"not found:(\n";
			}
		}
		else
		break;
	}
	return 0;
}
