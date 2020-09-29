#include<iostream>
using namespace std;
typedef struct lnode{
	int data;
	struct lnode *next;
}*lptr;
void addend(lptr &l,int x)
{
	lptr temp=new(lnode),ptr=l;
	temp->data=x;
	if(l==NULL)
	{
		l=temp;
		temp->next=l;
	}
	else
	{
		temp->next=l;
		while(ptr->next!=l)
		ptr=ptr->next;
		ptr->next=temp;
	}
}
int personleft(lptr &l)
{
	lptr ptr=l,temp;int n,c,count;
	do
	{
		cout<<"enter the value on the die:";
		cin>>n;c=0;count=0;
		while(c!=n)
		{
			temp=ptr;
			ptr=ptr->next;
			c++;
		}
		temp->next=ptr->next;
	}while(temp->next->next!=temp);
	return l->data;
}
int main()
{
	lptr L=NULL;
	int n;
	cout<<"enter no of persons:";
	cin>>n;
	string s[n];
	cout<<"enter the names:";
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		addend(L,i);
	}
	cout<<s[personleft(L)]<<endl;
	return 0;
}
