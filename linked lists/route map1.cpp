#include<iostream>
#include<cstring>
using namespace std;
typedef struct mlnode
{
	char data;
	int n;
	struct mlnode **next;
}*mptr;int len;
void create(mptr &m, char *ch) {
	static int i = 0;
	if (ch[i] == NULL)
		return;
	mptr t = new(mlnode);
	if (isalpha(ch[i]) && ch[i + 1] != '(') {
		t->data = ch[i];
		t->next = new mlnode*[1];
		t->n = 1;
		t->next[0] = NULL;
		if (m == NULL)
		m = t;
		else {
			mptr p = m;
			while (p->next[0] != NULL)
				p = p->next[0];
			p->next[0] = t;
		}
		i++;
		create(m, ch);
	}
	else if (ch[i] == ')')
		return;
	else if (ch[i + 1] == '(') {
		t->data = ch[i];
		t->next = new mlnode*[2];
		t->next[0] = NULL;
		t->next[1] = NULL;
		t->n = 2;
		if (m == NULL)
			m = t;
		else {
			mptr p = m;
			while (p->next[0] != NULL)
				p = p->next[0];
			p->next[0] = t;
		}
		i = i + 2;
		create(t->next[0], ch);
		i = i + 2;
		create(t->next[1], ch);
		i++;
		create(m, ch);
	}
}

void prinf(mptr h,mptr k){
char ch[15];int i=0;
	while(h->n!=2){
		ch[i]=h->data;
		h=h->next[0];
		i++;
	}
	ch[i]=h->data;	
	i++;
	ch[i]='\0';
	int flag=0;
	if(k->data==h->data)
	flag=1;
	if(flag==0)
	{
		for(int i=0;ch[i]!='\0';i++)
		cout<<ch[i]<<" ";
	}
}
void print(mptr m, mptr l) 
{
	while (m != l)
	{
		cout << m->data << " ";
		m = m->next[0];
	}
	if(m!=NULL)
	cout << m->data<<" ";
}

void prin(mptr m, mptr h) {
	mptr p = m;
	if (p != NULL) {
		while (p->n != 2) {
			p = p->next[0];
			if (p == NULL)
				break;
		}
	}
	print(m, p);
	if (p == NULL)
		return;
	prin(p->next[0], h);
	cout << endl;
		prinf(h,p);
	print(m, p);
	prin(p->next[1], h);
}
int main() {
	mptr m = NULL;
	char ch[50];
	cout << "enter the exp\n";
	cin >> ch;
	len=strlen(ch);
	create(m, ch);
	mptr l = m;
	prin(m, l);
	return 0;
}
