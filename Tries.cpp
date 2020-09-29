#include<iostream>
#include<cstring>
using namespace std;
typedef struct trnode{
	int tag;
	union u1{
		struct trnode *letter[26];
		char str[10];
	}u;
}*ptr;
void insert(ptr &T,char s[])
{
	int x=0,ind=s[x]-'a';
	while(1)
	{
		if(T->u.letter[ind])
		{
			T=T->u.letter[ind];
			ind=s[++x]-'a';
		}
		else
		{
			ptr temp=new(trnode);
			temp->tag=1;
			strcpy(temp->u.str,s);
			T->u.letter[ind]=temp;
			break;
		}
	}
}
bool search(ptr T,char s[],int n)
{
	int x=0,ind=s[x]-'a';
	while(T!=NULL)
	{
		if(T->tag==0)
		{
			if(T->u.letter[ind])
			{
				T=T->u.letter[ind];
				ind=s[++x]-'a';
			}
			else
			return false;
		}
		else
		{
			if(!strcmp(s,T->u.str))
			return true;
			else
			return false;
		}
	}
}
int main()
{
	char s[10];int ch=1;
	ptr T=new(trnode),temp=new(trnode);
	temp->tag=1;
	T->tag=0;
	for(int i=0;i<26;i++)
	T->u.letter[i]=NULL;
	while(ch!=-1)
	{
		cout<<"enter the name to be inserted:";
		cin>>s;
		insert(T,s);
		cout<<"enter -1 to exit:";
		cin>>ch;
	}
	ch=1;
	while(ch!=-1)
	{
		cout<<"enter the name to be searched:";
		cin>>s;
		if(search(T,s,2))
		cout<<"Found!\n";
		else
		cout<<"Not Found!\n";
		cout<<"enter -1 to exit:";
		cin>>ch;
	}	
	return 0;
}
