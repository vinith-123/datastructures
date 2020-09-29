#include<iostream>
using namespace std;
typedef struct lnode{
	int data;
	struct lnode *next;
}*lptr;
void addend(lptr &l,int k)
{
	lptr p,temp;
	temp=new(lnode);
	temp->data=k;
	temp->next=NULL;
	p=l;
	if(p==NULL)
	l=temp;
	else
	{
		while(p->next!=NULL)
		p=p->next;
		p->next=temp;
	}
}
void display(lptr &l)
{
	if(l==NULL)
	cout<<"no elements to dispaly\n";
	else
	{
		while(l!=NULL)
		{
			cout<<l->data<<" ";
			l=l->next;
		}
	}
}
void meargesort(lptr &L3,lptr &L1,lptr &L2)
{
	int ele;
	while(L1!=NULL && L2!=NULL)
	{
		if(L1->data > L2->data)
		{
			addend(L3,L2->data);
			L2=L2->next;
		}
		else
		{
			addend(L3,L1->data);
			L1=L1->next;
		}
	}
	if(L1==NULL)
	{
		while(L2!=NULL)
		{
			addend(L3,L2->data);
			L2=L2->next;
		}
		return;
	}
	else
	{
		while(L1!=NULL)
		{
			addend(L3,L1->data);
			L1=L1->next;
		}
	}
}
int main()
{
	lptr L1=NULL,L2=NULL,L3=NULL;
	int n,ele;
	cout<<"enter the no of elements in 1st LL:";
	cin>>n;
	cout<<"enter the sorted list1::";
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		addend(L1,ele);
	}
	cout<<"enter the no of elements in 2nd LL:";
	cin>>n;
	cout<<"enter the sorted list2::";
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		addend(L2,ele);
	}
	meargesort(L3,L1,L2);
	display(L3);
	return 0;
}
