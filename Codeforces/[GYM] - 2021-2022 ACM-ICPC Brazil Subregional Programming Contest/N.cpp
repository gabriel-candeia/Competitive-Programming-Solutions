#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
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
    if(l==r){
        p->v = 0;
        return;
    }
    int med = (l+r)/2;
    p->l = new node();
    p->r = new node();
    build(p->l,l,med);
    build(p->r,med+1,r);
    p->v = p->l->v + p->r->v;
}

void update(node *last, node *current, int l, int r, int i, int v){
    if(l==r){
        current->v += v;
        return;
    }
    int med = (l+r)/2;
    if(i<=med){
        current->r = last->r;
        current->l = new node(last->l->v);
        update(last->l,current->l,l,med,i,v);
    }
    else{
        current->l = last->l;
        current->r = new node(last->r->v);
        update(last->r,current->r,med+1,r,i,v);
    }
    current->v = current->l->v + current->r->v;
}

ll get(node *last, node *current, int l, int r, int i, int j){
    if(r<i || j<l)
        return 0;
    if(i<=l && r<=j){
        return current->v-last->v;
    }
    int med = (l+r)/2;
    return get(last->l,current->l,l,med,i,j)+ get(last->r,current->r,med+1,r,i,j);
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    
    vector<int> arr;
    arr.assign(n+1,0);
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    
    vector<node*> roots;
    roots.push_back(new node());
    build(roots[0],0,maxn);
    for(int i=1;i<=n;i++){
        roots.push_back(new node());
        update(roots[i-1],roots[i],0,maxn,arr[i],1);
    }
    
    for(int i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(b>arr[a]){
            cout << get(roots[a],roots[a+c],0,maxn,b,maxn-1) << "\n";
        }
        else{
            cout << 0 <<"\n";
        }
    }

    return 0;
}