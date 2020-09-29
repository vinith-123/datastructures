#include<iostream>
using namespace std;
struct lnode{
	int data;
	struct lnode *next;
};
typedef struct lnode* lptr;
void addend(lptr &L,int k)
{
	lptr p,temp;
	temp=new(lnode);
	temp->data=k;
	temp->next=NULL;
	p=L;
	if(p==NULL)
	{
		L=temp;
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
}
void display(lptr &L)
{
	lptr p;
	p=L;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}
bool search(lptr &L,int k)
{
	lptr p;
	p=L;
	while(p!=NULL)
	{
		if(p->data==k)
		return true;
		p=p->next;
	}
	return false;
}
int main()
{
	lptr L1=NULL,L2=NULL,L3=NULL,t1=NULL,t2=NULL;
	int n,ele;
	cout<<"enter no of elements in list1:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		addend(L1,ele);
	}
	cout<<"enter no of elements in list2:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		addend(L2,ele);
	}
	t1=L1;
	while(t1!=NULL)
	{
	  if(!search(L2,t1->data))
		addend(L3,t1->data);
		t1=t1->next;	
	}
	t1=L1;
	while(t1!=NULL)
	{
		if(search(L2,t1->data))
		addend(L3,t1->data);
		t1=t1->next;
	}
	t2=L2;
	while(t2!=NULL)
	{
		if(!search(L1,t2->data))
		addend(L3,t2->data);
		t2=t2->next;
	}
	display(L3);
	return 0;
}
