#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
#define LOG 20
using namespace std;

ll up[maxn][LOG], mx[maxn][LOG], parent[maxn], rnk[maxn], n, m, ht[maxn], resp[maxn];
vector<pair<ll,ll>> adj[maxn];
vector<array<ll,4>> edges;

ll find(ll x){
    return (parent[x]==x) ? x : parent[x] = find(parent[x]);
}

bool _union(ll x, ll y){
    x = find(x), y = find(y);
    if(x!=y){
        if(rnk[x]>rnk[y]){
            parent[y] = x;
        }
        else{
            parent[x] = y;
            rnk[y]+=(rnk[x]==rnk[y]);
        }
        return true;
    }
    return false;
}

ll mst(){
    ll answ = 0;
    for(ll i=0;i<maxn;i++)
        parent[i] = i;

    for(ll i=0;i<m;i++){
        if(_union(edges[i][1],edges[i][2])){
            answ += edges[i][0];
            resp[edges[i][3]] = -1;
            adj[edges[i][1]].push_back({edges[i][2],edges[i][0]});
            adj[edges[i][2]].push_back({edges[i][1],edges[i][0]});
        }
    }
    return answ;
}

void dfs(ll u, ll p){
    up[u][0] = p;
    for(ll k=1;k<LOG;k++){
        if(up[u][k-1]!=-1){
            up[u][k] = up[up[u][k-1]][k-1];
            mx[u][k] = max(mx[u][k-1],mx[up[u][k-1]][k-1]);
        }
    }

    for(auto e:adj[u]){
        if(e.first!=p){
            mx[e.first][0] = e.second;
            ht[e.first] = ht[u]+1;
            dfs(e.first,u);
        }
    }
}

ll lift(ll u, ll x, ll &wt){
    for(ll k=LOG-1;k>=0;k--){
        if(up[u][k]!=-1 && (1<<k)<=x){
            wt = max(wt,mx[u][k]);
            u = up[u][k];
            x-=(1<<k);
        }
    }
    return u;
}

ll lca(ll u, ll v){
    ll answ = 0;
    if(ht[u]<ht[v])
        swap(u,v);
    u = lift(u,ht[u]-ht[v],answ);
    if(u==v)
        return answ;
    for(ll k=LOG-1;k>=0;k--){
        if(up[u][k]!=up[v][k]){
            answ = max({mx[u][k],mx[v][k],answ});
            u = up[u][k];
            v = up[v][k];
        }
    }
    return max({answ,mx[u][0],mx[v][0]});
}

int main(){
    ll x, y, w;

    cin >> n >> m;
    for(ll i=0;i<m;i++){
        cin >> x >> y >> w;
        edges.push_back({w,y,x,i});
    }

    sort(edges.begin(),edges.end());
    ll wt = mst();
    memset(up,-1,sizeof(up));
    dfs(1,-1);
    
    for(ll i=0;i<m;i++){
        if(resp[edges[i][3]]==-1)
            resp[edges[i][3]] = wt;
        else
            resp[edges[i][3]] = wt+edges[i][0]-lca(edges[i][1],edges[i][2]);
    }
    
    for(ll i=0;i<m;i++)
        cout << resp[i] << '\n';
    return 0;
}
