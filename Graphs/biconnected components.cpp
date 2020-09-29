#include<iostream>
using namespace std;
int adj[100][100],count=1,flag[100];
struct stack{
	int top;
	int size;
	int elements[100];
}s;
void push(int n)
{
	if(s.top!=s.size)
	s.elements[++s.top]=n;
}
int pop()
{
	if(s.top!=-1)
	return s.elements[s.top--];
}
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
	flag[0]=1;
	else
	flag[0]=0;
}
void dft1(int v1,int n)
{
	v[v1].visited=1;
	for(int i=0;i<n;i++)
	{
		if(adj[v1][i] && !v[i].visited)
		dft1(i,n);
	}
		int ele=v1;
		if(flag[ele]==1)
		{
			cout<<ele<<" ";
			ele=pop();
			while(s.top!=-1 || flag[ele]!=1)
			{
				cout<<ele<<" ";
				ele=pop();
			}
			if(flag[ele]==1)
			push(ele);
			push(v1);
			cout<<endl;
		}
		else
		push(ele);
}
int main()
{
	s.top=-1;s.size=100;
	int v1,v2,ch=1,n,x=0;
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
	for(int i=0;i<n;i++)
	v[i].visited=0;
	dft1(0,n);
	while(s.top!=-1)
	cout<<pop()<<" ";
	return 0;
}
