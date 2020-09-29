#include<iostream>
using namespace std;
typedef struct lnode{
	int  data;
	struct lnode *next;
}*lptr;
lptr L=NULL;
void addend(int x)
{
	lptr ptr=L,temp=new(lnode);
	temp->data=x;
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
void bubblesort(int n)
{
	lptr ptr1=L,ptr2=L->next;int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n-i;j++)
		{
			if(ptr1->data > ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		ptr1=L;
		ptr2=L->next;
	}
}
void display()
{
	while(L!=NULL)
	{
		cout<<L->data<<" ";
		L=L->next;
	}
}
int main()
{
	int n,ele;
	cout<<"enter no of elements";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		addend(ele);
	}
	bubblesort(n);
	display();
	return 0;
}
