#include<iostream>
usings namespace std;
typedef struct add {
	int data;
	struct add *ad;
}*aptr;
typedef struct lnode {
	struct add *con;
	struct lnode *next;
}*lptr;

typedef struct node {
	int d;
	struct node *n;
}*nptr;
void prin(nptr l) {
	nptr k;
	k = l;
	while (k != NULL)
	{
		cout << k->d << " ";
		k = k->n;
	}
}
void insend(nptr &l, int k) {
	nptr t, p;
	p = l;
	t = new(node);
	t->d = k;
	t->n = NULL;
	if (l == NULL)
		l = t;
	else {
		while (p->n != NULL)
			p = p->n;
		p->n = t;
	}
}

void create10ll(lptr &k) {
	int i = 0;
	while (i<10) {
		lptr t;
		t = new(lnode);
		t->next = NULL;
		t->con = NULL;
		if (k == NULL) {
			k = t;
		}
		else {
			lptr p = k;
			while (p->next != NULL)
				p = p->next;
			p->next = t;
		}
		i++;
	}
}
void addi(lptr &s, int x) {
	aptr t = new(add);
	t->data = x;
	t->ad = NULL;
	aptr d = s->con;
	if (s->con == NULL)
		s->con = t;
	else {
		while (d->ad != NULL) 
			d = d->ad;
			d->ad = t;	
	}
}

void emptyll(lptr &s, nptr &p) {
	
	while (s != NULL) {
		aptr a = s->con;
		while (a != NULL) {
			int k = a->data;
			insend(p, k);
			a = a->ad;
		}
		s = s->next;
	}
}
void radix(nptr &p, int n)
{
	lptr ll= NULL;
	int i = 0, j, m = 10, q = 1, x, y;
	while (i<n) {
		create10ll(ll);
		lptr s = ll;
		
		while (p != NULL) {
			x = p->d;
			x = x%m;
			x = x / q;
			j = 0;
			while (j<x)
			{
				s = s->next;
				j++;
			}
			addi(s, p->d);
			s = ll;
			p = p->n;
		}
		q = q * 10;
		m = m * 10;
		i++;
		emptyll(ll, p);
	}
}
int main() {
	nptr l;
	l = NULL;
	int n, k;
	cout << "enter no of ele and ele\n";
	cin >> n;
	int max = 0;
	for (int i = 0; i<n; i++) {
		int j = 0;
		cin >> k;
		insend(l, k);
		while (k>0)
		{
			k = k / 10;
			j++;
		}
		if (j > max)
			max = j;;
	}
	radix(l, max);
	prin(l);
}
