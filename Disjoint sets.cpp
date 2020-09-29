#include<iostream>
using namespace std;
int S[100];
int find(int i)
{
	if(S[i]==0)
	return i;
	else
	return find(S[i]);
}
void u(int i,int j)
{
	if(S[i]==0)
	S[i]=j;
	else if(S[j]==0)
	S[j]=i;
	else
	S[find(i)]=j;
}
bool check(int u,int v)
{
	if(find(u)==find(v))
	return true;
	else
	return false;
}
int main()
{
	int e1,e2,ch=1;
	while(ch!=3)
	{
		cout<<"select your choice 1.add 2.check3.exit::";
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"enter the elements to be added";
			cin>>e1>>e2;
			u(e1,e2);
			break;
			case 2:
			cout<<"enter the elements to be checked:";
			cin>>e1>>e2;
			if(check(e1,e2))
			cout<<"yes!They are in same set\n";
			else
			cout<<"No!They are not in same set\n";
			break;
			Default:
			break;
		}
	}
	return 0;
}
