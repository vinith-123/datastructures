#include<iostream>
#include<vector>
using namespace std;
int adj[5][5];
int n=5;
/*void print(int v,bool flag[],int path[])
{
	static int index=0;int j=0;
	flag[v]=true;
	path[index++]=v;
	for(int i=0;i<5;i++)
	{
		if(g[v][i]==1 && flag[i]==false)
		print(i,flag,path);
		else if(g[v][i]==1 && flag[i]==true && i==path[0])
		{
			j=0;
			while(path[j]!=-1)
			{
				cout<<path[j]<<" ";
				path[j]=-1;
				j++;
			}
		}
		cout<<endl;
	}
}
void cycles()
{
	bool flag[5];
	for(int i=0;i<5;i++)
	flag[i]=false;
	int path[6];
	for(int k=0;k<6;k++)
	path[k]=-1;
	for(int j=0;j<5;j++)
	{
		print(j,flag,path);
	}
}*/
  void cyclesUtil(int s, vector<bool> visited, vector<int> path)
  {
    visited[s]=true;
    path.push_back(s);

    for(int i=0; i<n; i++)
    {
      if(adj[s][i]==1 && visited[i]==true && i==path[0])
      {
        for(int j=0; j<path.size(); j++)cout << path[j] << " ";
        cout << i;
        cout << endl;
      }
      else if(adj[s][i]==1 && visited[i]==false)cyclesUtil(i, visited, path);
    }
  }
  void cycles()
  {
    vector<bool> visited;
    for(int i=0; i<n; i++)visited.push_back(false);
    vector<int> path;

    for(int i=0; i<n; i++)cyclesUtil(i, visited, path);
  }
int main()
{
	int i,j,v=5,ch=1,v1,v2,row=-1,column,index;
	string s="";
	while(ch!=-1)
	{
		cout<<"enter the edge vertices:";
		cin>>v1>>v2;
		adj[v1][v2]=1;
		cout<<"enter -1 to exit:";
		cin>>ch;
	}
	cycles();
	return 0;
}
