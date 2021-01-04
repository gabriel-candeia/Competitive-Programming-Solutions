#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
#define LOG 20
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll up[maxn][LOG], n, ht[maxn];
vector<ll> adj[maxn];

void dfs(ll u, ll p){
    up[u][0] = p;
    for(ll k=1;k<LOG;k++)
        if(up[u][k-1]!=-1)
            up[u][k] = up[up[u][k-1]][k-1];
    if(p!=-1) ht[u] = ht[p]+1;

    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);
}

ll lift(ll u, ll x){
    for(ll k=LOG-1;k>=0;k--){
        if(up[u][k]!=-1 && (1<<k)<=x){
            u = up[u][k];
            x-=(1<<k);
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
    for(ll k=LOG-1;k>=0;k--){
        if(up[u][k]!=up[v][k]){
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}

int main(){
    //fastio();
    fstream rd, wrt;
    rd.open("dynamic.in",std::ifstream::in);
    wrt.open("dynamic.out",std::ifstream::out);
    while(rd >> n && n){
        ll x, y, w, q, root=1;
        char op;
        memset(up,-1,sizeof(up));
        memset(ht,0,sizeof(ht));
        for(int i=0;i<maxn;i++)
            adj[i].clear();

        for(ll i=0;i<n-1;i++){
            rd >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(1,-1);

        rd >> q;
        for(ll i=0;i<q;i++){
            rd >> op >> x;     
            if(op=='!'){
                root = x;
            }
            else{
                rd >> y;
                int u = lca(x,root), v = lca(y,root);
                if(u==v){   
                    wrt << lca(x,y) << '\n';
                }
                else{
                    if(ht[u]<ht[v])
                        swap(u,v);
                    wrt << u << '\n';
                }
            }
        }
    }    
    rd.close();
    wrt.close();

    return 0;
}
