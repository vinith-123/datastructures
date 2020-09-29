#include<iostream>
using namespace std;
long long convert(int n,int base)
{
	if(n==0)
	return n;
	else
	return (n%base+10*convert(n/base,base));
}
int main()
{
	int n,b;
	cin>>n>>b;
	cout<<convert(n,b);
}
