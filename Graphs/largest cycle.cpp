#include<iostream>
using namespace std;
int main()
{
	int i,j,v,ch=1,v1,v2,row=-1,column,index;
	string s="",largests="";
	cout<<"enter no of vertices:";
	cin>>v;
	int g[v][v];
	for(i=0;i<v;i++)
	{
		for( j=0;j<v;j++)
		g[i][j]=0;
	}
	g[0][1]=g[0][3]=g[1][2]=g[1][4]=g[2][0]=g[2][3]=g[4][3]=1;
/*	while(ch!=-1)
	{
		cout<<"enter the edge vertices:";
		cin>>v1>>v2;
		g[v1][v2]=1;
		cout<<"enter -1 to exit:";
		cin>>ch;
	}*/
	for(int i=0;i<v;i++)
	{
		j=0;index=i;
		while(j!=v)
		{
			while(g[index][j]!=1 && j!=v && j > row)
			j++;
			if(j==v)
			break;
			else
			{
				s+=index+48;
				index=j;
				if(index==i)
				{
					cout<<s<<endl;
					if(s.length() > largests.length())
					{
						largests="";
						largests+=s;
					}
					s="";
					break;
				}
				j=0;
			}
		}
		row=i;
	}
	cout<<"yes"<<endl;
	cout<<largests<<endl;
	return 0;
}
