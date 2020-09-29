// vinith alampally 
// all BFT's 
/*
	logic
	1.we will have a queue which will store all adjacent unvisited vertices of present vertices
	2.we permute all elements of the queue as a string and for each permutation we update the index of parent and  enqueue all its children and recursively call the bft function
*/
#include<iostream>
#include<cstring>
using namespace std;
char adj[12][12];
struct queue{
	char elements[50];
	int front;
	int rear;
	int size;
}q;
void enqueue(char c)
{
	if((q.rear+1)%q.size!=q.front)
	{
		if(q.front==q.rear)
		q.front=0;
		q.rear=(q.rear+1)%(q.size);
		q.elements[q.rear]=c;
	}
}
char dequeue()
{
	if(q.front!=-1)
	{
		int index=q.front;
		if(q.front==q.rear)
		{
			q.front=q.rear=-1;
		}
		else
		q.front=(q.front+1)%q.size;
		return q.elements[index];
	}
}
string getchildren(char p,bool visited[])
{
	string s="";char c;
	for(int  i=0;i<12;i++)
	{
		if(adj[p-48][i]=='1')
		{
			visited[i]=true;
			c=i+48;
			s+=c;
		}
	}
	return s;
}
void bft(string s1,int indexpar,bool visited[]);
void swap(char &c1,char &c2)
{
	char temp=c1;
	c1=c2;
	c2=temp;
}
void permute(string s1,int l,int r,bool visited[],int x)
{
	int i;
	if(l==r)
	{
		int flag=0;
		bool tempvisit[12];
		for(int v=0;v<12;v++)
		tempvisit[v]=visited[v];
			char c=s1[x];
			for( i=0;i<12;i++)
			{
				if(c-48==i)
				break;
			}
			for(int j=0;j<12;j++)
			{
				if(adj[i][j]=='1'&& !visited[j])
				{
					flag=1;
					visited[j]=true;
					enqueue(j+48);
				}
			}
		bft(s1,++x,visited);
		for(int v=0;v<12;v++)
		visited[v]=tempvisit[v];
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(s1[l],s1[i]);
			permute(s1,l+1,r,visited,x);
			swap(s1[l],s1[i]);
		}
	}
}
void bft(string s1,int indexpar,bool visited[])
{
	if(s1.length()!=indexpar)
	{
		char c;
		int len1=s1.length(),flag=0,i;
		if(q.front==-1)
		{
			bool tempvisit[12];
			for(int v=0;v<12;v++)
			tempvisit[v]=visited[v];
			char c=s1[indexpar];
			for( i=0;i<12;i++)
			{
				if(c-48==i)
				break;
			}
			for(int j=0;j<12;j++)
			{
				if(adj[i][j]=='1'&& !visited[j])
				{
					flag=1;
					visited[j]=true;
					enqueue(j+48);
				}
			}
		}
		while(q.front!=-1)
		{
			flag=1;
			c=dequeue();
			s1+=c;
		}
		if(flag==1)
		{
			permute(s1,len1,s1.length()-1,visited,len1);
		}
		else
		{
			int i;
			bool tempvisit[12];
			for(int v=0;v<12;v++)
			tempvisit[v]=visited[v];
			char c=s1[indexpar];
			for( i=0;i<12;i++)
			{
				if(c-48==i)
				break;
			}
			for(int j=0;j<12;j++)
			{
				if(adj[i][j]=='1'&& !visited[j])
				{
					visited[j]=true;
					enqueue(j+48);
				}
			}	
			bft(s1,indexpar+1,visited);
			for(int v=0;v<12;v++)
			visited[v]=tempvisit[v];
		}
	}
	else
	cout<<s1<<endl;
}
int main()
{
	string s1="";
	bool visited[12];
	memset(visited,false,sizeof(visited));
	memset(adj,'0',sizeof(adj));
	q.front=-1;q.rear=-1;q.size=50;
	char v1,v2,s;int ch=1;
	while(ch!=-1)
	{
		cout<<"enter the edge vertices:";
		cin>>v1>>v2;
		adj[v1-48][v2-48]=adj[v2-48][v1-48]='1';
		cout<<"enter -1 to exit";
		cin>>ch;
	}
	cout<<"enter starting vertex";
	cin>>s;
	visited[s-48]=true;
	char c=s;
	s1=s1+c;
	string v=""+getchildren(s,visited);
	visited[s-48]=true;
	for(int i=0;i<v.length();i++)
	enqueue(v[i]);
	cout<<"all possible BFT's :) are\n";
	bft(s1,0,visited);
	return 0;
}
