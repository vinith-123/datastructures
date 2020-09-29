#include<iostream>
using namespace std;
typedef struct gnode {
	int count;
	struct gnode **link;
	int data;
}*gptr;

struct queue {
	int front;
	int rear;
	gptr ele[50];
	int size;
	int empty() {
		if (front == -1)
			return 1;
		else
			return 0;
	}
	int full() {

		if (front == ((rear + 1) % size))
			return 1;
		else
			return 0;
	}
	void enq(gptr k) {
		if (full())
			cout << "full\n";
		else {
			if (empty())
				front = 0;
			rear = (rear + 1) % size;
			ele[rear] = k;
		}
	}

	void deque() {
		if (empty())
			cout << "empty\n";
		else {
			if (front == rear) {
				front = -1;
				rear = -1;
			}
			else
				front = (front + 1) % size;

		}
	}
	gptr fro() {
		if (empty())
			return NULL;
		else
			return ele[front];
	}

};

struct stack {
	int size;
	int top;
	gptr elements[50];

	int full() {
		return (top > size - 1) ? 1 : 0;
	}

	int empty() {
		if (top == -1)
			return 1;
		else
			return 0;
	}
	void push(gptr k) {
		if (full())
			cout << "stack full";
		else
			elements[++(top)] = k;
	}

	void pop() {
		if (empty())
			cout << "empty";
		else
			top--;
	}
	gptr tope() {
		if (empty())
			return NULL;
		else
			return elements[top];
	}

};

void insend(gptr &g, int p, stack &s) {

	gptr k = new(gnode);
	k->data = p;
	k->link = new gnode*[4];
	k->count = 0;
	for (int i = 0; i<4; i++)
	{
		k->link[i] = NULL;
	}
	g = k;
	s.push(g);
	cout << "does" << s.tope()->data << " have 1 child if yes press y";
	char m;
	cin >> m;

	if (m == 'y') {
		cin >> p;
		g->count = 1;
		insend(g->link[0], p, s);
	}
	else
	{
		s.pop();
		return;
	}
	cout << "does" << s.tope()->data << " have 2 child if yes press y";

	cin >> m;

	if (m == 'y') {
		cin >> p;
		g->count = 2;
		insend(g->link[1], p, s);
	}
	else
	{
		s.pop();
		return;
	}
	cout << "does" << s.tope()->data << " have 3 child if yes press y";

	cin >> m;

	if (m == 'y') {
		cin >> p;
		g->count = 3;
		insend(g->link[2], p, s);
	}
	else
	{
		s.pop();
		return;
	}
	cout << "does" << s.tope()->data << " have 4 child if yes press y";

	cin >> m;

	if (m == 'y') {
		cin >> p;
		g->count = 4;
		insend(g->link[3], p, s);
	}
	else
	{
		s.pop();
		return;
	}


}
void prinlevel(gptr g) {
	queue q;
	q.front = q.rear = -1;
	q.size = 90;
	q.enq(g);
	q.enq(NULL);
	while (!q.empty()) {
		if (q.fro() != NULL)
		{
			cout << q.fro()->data << " ";
			for (int i = 0; i<q.fro()->count; i++)
				q.enq(q.fro()->link[i]);
		}
		else
		{
			cout << endl;
			q.enq(NULL);
		}
		q.deque();
		if (q.front == q.rear)
			break;

	}
}

void print(gptr g)
{
	if(g!=NULL)
	{
		cout<<g->data<<" ";
	print(g->link[0]);
		print(g->link[1]);
			print(g->link[2]);
				print(g->link[3]);
		
		
	}
}
int main() {
	gptr g = NULL;
	stack s;
	s.top = -1;
	s.size = 100;
	
	insend(g, 5, s);
	
	//cout << g->count;
	/*cout << g->link[0]->count;
	cout << g->link[1]->count;
	cout << g->link[2]->count;*/

	//cout << endl;

	prinlevel(g);

cout<<endl<<"preorder is :"<<endl;
print(g);
}
