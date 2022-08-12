#include<bits/stdc++.h>
#define maxn int(5e4+5)
#define ll long long
using namespace std;

int p[maxn], val[maxn], fst[maxn], lst[maxn], answ[maxn];
vector<int> adj[maxn], tour;


void solve(int u, int p){
    tour.push_back(u);
    fst[u] = tour.size()-1;

    for(auto v:adj[u]){
        if(v!=p){
            solve(v,u);
        }
    }
    lst[u] = tour.size()-1;
}

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
    int n;

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> val[i];
    }

    for(int i=1;i<=n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());
    }

    solve(1,-1);
    
    vector<node*> roots;
    roots.push_back(new node());
    build(roots.back(),1,maxn);
    for(int i=0;i<n;i++){
        roots.push_back(new node());
        update(roots[i],roots[i+1],1,maxn,val[tour[i]],1);
    }
    
    for(int i=1;i<=n;i++){
        answ[i] = tour[fst[i]+get(roots[fst[i]+1],roots[lst[i]+1],1,maxn,val[i],maxn)];
        cout << answ[i];
        if(i!=n)
            cout  << " ";
    }
    cout<<"\n";

    return 0;
}