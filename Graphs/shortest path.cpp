#include<iostream>
using namespace std;
int adj[7][7];
struct vertex
{
	int cost;
	int prev;
	int flag;
}v[7];

int count1(int v)
{
	int c=0;
	for(int i=0;i<7;i++)
	{
		if(adj[v][i]!=0)
		c++;
	}
	return c;
}
int updatecurrent()
{
	int tempcost=1000,result;
	for(int i=0;i<7;i++)
	{
		if(v[i].flag==0)
		{
			if(v[i].cost < tempcost )
			{
				result=i;
				tempcost=v[i].cost;
			}
		}
	}
	return result;
}
void shortestpath(int curr,int d,int &flag)
{
	int c=0,j=0,cost=0,count=0;
	while(flag!=1)
	{
		c=count1(curr);
		while(count!=c)
		{
			while(adj[curr][j]==0)
			j++;
			count++;
			cost=adj[curr][j];
			if(v[j].cost > cost+v[curr].cost)
			{
				v[j].cost=cost+v[curr].cost;
				v[j].prev=curr;
			}
			j++;
		}
		v[curr].flag=1;
		curr=updatecurrent();
		if(curr==d)
		{
			cout<<v[curr].cost<<endl;
			flag=1;
			break;
		}
		else
		shortestpath(curr,d,flag);
	}
	return;
}
int main()
{
	int ch=1,s,d,w,v1,v2,point,x=0,arr[8],flag=0;
	while(ch!=-1)
	{
		cout<<"enter the edge vertices & weight:";
		cin>>v1>>v2>>w;
		adj[v1][v2]=w;
		cout<<"enter -1 to exit:";
		cin>>ch;
	}
	for(int i=0;i<7;i++)
	{
		v[i].cost=1000;
		v[i].flag=0;
		v[i].prev=-1;
	}
	cout<<"enter source,destination:";
	cin>>s>>d;
	v[s].cost=0;v[s].prev=s;
	shortestpath(s,d,flag);
	point=d;
	while(point!=s)
	{
		arr[x++]=point;
		point=v[point].prev;
	}
	cout<<s<<"->";
	x--;
	while(x!=-1)
	{
		cout<<arr[x--];
		if(x!=-1)
		cout<<"->";
	}
	return 0;
}
