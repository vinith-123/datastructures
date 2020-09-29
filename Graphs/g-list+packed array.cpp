#include<iostream>
using namespace std;
typedef struct lnode{
	struct gnode *link;
	struct lnode *next;
}*LPTR;
typedef struct gnode{
	int vertex;
	struct gnode *vnext;
	struct lnode *lnext;
}*GPTR;
void print1(GPTR a[],int v)
{
	for(int i=0;i<v;i++)
	{
		cout<<a[i]->vertex<<" ";
		if(a[i]->lnext!=NULL)
		{
			LPTR ptr=a[i]->lnext;
			while(ptr!=NULL)
			{
				cout<<ptr->link->vertex<<" ";
				ptr=ptr->next;
			}
		}
		cout<<endl;
	}
}
int count(GPTR v)
{
	int c=0;
	LPTR ptr=v->lnext;
	while(ptr!=NULL)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}
void pack(GPTR vert[],int v,int a[])
{
	int x=0;
	for(int i=0;i<v;i++)
	{
		if(vert[i]->lnext!=NULL)
		{
			LPTR ptr=vert[i]->lnext;
			while(ptr!=NULL)
			{
				a[x++]=ptr->link->vertex;
				ptr=ptr->next;
			}
		}
	}
}
int main()
{
	int v,c=0;
	cout<<"enter no of vertices:";
	cin>>v;
	int a[v][v];
	for(int i=0;i<v;i++)
	for(int j=0;j<v;j++)
	cin>>a[i][j];
	GPTR vert[v];
	for(int i=0;i<v;i++)
	{
		vert[i]=new(gnode);
		vert[i]->lnext=NULL;
		vert[i]->vertex=i;
		vert[i]->vnext=NULL;
	}
	for(int i=0;i<v-1;i++)
	vert[i]->vnext=vert[i+1];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(a[i][j]==1)
			{
				LPTR ptr=new(lnode);
				ptr->link=vert[j];
				ptr->next=NULL;
				if(vert[i]->lnext==NULL)
				vert[i]->lnext=ptr;
				else
				{
					LPTR p=vert[i]->lnext;
					while(p->next!=NULL)
					p=p->next;
					p->next=ptr;
				}
			}
		}
	}
	cout<<"G-list\n";
	print1(vert,v);
	int arr[v],size;
	arr[0]=0;
	for(int i=1;i<v;i++)
	arr[i]=arr[i-1]+count(vert[i]);
	size=arr[v-1];
	int packedarry[size];
	pack(vert,v,packedarry);
	cout<<"packed array\n";
	cout<<"index array:";
	for(int i=0;i<v;i++)
	cout<<arr[i]<<endl;
	cout<<"packed array:";
	for(int i=0;i<size;i++)
	cout<<packedarry[i]<<" ";
	return 0;	
}
