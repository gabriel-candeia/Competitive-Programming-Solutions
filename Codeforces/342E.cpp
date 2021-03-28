#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
#define maxn int(1e5+5)
#define LOG 20
using namespace std;

vector<int> adj[maxn];
int parent[maxn][LOG], ht[maxn], color[maxn], dist[maxn], n, m;

void dfs(int u, int p){
    if(p!=-1) ht[u] = ht[p]+1;
    parent[u][0] = p;
    for(int k=1;k<LOG && parent[u][k-1]!=-1;k++)
        parent[u][k] = parent[parent[u][k-1]][k-1];
    
    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);
}

int lift(int u, int h){
    for(int k = LOG-1;k>=0;k--)
        if(h>=(1<<k) && parent[u][k]!=-1)
            u = parent[u][k], h -= (1<<k);
    return u;
}

int lca(int u, int v){
    if(ht[u]<ht[v])
        swap(u,v);
    u = lift(u,ht[u]-ht[v]);
    if(u==v)
        return u;
    for(int k = LOG-1;k>=0;k--)
        if(parent[u][k]!=parent[v][k])
            u = parent[u][k], v = parent[v][k];
    return parent[u][0];
}

void bfs(){
    queue<int> q;
    int u;

    memset(dist,-1,sizeof(dist));
    for(int i=1;i<=n;i++)
        if(color[i]) 
            dist[i] = 0, q.push(i);
    
    while(q.size()){
        u = q.front(), q.pop();
        for(auto v:adj[u])
            if(dist[v]==-1)
                dist[v] = dist[u]+1, q.push(v);
    }
}

int main(){
    cin >> n >> m;

    
    for(int i=0, x, y;i<n-1;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    color[1] = 1;
    dfs(1,-1);
    const int block = sqrt(m);
    vector<int> curr;
    for(int i=0, x, y;i<m;i++){
        cin >> x >> y;
        if(x==1){
            color[y] = 1, curr.push_back(y);
        }
        if((i%block)==0){
            curr.clear(), bfs();
        }
        if(x==2){
            int answ = dist[y];
            for(auto z:curr)
                answ = min(answ,ht[z]+ht[y]-2*ht[lca(z,y)]);
            cout << answ << '\n';
        }
    }

    return 0;
}