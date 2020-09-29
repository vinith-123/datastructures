#include<iostream>
using namespace std;
typedef struct lnode{
	int data;
	struct lnode *next;
}*lptr;
void addend(lptr &l,int x)
{
	lptr ptr,temp;
	ptr=l;
	temp=new(lnode);
	temp->data=x;
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
lptr middle(lptr L)
{
	lptr mid=L,mover=L;
	int count=0;
	while(mover!=NULL)
	{
	 if(count==2)
	 {
		 mid=mid->next;
		 count=0;
	 }
	 mover=mover->next;
	 count++;
	}
	return mid;
}
int main()
{
	lptr L=NULL,ans=NULL;
	int ele,n;
	cout<<"enter no of elements:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		addend(L,ele);
	}
	ans=middle(L);
	cout<<ans->data<<" ";
	return 0;
}
