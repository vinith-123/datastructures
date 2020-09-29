#include<iostream>
using namespace std;
int adj[12][12];
struct vertex{
	int degree;
}v[12];
typedef struct lnode{
	int vertex;
	struct lnode *next;
}*LPTR;
int deg(int v)
{
	int count=0;
	for(int i=0;i<12;i++)
	if(adj[v][i])
	count++;
	return count;
}
void eulercycle(int i,LPTR &L)
{
	string s1="";
	int tempadj[12][12];
	struct vertex tempv[12];
	LPTR temp=new(lnode);
	temp->vertex=i;
	temp->next=NULL;
	if(L==NULL)
	L=temp;
	else
	{
		LPTR ptr=L;
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=temp;
	}
	int x=0;
	for(int q=0;q<12;q++)
	{
		for(int x=0;x<12;x++)
		{
			tempadj[q][x]=adj[q][x];
			tempv[x]=v[x];
		}
	}
	for( x=0;x<12;x++)
	{
		if(adj[i][x])
		{
			adj[i][x]=adj[x][i]=0;
			v[i].degree--;
			v[x].degree--;
			s1+=x+48;
		}
	}
	if(x==12)
	return;
	else
	{
		for(int w=0;w<s1.length();w++)
		{
			eulercycle(s1[w]-48,L);
			for(int q=0;q<12;q++)
			{
				for(int x=0;x<12;x++)
				{
					adj[q][x]=tempadj[q][x];
					v[x]=tempv[x];
				}
			}
		}
	}
}
void slice(int v,LPTR &L)
{
	LPTR ptr=L,sub=NULL,temp=NULL;
	while(ptr->next->vertex!=v)
	ptr=ptr->next;
	eulercycle(v,sub);
	temp=sub;
	while(sub->next!=NULL)
	sub=sub->next;
	sub->next=ptr->next->next;
	ptr->next=temp;
}
int main()
{
	int ch=1,v1,v2,s;
	LPTR L=NULL;
	while(ch!=-1)
	{
		cout<<"enter the edge vertices:";
		cin>>v1>>v2;
		adj[v1][v2]=adj[v2][v1]=1;
		cout<<"enter -1 to exit:";
		cin>>ch;
	}
	for(int i=0;i<12;i++)
	{
		if(deg(i)>0 && (deg(i)%2==0))
		v[i].degree=deg(i);
		else
		{
			cout<<"euler cycle not possible";
			break;
		}
	}
	cout<<"enter the starting vertex:";
	cin>>s;
	eulercycle(s,L);
	LPTR ptr=L;int flag=-1;
	while(ptr)
	{
		if(v[ptr->vertex].degree!=0)
		slice(ptr->vertex,L);
		else
		ptr=ptr->next;
	}
	while(L)
	{
		cout<<L->vertex<<" ";
		L=L->next;
	}
	return 0;
}
