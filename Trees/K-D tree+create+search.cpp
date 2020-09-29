#include<iostream>
using namespace std;
typedef struct kdnode{
	struct kdnode *lchild;
	char data[3];
	struct kdnode *rchild;
}*KDPTR;
void create(KDPTR &T,char k[])
{
	int i=0;
	KDPTR temp=new(kdnode);
	temp->lchild=NULL;
	temp->data[0]=k[0];
	temp->data[1]=k[1];
	temp->data[2]=k[2];
	temp->rchild=NULL;
	if(T==NULL)
	T=temp;
	else
	{
		KDPTR ptr=T;
		while(1)
		{
			if(ptr->data[i]<k[i])
			{
				if(ptr->rchild==NULL)
				{
					ptr->rchild=temp;
					break;
				}
				else
				{
					ptr=ptr->rchild;
					i=(i+1)%3;
				}
			}
			else
			{
				if(ptr->lchild==NULL)
				{
					ptr->lchild=temp;
					break;
				}
				else
				{
					ptr=ptr->lchild;
					i=(i+1)%3;
				}
			}
		}
	}
}
void print(KDPTR T)
{
	if(T==NULL)
	return;
	else
	{
		cout<<"["<<T->data[0]<<" "<<T->data[1]<<" "<<T->data[2]<<"]"<<endl;
		print(T->lchild);
		print(T->rchild);
	}
}
bool search(KDPTR T,char k[])
{
	static int i=0;
	if(T!=NULL)
	{
		if(T->data[i]<k[i])
		{
			i=(i+1)%3;
			return search(T->rchild,k);
		}
		if(T->data[i]>k[i])
		{
			i=(i+1)%3;
			return search(T->lchild,k);
		}
		if(T->data[i]==k[i])
		{
			for(int j=0;j<3;j++)
			{
				if(T->data[j]!=k[j])
				return false;
			}
			return true;
		}
	}
	else
	return false;
}
int main()
{
	int ch=0,n=1;KDPTR T=NULL;
	char k[3],s[3];
	while(ch!=4)
	{
		cout<<"enter the choice 1.create K-D tree 2.print 3.search 4.exit::";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter no of nodes:";
				cin>>n;
				cout<<"enter enter all nodes keysets of form [char,char,char]\n";
				for(int z=0;z<n;z++)
				{
					cin>>k[0]>>k[1]>>k[2];
					create(T,k);
				}
				break;
			case 2:
				print(T);
				break;
			case 3:
				cout<<"enter the keyset to be searched:";
				cin>>s[0]>>s[1]>>s[2];
				if(search(T,s))
				cout<<"found!\n";
				else
				cout<<"not found!\n";
				break;
			default:
				break;
		}
	}
	return 0;
}
