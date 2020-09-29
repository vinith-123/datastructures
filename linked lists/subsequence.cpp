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
void subsequence(lptr L,int s)
{
	lptr sptr,ptr,temp;
	int count,sum,flag=0;
	ptr=L;
	while(ptr!=NULL)
	{
		sptr=ptr;
		temp=ptr;
		sum=0;count=0;
		while(sum<s)
		{
			sum+=temp->data;
			count++;
			if(sum==s)
			break;
			temp=temp->next;
		}
		if(sum==s)
		{
			flag++;
			for(int k=0;k<count;k++)
			{
				cout<<sptr->data<<" ";
				sptr=sptr->next;
			}
			cout<<endl;
		}
		ptr=ptr->next;
	}
	if(flag==0)
	cout<<"no subsequence found!";
	return;
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
	cout<<"enter the sum to be checked:";
	cin>>k;
	subsequence(L,k);
	return 0;
}
