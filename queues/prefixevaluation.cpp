#include<iostream>
using namespace std;
union u1{
	char c;
	int n;
};
struct queue{ 
	int front;
	int rear;
	int size;
	int tag[50];
union u1 elements[50];
};
bool qfull(queue &q)
{
	return (q.rear+1)%(q.size)==q.front?true:false;
}
bool qempty(queue &q)
{
	return (q.front==-1)?true:false;
}
void enqueue(queue &q,int tag,union u1 x)
{
	if(tag==1)
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%(q.size);
		q.tag[q.rear]=1;
		q.elements[q.rear].c=x.c;
	}
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%(q.size);
		q.tag[q.rear]=2;
		q.elements[q.rear].n=x.n;
	}
}
u1 dequeue(queue &q,int &check)
{
	int index;u1 k;
	if(!qempty(q))
	{
		if(q.front==q.rear)
		{
			index=q.front;
			q.rear=-1;
			q.front=-1;
			if(q.tag[index]==1)check=1;
			else check=2;
			return q.elements[index];
		}
		else
		{
			index=q.front;
			q.front=(q.front+1)%(q.size);
			if(q.tag[index]==1)check=1;
			else check=2;
			return q.elements[index];
		}	
	}
}
int main()
{
	string str;
	queue *q;
	q=new(queue);char ch,e1,e2,e3;int check1,check2,check3,i1,i2,i3,flag=0;u1 temp1,temp2,temp3,operation,answer;
	q->front=-1;q->rear=-1;q->size=50;
	cout<<"enter the prefix expression::";
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		ch=str[i];
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
		{
			q->tag[i]=1;
			q->elements[i].c=ch;
			enqueue(*q,q->tag[i],q->elements[i]);
		}
		else
		{
			q->tag[i]=2;
			q->elements[i].n=ch-48;
			enqueue(*q,q->tag[i],q->elements[i]);
		}
	}
	while(q->front!=q->rear)
	{
		if(flag==0)
		{
		temp1=dequeue(*q,check1);
		temp2=dequeue(*q,check2);
		temp3=dequeue(*q,check3);
		}
		if(check1==1 && check2==2 && check3==2)
		{
			flag=0;
			switch(temp1.c)
			{
				case '+':
					operation.n=temp2.n+temp3.n;
					enqueue(*q,2,operation);
					break;
				case '-':
					operation.n=temp2.n-temp3.n;
					enqueue(*q,2,operation);
					break;
				case '*':
					operation.n=temp2.n*temp3.n;
					enqueue(*q,2,operation);
					break;
				default:
					operation.n=temp2.n/temp3.n;
					enqueue(*q,2,operation);
					break;
			}
		}
		else
		{
			enqueue(*q,check1,temp1);
			flag=1;
			temp1=temp2;
			temp2=temp3;
			check1=check2;
			check2=check3;
			temp3=dequeue(*q,check3);
		}
	}
	switch(temp1.c)
	{
			case '+':
					operation.n=temp2.n+temp3.n;
					enqueue(*q,2,operation);
					break;
				case '-':
					operation.n=temp2.n-temp3.n;
					enqueue(*q,2,operation);
					break;
				case '*':
					operation.n=temp2.n*temp3.n;
					enqueue(*q,2,operation);
					break;
				default:
					operation.n=temp2.n/temp3.n;
					enqueue(*q,2,operation);
					break;
			}
	
	cout<<"answer="<<operation.n<<"\n";
	return 0;
}
