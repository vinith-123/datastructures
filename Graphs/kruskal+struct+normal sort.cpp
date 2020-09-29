/*9
0 1 7
0 2 8
1 2 3
1 3 6
2 3 4
2 4 3
3 4 2
3 5 5
4 5 2*/
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
void un(edge e,int &count)
{
	if(find(e.v1)!=find(e.v2))
	{
		count++;
		cost+=e.w;
		str+=e.v1+48;
		str+=e.v2+48;
		if(S[e.v1]==0)
		S[e.v1]=e.v2;
		else if(S[e.v2]==0)
		S[e.v2]=e.v1;
		else
		S[find(e.v1)]=e.v2;
	}	
}

int main()
{
	for(int i=0;i<20;i++)
	{
		e[i].w=1000;
	}
	int count=0,n=6;
	memset(S,0,sizeof(S));
	cout<<"enter no of edges;";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"edge vertices,weight:";
		cin>>e[i].v1>>e[i].v2>>e[i].w;
	}
	sort(e,e+n,comp);
	int i=0;
	while(count!=5)
	{
		un(e[i],count);
		i++;
	}
	cout<<str<<endl;
	cout<<"cost="<<cost<<endl;
}

