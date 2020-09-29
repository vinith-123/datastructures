#include<iostream>
using namespace std;
typedef struct btnode{
	struct btnode *lchild;
	char data;
	struct btnode *rchild;
}*BTPTR;
string getstring(string s1,char k)
{
	int j=0;string s3="";
	while(s1[j]!=k)
	s3=s3+s1[j++];
	return s3;
}
string getstring2(string s1,char k)
{
	string s4="";int j=0;
	while(s1[j]!=k)j++;j++;
	while(j!=s1.length())
	s4+=s1[j++];
	return s4;
}
int v;
BTPTR create(string s1,string s2,string s3,string s4)
{
	s3="";s4="";
	BTPTR temp=new(btnode);temp->lchild=NULL;temp->rchild=NULL;
	temp->data=s1[v--];
	s3=getstring(s2,temp->data);
	s4=getstring2(s2,temp->data);
	if(s3=="" && s4=="")
	{
		temp->lchild=NULL;
		temp->rchild=NULL;
		return temp;
	}
	temp->rchild=create(s1,s4,s3,s4);
	s4="";
	if(s3=="" && s4=="")
	return temp;
	temp->lchild=create(s1,s3,s3,s4);
	s3="";
	if(s3=="" && s4=="")
	return temp;
}
void preorder(BTPTR T)
{
	if(T==NULL)
	return;
	else
	{
		cout<<T->data<<" ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
int main()
{
	string s1,s2,s3="",s4="";
	cout<<"enter inorder:";
	cin>>s2;
	cout<<"enter postorder:";
	cin>>s1;
	v=s1.length()-1;
	BTPTR T=NULL;T=create(s1,s2,s3,s4);
	cout<<"preorder is::";
	preorder(T);
	return 0;
}
