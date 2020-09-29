#include<iostream>
using namespace std;
typedef struct mtnode
{
	mtnode *ptr[3];
	int key[2];
}*MTPTR;
void create(MTPTR &T,int k)
{
	if(T==NULL)
	{
		T=new(mtnode);
		for(int i=0;i<3;i++)
		T->ptr[i]=NULL;
		T->key[0]=k;
		T->key[1]=-1;
	}
	else
	{
		MTPTR ptr1=T;int j=0,temp;
		while(j!=2)
		{
			if(ptr1->key[j]==-1)
			break;
			j++;
		}
		if(ptr1->key[j]==-1)
		{
			j=0;
			while(ptr1->key[j]!=-1)
			{
				if(ptr1->key[j]>k)
				{
					temp=ptr1->key[j];
					ptr1->key[j]=k;
					k=temp;
					j++;
				}
				else
				j++;
			}
			ptr1->key[j]=k;
		}
		else
		{
			 j=0;
			while(1)
			{
				if(k<=ptr1->key[j])
				{
					create(ptr1->ptr[j],k);
					break;
				}
				else
				{
					create(ptr1->ptr[j+1],k);
					break;
				}
			}
		}
	}
}
void print(MTPTR T)
{
	if(T!=NULL)
	{
		for(int r=0;r<2;)
		{
			print(T->ptr[r]);
			if(T->key[r]!=-1)
			cout<<T->key[r++]<<" ";
			print(T->ptr[r]);
		}
	}
	else
	return;
}
bool search(MTPTR T,int k)
{
	if(T!=NULL)
	{
		int z;
		for(z=0;z<2;z++)
		{
			if(T->key[z]==k)
			return true;
		}
		z=0;
		while(1)
		{
			if(k>T->key[z])
			z++;
			else
			return search(T->ptr[z],k);
		}
	}
	else
	return false;
}
int main()
{
	MTPTR T=NULL;
	int ch=1,k;
	while(ch!=3)
	{
		cout<<"select the choice 1.create 2.search 3.print 4.exit::";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter the key:";
				cin>>k;
				create(T,k);
				break;
			case 2:
				cout<<"enter the key to be searched:";
				cin>>k;
				if(search(T,k))
				cout<<"found!";
				else
				cout<<"not found:(";
				break;
			case 3:
				print(T);
			default:
				break;	
		}
	}
	return 0;
}
