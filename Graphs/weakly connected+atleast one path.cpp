/*
0 1
1
1 2
1
2 3
1
4 0
1
4 3
-1
*/
#include<iostream>
using namespace std;
int adj[5][5];
string ans="";
int indegree(int v)
{
	int count=0;
	for(int i=0;i<5;i++)
	{
		if(adj[i][v])
		count++;
	}
	return count;
}
int outdegree(int v)
{
	int count=0;
	for(int i=0;i<5;i++)
	{
		if(adj[v][i])
		count++;
	}
	return count;
}
void dfs(int s,int d,string ans)
{
	if(indegree(d)==0 || outdegree(s)==0)
	{
		cout<<"no path exists\n";
		exit(0);
	}
	else
	{
		string str="";
		ans+=s+48;
		for(int i=0;i<5;i++)
		{
			if(adj[s][i])
			str+=i+48;
		}
		for(int i=0;i<str.length();i++)
		{
			if(str[i]-48==d)
			{
				ans+=str[i];
				cout<<ans<<endl;
				exit(0);
			}
		}
		string temp=ans;
		for(int i=0;i<str.length();i++)
		{
			dfs(str[i]-48,d,ans);
			ans=temp;
		}
	}
}
int main()
{
	int v1,v2,ch=1,s,d;
	while(ch!=-1)
	{
		cout<<"enter the edge vertices:";
		cin>>v1>>v2;
		adj[v1][v2]=1;
		cout<<"enter -1 to exit:";
		cin>>ch;
	}
	cout<<"enter source and destination:";
	cin>>s>>d;
	dfs(s,d,ans);
	return 0;
}
