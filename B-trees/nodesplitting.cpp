#include<iostream>
using namespace std;
typedef struct blnode{
	struct blnode *pptr;
	int keys[2];
	struct blnode *ptr[3];
}*BLPTR;
bool isleaf(BLPTR T)
{
	for(int i=0;i<3;i++)
	{
		if(T->ptr[i]!=NULL)
		return false;
	}
	return true;
}
bool emptyslot(BLPTR T)
{
	for(int i=0;i<2;i++)
	{
		if(T->keys[i]==-1)
		return true;
	}
	return false;
}
void parent(BLPTR &T,BLPTR &p,BLPTR &temp1,int a[]);
void overflow(BLPTR &T,BLPTR &p,int n)
{
	int j,k=0,a[3],temp;
	BLPTR b[4],swaptemp2;
	BLPTR temp1=new(blnode),temp2=p->pptr;
	a[2]=n;
	a[0]=p->keys[0];
	a[1]=p->keys[1];
	for(int i=0;i<3;i++)
	b[i]=p->ptr[i];
	b[3]=NULL;
	for(int i=0;i<3;i++)
	{
		for(int j=1;j<3-i;j++)
		{
			if(a[j] < a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				swaptemp2=b[j];
				b[j]=b[j+1];
				b[j+1]=swaptemp2;
			}
		}
	}
	p->keys[0]=a[0];p->keys[1]=-1;
	temp1->keys[0]=a[2];temp1->keys[1]=-1; 
	p->ptr[0]=b[0];
	p->ptr[1]=b[1];
	for(int i=2;i<3;i++)
	p->ptr[i]=NULL;
	k=0;
	for(int i=2;i<4;i++)
	temp1->ptr[k++]=b[i];
	for(int v=k;v<3;v++)
	temp1->ptr[v]=NULL;
	if(temp2==NULL)
	{
		T=new(blnode);
		T->pptr=NULL;
		T->keys[0]=a[1];
		T->ptr[0]=p;
		T->ptr[1]=temp1;
		T->ptr[2]=NULL;
		T->keys[1]=-1;
		p->pptr=T;
		temp1->pptr=T;
	}
	else
	parent(T,p,temp1,a);
}
void parent(BLPTR &T,BLPTR &p,BLPTR &temp1,int a[])
{
	BLPTR pp=p->pptr;int n=a[1];
		if(emptyslot(pp))
		{
			int i=0,temp;
			BLPTR temp2;
			while(pp->keys[i]<n && pp->keys[i]!=-1) 
			i++;
			if(pp->keys[i]==-1)
			{
				pp->keys[i]=n;
				pp->ptr[i+1]=temp1;
			}
			else
			{
				while(pp->keys[i]!=-1)
				{
					temp=pp->keys[i];
					temp2=pp->ptr[i+1];
					pp->keys[i]=n;
					pp->ptr[i+1]=temp1;
					n=temp;
					temp1=temp2;
					i++;
				}
				pp->keys[i]=n;
				pp->ptr[i+1]=temp1;
			}
		}
		else
		{
			cout<<"yes its working\n";
			overflow(T,pp,n);
			cout<<"yes again\n";
		/*	BLPTR temp=T,temp2;int i=0;
			while(temp!=NULL)
			{
				i=0;
				while(a[2]> temp->keys[i] && temp->keys[i]!=-1 && i!=2)
				i++;
				if(temp->keys[i]==-1)
				{
					temp2=temp;
					temp=temp->ptr[i];
				}
				else if(i==2)
				{
					temp2=temp;
					temp=temp->ptr[2];
				}
				else
				{
					temp2=temp;
					temp=temp->ptr[i];
				}
			}
			cout<<temp2->keys[0]<<" "<<temp2->keys[1]<<endl;
			//temp2->ptr[i]=temp1;*/
		}
}
void print(BLPTR T)
{
	if(T==NULL)
	return ;
	else
	{
		for(int i=0;i<2;i++)
		{
			print(T->ptr[i]);
			if(T->keys[i]!=-1)
			cout<<T->keys[i]<<" ";
		}
		print(T->ptr[2]);
	}
}
int main()
{
	int n,i,j,k,t,a[3];
	BLPTR T=new(blnode),p=T;
	T->pptr=NULL;
	for(int i=0;i<2;i++)
	{
		T->keys[i]=-1;
		T->ptr[i]=NULL;
	}
	T->ptr[2]=NULL;
	while(1)
	{
		cout<<"enter integer:";
		cin>>n;i=0;BLPTR temp1,temp2;p=T;
		while(!isleaf(p))
		{
			while(n>p->keys[i] && i!=2 && p->keys[i]!=-1)
			i++;
			if(i==3)
			{
				p=p->ptr[2];
				i=0;
			}
			else
			{
				p=p->ptr[i];
				i=0;
			}
		}
		if(emptyslot(p))
		{
				i=0;
				while(p->keys[i]!=-1)
				{
					if(p->keys[i]>n)
					{
						t=p->keys[i];
						p->keys[i]=n;
						n=t;
					}
					i++;
				}
				p->keys[i]=n;
		}
		else
		overflow(T,p,n);
		print(T);
		cout<<endl;
		cout<<"enter -1 to exit:";
		cin>>n;
		if(n==-1)break;
	}
	return 0;
}
