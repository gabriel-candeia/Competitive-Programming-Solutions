#include<bits/stdc++.h>
#define N int(1e5)+3
using namespace std;

int arr[N];
map<int,int> compress, decompress;
struct node{
    node *l, *r;
    int v;

    node(){
        l = r = NULL;
        v = 0;
    }
};

void build(node *p, int l, int r){
    if(l==r){
        p->v = 0;
        return;
    }
    int med = (l+r)/2;
    p->l = new node(); 
    p->r = new node(); 
    build(p->l,l,med);
    build(p->r,med+1,r);
    p->v = p->l->v+p->r->v;
}

void update(node *last, node *current, int l, int r, int i, int k){
    if(l==r){
        current->v+=k;
        return;
    }
    int med = (l+r)/2;
    if(i<=med){
        current->r = last->r;
        current->l = new node();
        update(last->l,current->l,l,med,i,k);
    }
    else{
        current->l = last->l;
        current->r = new node();
        update(last->r,current->r,med+1,r,i,k);
    }
    current->v = current->l->v+current->r->v;
}

int get(node *last, node * current, int l, int r, int k){
    if(l==r){
        return decompress[l];
    }
    int cmp = current->l->v-last->l->v, med = (l+r)/2;
    if(k<=cmp){
        return get(last->l,current->l,l,med,k);
    }
    return get(last->r,current->r,med+1,r,k-cmp);
}

int main(){
    int n, m, l, r, k;

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        compress[arr[i]];
    }
    int cnt = 0;
    for(auto& p:compress){
        p.second = cnt;
        decompress[cnt++] = p.first;
    }
    vector<node*> root;
    root.push_back(new node());
    build(root[0],0,n-1);
    for(int i=1;i<=n;i++){
        arr[i] = compress[arr[i]];
        root.push_back(new node());
        update(root[i-1],root[i],0,n-1,arr[i],1);
    }

    for(int i=0;i<m;i++){
        cin >> l >> r >> k;
        cout << get(root[l-1],root[r],0,n-1,k) << '\n';
    }

    return 0;
}