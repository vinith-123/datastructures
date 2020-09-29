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
int search(lptr L,int k)
{
	if(L==NULL)
		return 0;
	else
	{
		if(L->data==k)
		return 1;
		search(L->next,k);
	}
}
int main()
{
	lptr L=NULL;
	int n,k;
	cout<<"enter no of elements in LL:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		addend(L,k);
	}
	cout<<"enter the number to be searched:";
	cin>>k;
	if(search(L,k))
	cout<<"found!";
	else
	cout<<"not found!";
	return 0;
}
