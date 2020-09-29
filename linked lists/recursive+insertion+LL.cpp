#include<iostream>
using namespace std;
typedef struct lnode{
	int data;
	struct lnode *next;
}*lptr;
void addend(lptr &L,int k)
{
	lptr p,temp;
	temp=new(lnode);
	temp->data=k;
	temp->next=NULL;
	p=L;
	if(p==NULL)
	L=temp;
	else
	{
		while(p->next!=NULL)
		p=p->next;
		p->next=temp;
	}
}
void display(lptr L)
{
	while(L!=NULL)
	{
		cout<<L->data<<" ";
		L=L->next;
	}
}
void insertionsort(lptr &L,lptr ptr)
{
	if(ptr==NULL)
	return;
	else
	{
		lptr ptr1=L;int ele=ptr->data;
		while(ptr1->next!=ptr)
		ptr1=ptr1->next;
		while(ptr1->data > ele && ptr1!=NULL)
		{
			ptr->data=ptr1->data;
			ptr=ptr1;
			ptr1=L;
			while(ptr1->next!=ptr && ptr1!=NULL)
			ptr1=ptr1->next;
		}
		ptr=ptr->next;
		insertionsort(L,ptr);
	}
}
int main()
{
	lptr L=NULL;
	int n,k;
	cout<<"enter no of elements:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		addend(L,k);
	}
	insertionsort(L,L->next);
	display(L);
	return 0;
}
