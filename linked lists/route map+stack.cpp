#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
struct mlnode{
    int tag;
    union u{
        char c;
        struct mlnode *ml = NULL;
    }data;
    struct mlnode *next = NULL;
};

typedef struct mlnode* mlptr;

struct stck{
    int sz = 50;
    int top = -1;
    char elmts[50];
};

    bool stkfull(stck *s){
        return (s->top == s->sz-1);
    }
    bool stkempty(stck *s){
        if(s->top == -1)
            return true;
        else
            return false;
    }

    void push(stck *s, char n){
        if(!stkfull(s))
            s->elmts[++(s->top)] = n;
        else
            cout << "Stack already full" << endl;
    }

    char pop(stck *s){
        if(!stkempty(s)){
            return s->elmts[s->top--];
        }
        else{
            return '\0';
        }
    }

    char peep(stck *s){
        if(!stkempty(s)){
            return s->elmts[s->top];
        }else{
            return '\0';
        }
    }


int print(mlptr ml, int i, stck s){
    mlptr head = ml;
    start:
    ml = head;

    while(ml != NULL){
        if(ml->tag == 1){
            push(&s, ml->data.c);
            if(ml->next == NULL){
            }
        }
        else if(ml->tag == 2){
            print(ml->data.ml, i, s);
        }

        ml = ml->next;
    }

    string strans = "";
    for(; s.top != -1;){
        strans = strans + pop(&s) + " ";
    }
    for(int i = strans.length()-1 ; i >= 0 ; i--){
        cout << strans[i];
    }
    cout << endl;
}


string rest(string str){
    int cntr = 0;
    string ans = "";
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '('){
            cntr++;
        }
        else if(str[i] == ')'){
            cntr--;
        }
        ans = ans + str[i];
        if(cntr == 0)
            return ans;
    }
}

mlptr create(string str, mlptr ml){
    mlptr t =NULL, head = NULL;

    for(int i = 0 ; i < str.length() ; i++){
        t = new(mlnode);
        if(ml == NULL){
            if('a' <= str[i] && 'z' >= str[i]){
                t->tag =1;
                t->data.c = str[i];
                t->next = NULL;
                ml = t;
                head = ml;
            }
        }
        else{
            if(str[i] == '('){
                t->tag = 2;
                string temp = "";
                int nt = i;
                for(int nt = i ; nt < str.length() ; nt++)
                    temp = temp + str[nt];
                string cur = rest(temp);
                t->data.ml = create(cur, t->data.ml);
                i += cur.length();
                t->next = NULL;
                ml->next = t;
                ml = ml->next;
            }
            else if('a' <= str[i] && 'z' >= str[i]){
                t->tag =1;
                t->data.c = str[i];
                t->next = NULL;
                ml->next = t;
                ml = ml->next;
            }
            else if(str[i] == ')'){
                free(t);
                return head;
            }
        }
    }
}
int main()
{
    mlptr ml = NULL;
    string str = "(a, b, c,(j, (m, n, o) k, l), d, e, (f, g), h, i)";
    ml = create(str, ml);
    stck s;
    int i = 0;
    print(ml, i, s);


    return 0;
}
