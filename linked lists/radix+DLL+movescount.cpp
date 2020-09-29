#include<iostream>
using namespace std;
typedef struct lnode{
	int data;
	struct lnode* next;
}*lptr;
typedef struct dnode{
	struct dnode *left;
	int tag;
	struct lnode *link;    
	struct dnode *right;
}*dptr;
void bucket(dptr &L)
{
	dptr temp,ptr=L;
	for(int i=0;i<10;i++)
	{
		temp=new(dnode);
		temp->left=NULL;temp->right=NULL;temp->link=NULL;temp->tag=i;
		if(L==NULL)
		L=temp;
		else
		{
			ptr=L;
			while(ptr->right!=NULL)
			ptr=ptr->right;
			temp->left=ptr;
			ptr->right=temp;
		}
	}
}
void addend(int x,lptr &l)
{
	lptr temp=new(lnode),ptr=l;
	temp->next=NULL;temp->data=x;
	if(l==NULL)
	l=temp;
	else
	{
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=temp;
	}
}
void outofbucket(int a[],dptr &l)
{
	dptr temp=l;int i=0;
	while(l!=NULL)
	{
		while(l->link!=NULL)
		{
			a[i++]=l->link->data;
			l->link=l->link->next;
		}
		l=l->right;
	}
	l=temp;
}
int digitcount(int x)
{
	int c=0;
	while(x!=0)
	{
		c++;
		x=x/10;
	}
	return c;
}
int main()
{
	int n,maxdigit=0,movescount=0;
	dptr L,temp;
	cout<<"enter the number of elements to be sorted:";
	cin>>n;
	int a[n],v=0,b,r;
	cout<<"enter the elements";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(maxdigit<digitcount(a[i]))
		maxdigit=digitcount(a[i]);
	}
	for(int i=1;i<=maxdigit;i++)
	{
		L=NULL;
		bucket(L);temp=L;
		for(int j=0;j<n;j++)
		{
			b=a[j];v=0;
			while(v!=i)
			{
				v++;
				r=b%10;
				b=b/10;
			}	
			while(1)
		   {
				if(temp->tag==r)
				{
					cout<<"adding"<<a[j]<<" at "<<temp->tag<<endl; 
					addend(a[j],temp->link);
					break;
				}
				else if(temp->tag<r)
				{
					while(temp->tag!=r)
					{
						movescount++;
						temp=temp->right;
					}
				}
				else
				{
					while(temp->tag!=r)
					{
						movescount++;
						temp=temp->left;
					}
				}
		   }   
	   }
	   outofbucket(a,L);
    }
	cout<<"movescount="<<movescount<<endl;
	cout<<"sorted order::";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}
