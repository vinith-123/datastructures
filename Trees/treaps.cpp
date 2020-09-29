#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct tnode
{
    int key, priority;
    tnode *left, *right;
}*tptr;
tptr getnewnode(int key,int p)
{
    tptr temp = new tnode;
    temp->key = key;
    temp->priority = p;
    temp->left = temp->right = NULL;
    return temp;
} 
void rightrotate(tptr &y)
{
    tptr x = y->left;
	tptr T2 = x->right;
    x->right = y;
    y->left = T2;
    y=x;
}
void leftrotate(tptr &x)
{
   tptr y = x->right;
   tptr  T2 = y->left;
    y->left = x;
    x->right = T2;
 	x = y;
}
void insert(tptr &T, int key,int p)
{
    if (T==NULL)
    {
    	T= getnewnode(key,p);
    	return;
	}
    if (key <T->key)
    {
        cout<<"Insert in left subtree :"<<endl;
        insert(T->left, key,p);
        if (T->left->priority > T->priority)
            rightrotate(T);
    }
    else
    {
         cout<<"Insert in right subtree :"<<endl;
        insert(T->right, key,p);
        if (T->right->priority > T->priority)
            leftrotate(T);
    }
    return;   
}
void inorder(tptr root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        cout << "key: "<< root->key << " | priority: "<< root->priority<<endl;
        inorder(root->right);
    }
}
void preorder(tptr root)
{
    if (root!=NULL)
    {
    	 cout << "key: "<< root->key << " | priority: "<< root->priority<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(tptr root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << "key: "<< root->key << " | priority: "<< root->priority<<endl;
    }
}
struct queue
{
int front;
int rear;int size;
tptr elements[50];
};
struct queue q;
void enqueue(queue &q,tptr x)
{
	if(((q.rear+1)%q.size)==q.front)
	cout<<"queue is full"<<endl;	
	else
	{
		if(q.front==-1) q.front =0;
		q.elements[(++q.rear%q.size)]=x;
	}
}
tptr dequeue(queue &q)
{tptr t;
	if(q.front==-1)
	cout<<"queue is empty"<<endl;	
	else
	{
	 t=q.elements[q.front];
	 if(q.front==q.rear)
	 {
	 	q.front=-1; q.rear =-1;
	 }
	 else
	 {
	 	q.front=(q.front+1)%q.size;
	 } 	
	}
	return t;
}
bool isempty(queue &q)
{

	if(q.front==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int size(queue q)
{
	
	return q.rear+1;
}
tptr y = new tnode;

tptr t1;
void levelorder(tptr T)
{
	y->key = '*';
	y->left =  NULL;
	y->right = NULL;
enqueue(q,T);
enqueue(q,y);
while (!isempty(q))
    { 
	    
	  t1 = dequeue(q);
	  if(q.rear==-1)
	  {
	  	break;
	  }
	  if(t1->key!='*')
	  {
	  	cout<<t1->key<<" ";
	  }
	  else
	  {
	  	cout<<endl;
	  	enqueue(q,y);
	  }
       if (t1->left!=NULL)
       {
         enqueue(q,t1->left);
       }
       if (t1->right!=NULL)
       {
           enqueue(q,t1->right);
       }    
}   
}
int main()
{
	q.front =-1;
	q.rear =-1;
	q.size  = 55;
    tptr T = NULL;
   int n,x;
   char ch;
   do
   {
   	cout<<"enter the numbers:"<<endl;
   	cin>>n;
   	cin>>x;
   	insert(T,n,x);
   	cout<<"do u want to continue :"<<endl;
   	cin>>ch;
   }while(ch=='y');
    cout << "Inorder traversal of the given tree \n";
    inorder(T);
    cout<<"the level order is : "<<endl;
    levelorder(T);
    cout<<endl<<"the preorder is :"<<endl;
    preorder(T);
     cout<<endl<<"the postorder is :"<<endl;
    postorder(T);
    return 0;
}
