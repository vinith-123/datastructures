#include<iostream>
#include<cstring>
using namespace std;
int count=1,num[10];
void dft(int v,int rev[][10],bool visited[])
{
		cout<<v<<" ";
		visited[v]=true;
		for(int i=0;i<10;i++)
		{
			if(visited[i]==false && rev[v][i]>0 && i!=v)
			{
				dft(i,rev,visited);
			}
		}
}
void dft2(int v,int adj[][10],bool visited[])
{
	visited[v]=true;
	for(int i=0;i<10;i++)
	{
		if(!visited[i] && adj[v][i]==1 && i!=v)
		{
			dft2(i,adj,visited);
		}
	}
	num[v]=count++;
}
int main()
{
	bool visited[10];
	int  adj[10][10],rev[10][10];
	int i=0,v1,v2,c=0,max,index;
	memset(num,0,sizeof(num));
	memset(adj,0,sizeof(adj));
	memset(rev,0,sizeof(rev));
	memset(visited,false,sizeof(visited));
	int ch=1;
	while(ch!=-1)
	{
		cout<<"enter edge vertices:";
		cin>>v1>>v2;
		adj[v1][v2]=1;
		rev[v2][v1]=1;
		cout<<"enter -1 to exit";
		cin>>ch;
	}
	for(int i=0;i<10;i++)
	{
		if(!visited[i])
		{
			dft2(i,adj,visited);
		}
	}
	max=count-1;
	for(int z=0;z<10;z++)
	visited[z]=false;
	int flag3=1;
	while(max>0)
	{
		for(int i=0;i<10;i++)
		{
			if(num[i]==max)
			{
				if(!visited[i])
				{
					dft(i,rev,visited);
					cout<<endl;
				}
				max--;
			}
		}
	}
	return 0;
}
