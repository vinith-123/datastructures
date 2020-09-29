#include<iostream>
using namespace std;
char adj[12][12];int flag[8];
void topologicalsort()
{
	int f,count=0;
	while(count!=6)
	{
		for(int i=0;i<6;i++)
		{
			if(flag[i]==0)
			{
				f=0;
				for(int j=0;j<6;j++)
				{
					if(adj[j][i]=='1')
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					cout<<i<<" ";
					flag[i]=1;
					count++;
					for(int j=0;j<6;j++)
					adj[i][j]='0';
				}
			}
		}
	}
}
int main()
{
	int ch=1,v1,v2;
	while(ch!=-1)
	{
		cout<<"enter edge vertices:";
		cin>>v1>>v2;
		adj[v1][v2]='1';
		cout<<"enter -1 to exit";
		cin>>ch;
	}
	topologicalsort();
	return 0;
}
