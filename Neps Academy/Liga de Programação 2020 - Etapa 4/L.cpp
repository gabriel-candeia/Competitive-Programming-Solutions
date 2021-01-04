#include<bits/stdc++.h>
#define N 1e5+5
using namespace std;

struct node{
    node *l, *r;
    int aparece, repete;
    
    node(int x=0, int y=0){
        l = r = NULL;
        aparece = x;
        repete = y;
    }
};

void build(node *p, int l, int r){
    if(l==r){
        return;
    }
    int med = (l+r)/2;
    p->l = new node();
    p->r = new node();
    build(p->l,l,med);
    build(p->r,med+1,r);
}

void update(node *last, node *current, int l, int r, int i){
    if(l==r){
        current->aparece+=(current->aparece==0);
        current->repete+=(current->repete==0 && current->aparece==1)
    }
    int med = (l+r)/2;
    if(i<=med){
        current->r = last->r;
        current->l = new node(last->l->aparece,last->l->repete);
        update(last->l,current->l,l,med,i);
    }
    else{
        current->l = last->l;
        current->r = new node(last->r->aparece,last->r->repete);
        update(last->r,current->r,med+1,r,i);
    }
    current->aparece = current->l->aparece + current->r->aparece;
    current->repete = current->l->repete + current->r->repete;
}

int get(node *last, node *current, int l, int r, int i, int j){
    if(j<l || r<i){
        return 0;
    }
    else if(i<=l && r<=j){
        return current->aparece-last->aparece + current->repete;
    }
    
}

int main(){


    return 0;
}