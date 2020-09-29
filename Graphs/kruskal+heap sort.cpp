#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int S[6],cost=0;
string str="";
struct edge{
	int v1;
	int v2;
	int w;
}e[20];
bool comp(edge l,edge r)
{
	return l.w<r.w;
}
int find(int i)
{
	if(S[i]==0)
	return i;
	else
	return find(S[i]);
}
void un(edge v,int &count,int &n)
{
	if(find(v.v1)!=find(v.v2))
	{
		count++;
		cost+=v.w;
		str+=v.v1+48;
		str+=v.v2+48;
		if(S[v.v1]==0)
		S[v.v1]=v.v2;
		else if(S[v.v2]==0)
		S[v.v2]=v.v1;
		else
		S[find(v.v1)]=v.v2;
	}	
}
void heapify(edge e[],int n)
{
	edge temp;
	for(int i=1;i<n;i++)
	{
		if(2*i<n)
		{
			if(e[i].w>e[2*i].w)
			{
				temp=e[i];
				e[i]=e[2*i];
				e[2*i]=temp;
			}
		}
		if(2*i+1<n)
		{
			if(e[i].w>e[2*i+1].w)
			{
				temp=e[i];
				e[i]=e[2*i+1];
				e[2*i+1]=temp;
			}
		}
	}
}
bool isheap(edge e[],int n)
{
	for(int i=1;i<n;i++)
	{
		if(2*i<n)
		{
			if(e[i].w>e[2*i].w)
			return false;
		}
		if(2*i+1<n)
		{
			if(e[i].w>e[2*i+1].w)
			return false;
		}
	}
	return true;
}
int main()
{
	for(int i=0;i<20;i++)
	e[i].w=1000;
	int count=0,n=6;
	memset(S,0,sizeof(S));
	cout<<"enter no of edges;";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"edge vertices,weight:";
		cin>>e[i].v1>>e[i].v2>>e[i].w;
	}
	while(count!=5)
	{
		while(!isheap(e,n))
		heapify(e,n);
		un(e[1],count,n);
		e[1]=e[n-1];
		n--;
	}
	cout<<str<<endl;
	cout<<"cost="<<cost<<endl;
}

