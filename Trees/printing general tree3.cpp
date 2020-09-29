#include<iostream>
using namespace std;
typedef struct gnode {

	struct gnode *fsibling;
	char data;
	struct gnode *nsibling;
}*gptr;

void create(gptr &g,char* ch){
	static int i=1;
	if(ch[i]=='\0')
	return;
	else{
	
		if(ch[i]=='(')
		{i++;
	
		create(g->fsibling,ch);
		
	create(g,ch);
     	}
		else if(isalpha(ch[i]))
		{
		gptr k=new(gnode);
		k->fsibling=k->nsibling=NULL;
		k->data=ch[i];
		if(g!=NULL)
		{
	
		gptr t=g;
		while(t->nsibling!=NULL)
		t=t->nsibling;
		t->nsibling=k;
		i++;
		create(k,ch);
	
	   }
	   else
	   {
	   g=k;
	   
		i++;
		create(g,ch);
	}
		}
		else{
			i++;
			return;
		}
		
		
		
	}
}

void print(gptr g)
{
	if(g==NULL){
	return;}
	cout<<g->data;
	
	print(g->fsibling);
	
	print(g->nsibling);
	

}

int main(){
	gptr g=NULL;
	char ch[50];
	cout<<"enter the seq\n";
	cin>>ch;
	create(g,ch);
	gptr t = g;
	
	//cout<<g->data;
	///g=g->fsibling;
	//while(g!=NULL)
//	{
//		cout<<g->data<<" ";
//		g= g->nsibling;
//	}
	
	
	cout<<"level order is : "<<endl;
		cout<<t->data;
		cout<<endl;
	while(t!=NULL)
	{
	
		
		for(gptr temp = t->fsibling;temp!=NULL;temp=temp->nsibling)
		{
			cout<<temp->data;
		}
		cout<<endl;
		t=t->fsibling;
	}
	cout<<"preorder is :"<<endl;
print(g);
}

