/*0 1 7
1
0 2 8
1
1 2 3
1
1 3 6
1
2 4 3
1
2 3 4
1
3 4 2
1
3 5 5
1
4 5 2
-1*/ //input
#include<iostream>
#include<cstring>
using namespace std;
int adj[6][6],sum=0;
int S[6];
string str="";
int find(int i)
{
	if(S[i]==0)
	return i;
	else
	return find(S[i]);
}
void un(int u,int v,int &c)
{
	if(find(u)!=find(v))
	{
		c++;
		sum+=adj[u][v];
		str+=u+48;
		str+=v+48;
		if(S[u]==0)
		S[u]=v;
		else if(S[v]==0)
		S[v]=u;
		else
		S[find(u)]=v;
	}
	adj[u][v]=adj[v][u]=1000;
}
void kruskalmsp(int vertc)
{
	int c=0,v1,v2,min;
	while(c!=vertc-1)
	{
		min=1000;
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<6;j++)
			{
				if(adj[i][j]<min)
				{
					min=adj[i][j];
					v1=i;
					v2=j;
				}
			}
		}
		un(v1,v2,c);
	}
}
int main()
{
	int ch=1,v1,v2,w,n=6;
	for(int i=0;i<6;i++)
	for(int j=0;j<6;j++)
	adj[i][j]=1000;
	for(int i=0;i<6;i++)
	S[i]=0;
	while(ch!=-1)
	{
		cout<<"enter the edge vertices with weights:";
		cin>>v1>>v2>>w;
		adj[v1][v2]=adj[v2][v1]=w;
		cout<<"enter -1 to exit:";
		cin>>ch;
	}
	kruskalmsp(n);
	cout<<str<<endl;
	cout<<"cost="<<sum<<endl;
	return 0;
}
