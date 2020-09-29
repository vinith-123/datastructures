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
void insertionsort(lptr &L)
{
	lptr ptr,temp1,temp2;
	int ele,n=0;
	ptr=L->next;
	while(ptr!=NULL)
	{
		temp2=ptr;
		ele=ptr->data;
		temp1=L;
		while(temp1->next!=temp2)
		temp1=temp1->next;
		while(temp1->data > ele && temp2!=L)
		{
			temp2->data=temp1->data;
			temp2=temp1;
			temp1=L;
			while(temp1->next!=temp2 && temp2!=L)
			temp1=temp1->next;
		}
		temp2->data=ele;
		ptr=ptr->next;
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
	insertionsort(L);
	display(L);
	return 0;
}
