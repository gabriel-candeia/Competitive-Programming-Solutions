#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define LOG 21
using namespace std;

int ht[maxn], parent[maxn][LOG];
vector<int> adj[maxn];

void dfs(int u, int p){
    if(p!=-1) ht[u] = ht[p]+1;
    parent[u][0] = p;
    for(int k=1;k<LOG && parent[u][k-1]!=-1;k++)
        parent[u][k] = parent[parent[u][k-1]][k-1];
    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);
}

int lift(int u, int x){
    for(int k=LOG-1;k>=0;k--)
        if(x>=(1<<k) && parent[u][k])
            u = parent[u][k], x -= (1<<k);
    return u;
}

int lca(int u, int v){
    if(ht[v]<ht[u])
        swap(u,v);
    v = lift(v,ht[v]-ht[u]);
    if(v==u) return v;
    for(int k=LOG-1;k>=0;k--)
        if(parent[u][k]!=parent[v][k])
            u = parent[u][k], v = parent[v][k];
    return parent[u][0];
}

int dist(int u,int v){
    return ht[u]+ht[v]-2*ht[lca(u,v)];
}


int main(){
    int n, q;

    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1,-1);
    
    cin >> q;
    for(int i=0;i<q;i++){
        int a, b, x, y, k;
        int d1, d2;
        cin >> x >> y >> a >> b >> k;
        d1 = dist(a,b);
        d2 = min(dist(a,x)+dist(y,b)+1,dist(a,y)+dist(x,b)+1);
        if((d1%2==k%2 && d1<=k)||(d2%2==k%2 && d2<=k))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';  
    }
    return 0;
}