#include<iostream>
using namespace std;
struct btnode
{
	int fr;
	char c;
	struct btnode *l;
	struct btnode *r;
	string code;
};
typedef struct btnode *btptr;
btptr t;
struct queue
{
	int f;
	int r;
	int size;
	btptr elements[40];
};
struct queue q;
void sort(int);
void enqueue(btptr);
btptr dequeue();
void preorder(btptr );
void assign(btptr t1,string s);
int main()
{
	int i,n,d;
	char ch;
	string s;
	s=" ";
	btptr temp,t1,t2;
	cout<<"enter the number of elements to be entered:";
	cin>>n;
	q.f=-1;
	q.r=-1;
	q.size=n;
	cout<<"enter a character  and it's frequency:";
	for(i=0;i<n;i++)
	{
	  cin>>ch>>d;
	  temp=new(btnode);
	  temp->c=ch;
	  temp->fr=d;
	  temp->l=NULL;
	  temp->r=NULL;
	  temp->code="*";
	  enqueue(temp);	
	}
	sort(q.size);
	cout<<"sorting completed"<<endl;
	for(i=0;i<n-1;i++)
	{
		t1=dequeue();
		t2=dequeue();
		temp=new(btnode);
		temp->fr=t1->fr+t2->fr;
		temp->code="-";
		temp->l=t1;
		temp->r=t2;
		enqueue(temp);
		sort(q.size-(i+1));
	}
	t=dequeue();
	assign(t,s);
	cout<<t->fr<<"is the sum of all frequencies"<<endl;
	cout<<"preorder:"<<endl;
	preorder(t);
	return 0;
	
}
void enqueue(btptr t1)
{
	if(q.f==-1)
	{
		q.f=0;
		q.r=0;
		q.elements[q.r]=t1;
	}
	else
	{
		q.r=(q.r+1)%q.size;
		q.elements[q.r]=t1;
	}
}
btptr dequeue()
{
	btptr t1;
	if(q.f==-1)
	{
		cout<<"empty";
		exit(1);
	}
	else
	{
		t1=q.elements[q.f];
		if(q.f==q.r)
		{
			q.f=-1;
			q.r=-1;
		}
		else
		{
			q.f=(q.f+1)%q.size;
		}
		return t1;
	}
}
void sort(int count)
{
		int i,j;
		btptr e1,e2;
		for(i=0;i<count;i++)
	{
		e1=dequeue();
		for(j=0;j<count-1;j++)
			{
				e2=dequeue();
				if(e2->fr>e1->fr)
				{
					enqueue(e1);
				
					e1=e2;
				}
				else
				enqueue(e2);			
			}
			enqueue(e1);
	}
}
void preorder(btptr t1)
{
	if(t1!=NULL)
	{
		if(t1->c!=NULL)
		{
		cout<<t1->c<<" "<<t1->fr<<" "<<t1->code<<endl;
	    }
	    else
	    {
	    	cout<<t1->c<<" "<<t1->fr<<endl;
		}
		preorder(t1->l);
		preorder(t1->r);
	}
}
void assign(btptr t1,string s)
{
	if(t1!=NULL)
	{
		if(t1->l==NULL)
		{
			t1->code=s;
		}
		if(t1->r==NULL)
		{
			t1->code=s;
		}
		if(t1->l!=NULL)
		{
			t1->code=s+"0";
			assign(t1->l,t1->code);
		}
		if(t1->r!=NULL)
		{
			t1->code=s+"1";
			assign(t1->r,t1->code);
		}
	}
}
