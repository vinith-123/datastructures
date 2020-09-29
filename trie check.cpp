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
int getindex(char str1[],int ind,int len)
{
	for(int i=0;i<len;i++)
	if(str1[i]-'a'==ind)
		return str1[i+1]-'a';
}
void insert(ptr &T,char s[])
{
	int x=0,ind=s[x]-'a';
	while(1)
	{
		if(T->u.letter[ind])
		{
			if(T->u.letter[ind]->tag==1)
			{
				char str1[10];
				ptr temp1,temp2,temp3;
				temp1=T->u.letter[ind];
				strcpy(str1,temp1->u.str);
				temp2=new(trnode);
				temp2->tag=0;
				for(int i=0;i<26;i++)
				temp2->u.letter[i]=NULL;
				temp2->u.letter[getindex(str1,ind,strlen(str1))]=temp1;
				temp3=new(trnode);
				temp3->tag=1;
				strcpy(temp3->u.str,s);
				temp2->u.letter[s[ind+1]-'a']=temp3;
				T->u.letter[ind]=temp2;
				break;
			}
			else
			{
				ind=s[++x]-'a';
				T=T->u.letter[ind];
			}
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
bool search(ptr T,char s[])
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
	return false;
}
void levelorder(ptr T)
{
	
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
		if(search(T,s))
		cout<<"Found!\n";
		else
		cout<<"Not Found!\n";
		cout<<"enter -1 to exit:";
		cin>>ch;
	}	
	return 0;
}
