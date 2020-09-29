/*
10
0 1
1
0 2
1
1 2
1
1 3
1
3 4
1
3 5
1
4 5
1
4 6
1
6 7
1
6 8
1
6 9
1
7 8
1
8 9
-1*/
#include<iostream>
using namespace std;
int adj[100][100],count=1,flag[100];
struct vertex{
	int num;
	int low;
	int parent;
	int visited;
}v[100];
void assigndft(int ver,int par,int n)
{
	v[ver].low=v[ver].num=count++;
	v[ver].parent=par;
	v[ver].visited=1;
	for(int i=0;i<n;i++)
	{
		if(adj[ver][i] && !(v[i].visited))
		assigndft(i,ver,n);
	}
}
void updatelow(int n)
{
	for(int i=n-1;i>-1;i--)            
	{
		for(int j=0;j<n;j++)              //second case where vertex has back edge and if(w.num<v.low update with minimum value)
		{
			if(adj[i][j] && j!=v[i].parent)
			v[i].low=min(v[i].low,v[j].num);
		}
		for(int j=0;j<n;j++)              //third case where if vertex has children and if(child.low <v.low then update)
		{
			if( adj[i][j] && v[i].num < v[j].num)
			v[i].low=min(v[i].low,v[j].low);
		}
	}
}
bool threechild(int root,int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(adj[root][i])
		c++;
	}
	if(c>2)
	return true;
	return false;
}
void cutvertex(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(adj[i][j] && v[j].low>=v[i].num)
			flag[i]=1;
		}
	}
	if(threechild(0,n))
	cout<<0<<endl;
	for(int i=1;i<n;i++)
	{
		if(flag[i])
		cout<<i<<" ";
	}
}
int main()
{
	int v1,v2,ch=1,n;
	cout<<"enter no of vertices:";
	cin>>n;
	while(ch!=-1)
	{
		 cout<<"enter the edge vertices:";
		 cin>>v1>>v2;
		 adj[v1][v2]=adj[v2][v1]=1;
		 cout<<"enter -1 to exit:";
		 cin>>ch;
	}
	assigndft(0,-1,n);
	for(int i=0;i<n;i++)
	v[i].visited=0;
	updatelow(n);
	cutvertex(n);
	return 0;
}
