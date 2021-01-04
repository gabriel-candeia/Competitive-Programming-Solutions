#include<bits/stdc++.h>
#define maxn int(1e5+1)
#define LOG 20
#define ll long long
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll dist[maxn];
ll n, q, up[maxn][LOG], ht[maxn];
array<ll,3> edge;
vector<pair<ll,ll>> adj[maxn];    

void dfs(int u, int p, int t=1){
    up[u][0] = p;
    for(int k=1;k<LOG;k++)
        if(up[u][k-1]!=-1)
            up[u][k] = up[up[u][k-1]][k-1];
    ht[u] = t;

    for(auto e:adj[u]){
        if(e.second!=p){
            if(ht[e.second]){
                edge = {u,e.second,e.first};
            }
            else{
                dist[e.second] = dist[u] + e.first;
                dfs(e.second,u,t+1);
            }
        }
    }
}

ll lift(ll u, ll x){
    for(int k=LOG-1;k>=0;k--){
        if((1<<k)<=x && up[u][k]!=-1){
            u = up[u][k];
            x -=(1<<k);
        }
    }
    return u;
}

ll lca(ll u, ll v){
    if(ht[u]<ht[v])
        swap(u,v);
    u = lift(u,ht[u]-ht[v]);
    if(u==v)
        return u;
    for(int k=LOG-1;k>=0;k--)
        if(up[u][k]!=up[v][k])
            u = up[u][k], v = up[v][k];
    return up[u][0];
}

ll distance(ll u, ll v){
    return dist[u]+dist[v]-2*dist[lca(u,v)];
}

int main(){ 
    int t;
    fastio();
    cin >> t;
    while(t--){
        edge = {-1,-1,-1};
        memset(up,-1,sizeof(up));
        memset(ht,0,sizeof(ht));
        for(int i=0;i<maxn;i++)       
            adj[i].clear();

        cin >> n >> q;
        ll x, y , w;
        for(int i=0;i<n;i++){
            cin >> x >>  y >> w;
            adj[x].push_back({w,y});
            adj[y].push_back({w,x});
        }

        for(int i=1;i<=n;i++)       
            sort(adj[i].begin(),adj[i].end());

        dfs(1,-1);

        for(int i=0;i<q;i++){
            cin >> x >> y;
            ll answ = distance(x,y);
            if(edge[0]!=-1)
                answ = min({answ,distance(x,edge[0])+distance(y,edge[1])+edge[2],distance(x,edge[1])+distance(y,edge[0])+edge[2]});
            cout << answ <<'\n';
        }
    }

    return 0;
}