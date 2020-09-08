#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define maxn int(3e5+5)
#define maxm 20
using namespace std;

const int inf = 1e9;
vector<vector<pair<int,int>>> adj;
int n, m, up[maxn][maxm], best[maxn][maxm], h[maxn];

void dfs(int u, int p, int wt, int ht){
    up[u][0] = p; best[u][0] = wt; h[u] = ht;
    for(int k=1;k<maxm;k++){
        if(up[u][k-1]!=-1){
            up[u][k] = up[up[u][k-1]][k-1];
            best[u][k] = min(best[u][k-1],best[up[u][k-1]][k-1]);
        }
    }

    for(auto e:adj[u])
        if(e.first!=p)
            dfs(e.first,u,e.second,ht+1);
}

int lift(int u, int c, int &mn){
    for(int k=maxm-1;k>=0;k--){
        if((1<<k)<=c && up[u][k]!=-1){
            mn = min(mn,best[u][k]);
            u = up[u][k];
            c-=(1<<k);
        }
    }
    return u;
}

int lca(int u, int v){
    if(h[v]<h[u]){
        swap(u,v);
    }
    int mn = inf;
    v = lift(v,h[v]-h[u],mn);
    if(u==v)
        return mn;
    for(int k=maxm-1;k>=0;k--){
        if(up[v][k]!=up[u][k]){
            mn = min({best[v][k],best[u][k],mn});
            u = up[u][k];
            v = up[v][k];
        }
    }   
    return min({mn,best[v][0],best[u][0]});
}

int main(){
    fastio();
    int x, y, z;
    cin >> n >> m;

    adj.assign(n+1,vector<pair<int,int>>());
    for(int i=0;i<m;i++){
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    memset(up,-1,sizeof up);
    memset(best,inf,sizeof best);
    memset(h,0,sizeof h);
    dfs(1,-1,inf,0);


    int q, a, b;
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << lca(a,b) << '\n';
    }

    return 0;
}
