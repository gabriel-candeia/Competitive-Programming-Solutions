#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

struct node{
    node *l, *r;
    int x;

    node(int v=0){
        l = r = NULL, x = v; 
    }

    node(node *lc, node *rc){
        l = lc, r = rc, x = 0;
        if(l) x += l->x;
        if(r) x += r->x;
    }
};

int n, block;
vector<int> arr, nxt, last;
vector<node*> roots; 

node* build(int l, int r){
    if(l==r)
        return new node((l==n+1)||(l==last[arr[l]]));
    int med = l + (r-l)/2;
    return new node(build(l,med),build(med+1,r));
}

node* update(node *prev, int l, int r, int i, int v){
    if(l==r)
        return new node(v+prev->x);
    int med = l + (r-l)/2;
    if(i<=med)
        return new node(update(prev->l,l,med,i,v),prev->r);
    return new node(prev->l,update(prev->r,med+1,r,i,v));
}

int get(node *p, int l, int r, int k){
    if(l==r)
        return l;
    int med = l + (r-l)/2;
    if(k<=p->l->x)
        return get(p->l, l, med, k);
    return get(p->r,med+1,r,k-p->l->x);
}

int main(){
    fastio();
    cin >> n;
    arr.assign(n+1,0); 
    last.assign(n+1,n+1);
    nxt.assign(n+1,n+1); 
    for(int i=1;i<=n;i++)
        cin >> arr[i];

    for(int i=n;i;i--){
        nxt[i] = last[arr[i]];
        last[arr[i]] = i;
    }
    
    roots.push_back(build(1,n+1));
    for(int i=1;i<=n;i++){
        roots.push_back(update(roots[i-1],1,n+1,i,-1));
        if(nxt[i]!=n+1) 
            roots[i] = update(roots[i],1,n+1,nxt[i],1);
    }
    
    for(int k=1;k<=n;k++){
        int cnt = 0;
        for(int i=1;i<=n;i=get(roots[i-1],1,n+1,k+1), cnt++);
        cout << cnt << " ";
    }cout<<'\n';

    return 0;
}