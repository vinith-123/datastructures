#include<iostream>
using namespace std;
typedef struct lnode{
	int coeff;
	int power;
	struct lnode *next;
}*lptr;
void addend(lptr &L,int c,int p)
{
	lptr temp,ptr;
	ptr=L;
	temp=new(lnode);
	temp->coeff=c;
	temp->power=p;
	temp->next=NULL;
	if(ptr==NULL)
		L=temp;
	else
	{
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=temp;
	}
}
void display(lptr L)
{
	if(L==NULL)
	cout<<"error list is empty:(";
	else
	{
		while(L!=NULL)
		{
			cout<<L->coeff<<" "<<L->power<<endl;
			L=L->next;
		}
	}
}
void addpoly(lptr l1,lptr l2,lptr &l3)
{
	lptr temp=NULL;
	while(l1!=NULL && l2!=NULL)
	{
		if(l1->power > l2->power)
		{
			addend(l3,l1->coeff,l1->power);
			l1=l1->next;
		}
		else if(l1->power < l2->power)
		{
			addend(l3,l2->coeff,l2->power);
			l2=l2->next;
		}
		else
		{
			addend(l3,l1->coeff+l2->coeff,l1->power);
			l1=l1->next;
			l2=l2->next;
		}
	}
	if(l1==NULL && l2 == NULL)
	return ;
	else if(l1==NULL)
	temp=l2;
	else
	temp=l1;
	while(temp!=NULL)
	{
		addend(l3,temp->coeff,temp->power);
		temp=temp->next;
	}
	return;
}
int main()
{
	lptr L1=NULL,L2=NULL,L3=NULL;
	int n,ele1,ele2;
	cout<<"enter the no of terms in 1st polynomial expression::";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter coefficient and exponent";
		cin>>ele1>>ele2;
		addend(L1,ele1,ele2);
	}
	cout<<"enter the no of terms in 2nd polynomial expression::";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter coefficient and exponent";
		cin>>ele1>>ele2;
		addend(L2,ele1,ele2);
	}
	addpoly(L1,L2,L3);
	while(L3!=NULL)
	{
		cout<<L3->coeff<<" "<<L3->power<<endl;
		L3=L3->next;
	}
	return 0;
}
