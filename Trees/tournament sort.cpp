#include<iostream>
using namespace std;
typedef struct btnode{
	struct btnode *lchild;
	int data;
	struct btnode *rchild;
}*BTPTR;
struct stack{
	int top;
	int size;
	BTPTR elements[50];	
}s1,s2;
void push(BTPTR T,stack &s)
{
	s.elements[++s.top]=T;	
}
BTPTR pop(stack &s)
{
	return s.elements[s.top--];
}
typedef struct lnode{
	int d;
	struct lnode *next;
}*LPTR;
void deletenum(LPTR &L,int k)
{
	LPTR ptr=L,temp;
	if(L->d==k)
	L=L->next;
	else
	{
		while(ptr->d!=k && ptr!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		if(ptr->d==k)
		{
			temp->next=ptr->next;
			ptr->next=NULL;
		}
	}
}
int tournament()
{
	BTPTR temp,dm=new(btnode),ele1,ele2;
	dm->data=-1;dm->lchild=NULL;dm->rchild=NULL;
	while((s1.top!=0 && s2.top==-1)||(s2.top!=0 && s1.top==-1))
	{
		while(s1.top!=-1)
		{
			ele1=pop(s1);
			if(s1.top!=-1)
			ele2=pop(s1);
			else
			ele2=dm;
			temp=new(btnode);
			ele1->data > ele2->data?(temp->data=ele1->data):(temp->data=ele2->data);
			temp->rchild=ele1;
			temp->lchild=ele2;
			push(temp,s2);
		}
		while(s2.top!=-1)
		{
			ele1=pop(s2);
			if(s2.top!=-1)
			ele2=pop(s2);
			else
			ele2=dm;
			temp=new(btnode);
			ele1->data > ele2->data?(temp->data=ele1->data):(temp->data=ele2->data);
			temp->rchild=ele1;
			temp->lchild=ele2;
			push(temp,s1);
		}
	}
	if(s1.top==0)
	return pop(s1)->data;
	else
	return pop(s2)->data;
}
int main()
{
	LPTR L=NULL,temp;
	BTPTR ptr;
	int n,k;s1.top=-1;s1.size=50;s2.size=50;s2.top=-1;
	cout<<"enter the no of elements to be sorted:";
	cin>>n;
	L=new(lnode);L->next=NULL;temp=L;
	cout<<"enter the elements:";
	cin>>L->d;
	for(int i=1;i<n;i++)
	{
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=new(lnode);
		cin>>temp->next->d;
		temp->next->next=NULL;
	}
	for(int z=0;z<n;z++)
	{
		temp=L;
		while(temp!=NULL)
		{
			ptr=new(btnode);
			ptr->lchild=NULL;
			ptr->rchild=NULL;
			ptr->data=temp->d;
			push(ptr,s1);
			temp=temp->next;
		}
		k=tournament();
		cout<<k<<" ";
		deletenum(L,k);
	}
	return 0;
}
