#include<iostream>
using namespace std;
typedef struct lnode{
	int data;
	struct lnode *next;
}*lptr;
lptr L1=NULL,L2=NULL;
void addend(lptr &L,int k)
{
	lptr temp,ptr;
	ptr=L;
	temp=new(lnode);
	temp->data=k;
	temp->next=NULL;
	if(ptr==NULL)
	{
		L=temp;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
int main()
{
	int n,ele;
	cout<<"enter the no of elements in 1st list:";
	cin>>n;
	cout<<"enter the elements in 1st list:";
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		addend(L1,ele);
	}
	cout<<"enter the no of elements in 2nd list:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		addend(L2,ele);
	}
	lptr t1,t2;
	t1=L1;
	cout<<"common elements in both lists:";
	while(t1!=NULL)
	{
		t2=L2;
		while(t2!=NULL)
		{
			if(t1->data==t2->data)
			{
				cout<<t1->data<<" ";
				break;
			}
			t2=t2->next;
		}
		t1=t1->next;
	}
	return 0;
}

