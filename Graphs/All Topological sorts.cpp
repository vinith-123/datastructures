#include<iostream>
#include<cstring>
using namespace std;
int adj[6][6],flag[6]={false};
string s1="";
void alltopologicalsort(string s1)
{
	int tempadj[6][6],flag1=0,tempflag[6];
	string temps1=s1;
	string s="";
	for(int i=0;i<6;i++)
	{
		tempflag[i]=flag[i];
		for(int j=0;j<6;j++)
		tempadj[i][j]=adj[i][j];
	}
	for(int i=0;i<6;i++)
	{
		flag1=0;
		for(int j=0;j<6;j++)
		{
			if(adj[j][i]!=0)
			{
				flag1=1;
				break;
			}
		}
		if(flag1==0 && !flag[i])
		s+=i+48;
	}
	if(s.length()>0)
	{
		for(int i=0;i<s.length();i++)
		{
			s1+=s[i];
			flag[s[i]-48]=1;
			for(int j=0;j<6;j++)
			adj[s[i]-48][j]=0;
			alltopologicalsort(s1);
			for(int v=0;v<6;v++)
			{
				flag[v]=tempflag[v];
				for(int x=0;x<6;x++)
				adj[v][x]=tempadj[v][x];
			}
			s1=temps1;
		}
	}
	else
	{
		cout<<s1<<endl;
		return;
	}
}
int main()
{
	int ch=1,v1,v2;
	while(ch!=-1)
	{
		cout<<"enter edge vertices:";
		cin>>v1>>v2;
		adj[v1][v2]=1;
		cout<<"enter -1 to exit:";
		cin>>ch;
	}
	alltopologicalsort(s1);
	return 0;
}
