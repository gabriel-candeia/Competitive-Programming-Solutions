#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define LOG 20
#define ll long long
using namespace std;

ll parent[maxn], rnk[maxn];
void build(){
    for(ll i =0;i<maxn;i++)
        parent[i] = i;
}

ll find(ll x){
    return ((parent[x]==x) ? x : parent[x] = find(parent[x]));
}

bool _union(ll x, ll y){
    x = find(x);
    y = find(y);
    if(x!=y){
        if(rnk[x]>rnk[y]){
            parent[y] = x;
        }
        else{
            parent[x] = y;
            rnk[y] += (rnk[x]==rnk[y]);
        }
        return true;
    }
    return false;
}


ll up[maxn][LOG], n, m, wt[maxn][LOG], h[maxn];
vector<vector<pair<ll,ll>>> adj;
void dfs(ll u, ll p, ll w, ll ht=0){
    up[u][0] = p; wt[u][0] = w;
    h[u] = ht;
    for(ll k=1;k<LOG;k++){
        if(up[u][k-1]!=-1){
            up[u][k] = up[up[u][k-1]][k-1];
            wt[u][k] = max(wt[u][k-1],wt[up[u][k-1]][k-1]);
        }
    }

    for(auto e:adj[u])
        if(e.first!=p)
            dfs(e.first,u,e.second,ht+1);
}

ll lift(ll u, ll x, ll &w){
    for(ll k=LOG-1;k>=0;k--){
        if(up[u][k]!=-1 && (1<<k)<x){
            w = max(w,wt[u][k]);
            u = up[u][k];
            x-=(1<<k);
        }
    }
    return u;
}

ll lca(ll u, ll v){
    ll answ = -1;
    if(h[u]<h[v])
        swap(u,v);
    u = lift(u,h[u]-h[v],answ);
    if(u==v)
        return answ;
    for(ll k=LOG-1;k>=0;k--){
        if(up[v][k]!=-1 && up[u][k]!=-1 && up[v][k]!=up[u][k]){
            answ = max({answ,wt[u][k],wt[v][k]});
            u = up[u][k]; v = up[v][k];
        }
    }
    return max({answ,wt[u][0],wt[v][0]});
}

int main(){
    ll x, y, w;
    cin >> n >> m;

    vector<tuple<ll,ll,ll>> edges;
    for(ll i=0;i<m;i++){
        cin >> x >> y >> w;
        edges.push_back({w,x,y});
    }

    sort(edges.begin(),edges.end());
    adj.assign(n+1,vector<pair<ll,ll>>());
    vector<bool> used;
    build();
    for(auto e:edges){
        tie(w,x,y) = e;
        if(_union(x,y)){
            adj[x].push_back({y,w});
            adj[y].push_back({x,w});
            used.push_back(true);
        }
        else{
            used.push_back(false);
        }
    }

    memset(up,-1,sizeof(up));
    dfs(1,-1,-1);

    ll answ = 0;
    for(ll i=0;i<m;i++){
        tie(w,x,y) = edges[i];
        if(!used[i]){
            //cout << x << " " << y << " " << h[x] << " "<< h[y] <<'\n';
            answ += max(lca(x,y)+1-w,0ll);
        }
    }

    cout << answ <<'\n';
    return 0;
}