#include<iostream>
using namespace std;
typedef struct dtnode{
	struct dtnode *lchild;
	string data;
	struct dtnode *rchild;
}*DTPTR;
void create(DTPTR &T,string s)
{
	int i=0;
	DTPTR temp=new(dtnode),ptr=T;
	temp->data=s;
	temp->lchild=NULL;temp->rchild=NULL;
	if(ptr==NULL)
	T=temp;
	else
	{
		while(i!=ptr->data.length())
		{
			if(ptr->data[i] < s[i])
			{
				if(ptr->rchild!=NULL)
				{
					i++;
					ptr=ptr->rchild;
				}
				else
				{
					ptr->rchild=temp;
					break;
				}
			}
			if(ptr->data[i]>s[i])
			{
				if(ptr->lchild!=NULL)
				{
					i++;
					ptr=ptr->lchild;
				}
				else
				{
					ptr->lchild=temp;
					break;
				}
			}
			if(ptr->data[i]==s[i])
			i++;
		}
		if(i==ptr->data.length())
		ptr->lchild=temp;
	}	
}
bool search(DTPTR T,string s)
{
	int i=0;
	while(T!=NULL)
	{
			if(T->data[i]<s[i])
			{
				i++;
				T=T->rchild;
			}
			if(T->data[i]>s[i])
			{
				i++;
				T=T->lchild;
			}
			if(T->data[i]==s[i])
			{
				if(T->data==s)return true;
				else
				return false;
			}
	}
	return false;
}
void print(DTPTR T)
{
	if(T==NULL)
	return;
	else
	{
		print(T->lchild);
		cout<<T->data<<endl;
		print(T->rchild);
	}
}
int main()
{
	int n;DTPTR T=NULL;
	string s;
	cout<<"enter no of nodes:";
	cin>>n;
	for(int z=0;z<n;z++)
	{
		cout<<"enter the binary string:";
		cin>>s;
		create(T,s);
	}
	//print(T);
	cout<<"enter the string to be searched:";
	cin>>s;
	if(search(T,s))
	cout<<"found!";
	else
	cout<<"not found!";
	return 0;
}
