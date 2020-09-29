/*
0 1
1
0 2
1
0 3
1
1 2
1
2 3
1
1 4
-1
*/
#include<iostream>
using namespace std;
int adj[5][5],visited[5];
string s1="";
void dft(int v,string s1)
{
	s1+=v+48;
	visited[v]=1;
	int tempvisit[5],flag=0;
	for(int i=0;i<5;i++)
	tempvisit[i]=visited[i];
	string s="";
	for(int i=0;i<5;i++)
	{
		if(adj[v][i] && !visited[i])
		{
			flag=1;
			s+=i+48;
		}
	}
	if(flag==0)
	{
		if(s1.length()==5)
		cout<<s1<<endl;
		else
		{
			string s2="";
			for(int i=0;i<5;i++)
			{
				if(!visited[i] && adj[s1[0]-48][i]>0)
				s2+=i+48;
			}
			for(int i=0;i<s2.length();i++)
			{
				int tempvisit2[5];
				for(int q=0;q<5;q++)
				tempvisit2[q]=visited[q];
				dft(s2[i]-48,s1);
				for(int j=0;j<5;j++)
				visited[j]=tempvisit2[j];
			}
		}
	}
	else
	{
		for(int i=0;i<s.length();i++)
		{
			dft(s[i]-48,s1);
			for(int k=0;k<5;k++)
			visited[k]=tempvisit[k];
		}
	}
}
int main()
{
	int ch=1,v1,v2,s;
	while(ch!=-1)
	{
		cout<<"enter the edge vertices:";
		cin>>v1>>v2;
		adj[v1][v2]=adj[v2][v1]=1;
		cout<<"enter -1 to exit:";
		cin>>ch;
	}
	cout<<"enter the starting vertex:";
	cin>>s;
	dft(s,s1);
	return 0;
}
