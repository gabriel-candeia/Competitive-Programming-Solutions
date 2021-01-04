#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int n, start[maxn], last[maxn], st[4*maxn], lazy[4*maxn], color[maxn];
vector<int> adj[maxn], arr;

void dfs(int u, int p){
    arr.push_back(u);
    start[u] = arr.size()-1;

    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);
    
    last[u] = arr.size()-1;
}

int build(int p, int l, int r){
    if(l==r)
        return st[p] = color[arr[l]];
    int med = l + (r-l)/2;
    return st[p] = build(2*p,l,med)+build(2*p+1,med+1,r);
}

void push(int p, int l, int r){
    if(lazy[p]){ 
        st[p] = (r-l+1 - st[p]);
        if(l!=r){
            lazy[2*p] = (lazy[2*p]+1)%2;
            lazy[2*p+1] = (lazy[2*p+1]+1)%2;
        }
        lazy[p] = 0;
    }
}

int get(int p, int l, int r, int x, int y){
    push(p, l, r);
    if(y<l || r<x)
        return 0;
    if(x<=l && r<=y)
        return st[p];
    int med = l + (r-l)/2;
    return get(2*p,l,med,x,y)+get(2*p+1,med+1,r,x,y);
}

int update(int p, int l, int r, int x, int y){
    push(p, l, r);
    if(y<l || r<x)
        return st[p];
    if(x<=l && r<=y){
        lazy[p] = 1;
        push(p, l, r);
        return st[p];
    }
    int med = l + (r-l)/2;
    return st[p] = update(2*p,l,med,x,y)+update(2*p+1,med+1,r,x,y);
}

int main(){
    fastio();
    int x, y, q;
    string op;
    cin >> n;

    for(int i=2;i<=n;i++){
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    for(int i=1;i<=n;i++)
        cin >> color[i];

    dfs(1,-1);
    build(1,0,n-1);
    
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> op >> x;
        if(op == "get")
            cout << get(1,0,n-1,start[x],last[x]) << '\n';
        else
            update(1,0,n-1,start[x],last[x]);
    }

    return 0;
}