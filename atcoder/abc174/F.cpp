#include<bits/stdc++.h>
#define N int(5e5)+5
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

struct node{
    node *l, *r;
    int v;

    node(int x=0){
        l = r = NULL;
        v = x;
    }
};

void build(node *p, int l, int r){
    if(l==r)
        return;
    int med = l + (r-l)/2;
    p->l = new node();
    p->r = new node();
    build(p->l,l,med);
    build(p->r,med+1,r);
}

void update(node *last, node *curr, int l, int r, int i, int v){
    if(l==r){
        curr->v+=v;
        return;
    }
    int med = (l+r)/2;
    if(i<=med){
        curr->r = last->r;
        curr->l = new node(last->l->v);
        update(last->l,curr->l,l,med,i,v);
    }
    else{
        curr->l = last->l;
        curr->r = new node(last->r->v);
        update(last->r,curr->r,med+1,r,i,v);
    }
    curr->v = curr->l->v + curr->r->v;
}

int get(node *last, node *curr, int l, int r, int i, int j){
    if(j<l || r<i)
        return 0;
    else if(i<=l && r<=j){
        return curr->v-last->v;
    }
    int med = l + (r-l)/2;
    return get(last->l,curr->l,l,med,i,j)+get(last->r,curr->r,med+1,r,i,j);
}

int n, arr[N], nxt[N];
vector<node*> roots;

int main(){
    fastIO();
    int q, l, r;
    map<int,int> cnt;

    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    for(int i=n;i;i--){
        nxt[i] = cnt[arr[i]];
        if(nxt[i]==0) nxt[i] = n+1;
        cnt[arr[i]] = i;
    }

    roots.push_back(new node());
    build(roots[0],0,n+1);
    for(int i=1;i<=n;i++){
        roots.push_back(new node());
        update(roots[i-1],roots[i],0,n+1,nxt[i],1);
    }

    for(int i=0;i<q;i++){
        cin >> l >> r;
        cout << get(roots[l-1],roots[r],0,n+1,r+1,n+1) << '\n';
    }

    return 0;
}