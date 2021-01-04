#include<bits/stdc++.h>
#define LOG 20
#define maxn int(1e4+5)
using namespace std;

int up[maxn][LOG], dist[maxn], n, ht[maxn];
vector<pair<int,int>> adj[maxn];

void dfs(int u, int p){
    up[u][0] = p;
    for(int k=1;k<LOG;k++)
        if(up[u][k-1]!=-1)
            up[u][k] = up[up[u][k-1]][k-1];

    for(auto e:adj[u]){
        if(e.first!=p){
            dist[e.first] = dist[u]+e.second;
            ht[e.first] = ht[u]+1;
            dfs(e.first,u);
        }
    }
}

int lift(int u, int x){
    for(int k = LOG-1;k>=0;k--){
        if((1<<k)<=x && up[u][k]!=-1){
            x -= (1<<k);
            u = up[u][k];
        }
    }
    return u;
}

int lca(int u, int v){
    if(ht[u]<ht[v])
        swap(u,v);
    u = lift(u,ht[u]-ht[v]);
    if(u==v)
        return u;
    for(int k=LOG-1;k>=0;k--){
        if(up[u][k]!=up[v][k]){
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}

int main(){
    int t;
    cin >> t;

    while(t--){
        memset(up,-1,sizeof(up));
        memset(dist,0,sizeof(dist));
        for(int i=0;i<maxn;i++)
            adj[i].clear();

        int x, y, w, u;
        string op;
        cin >> n;
        for(int i=0;i<n-1;i++){
            cin >> x >> y >> w;
            adj[x].push_back({y,w});
            adj[y].push_back({x,w});
        }
        dfs(1,-1);
        while(cin >> op && op!="DONE"){
            if(op=="DIST"){
                cin >> x >> y;
                cout << dist[x]+dist[y]-2*dist[lca(x,y)] <<'\n';
            }
            else{
                cin >> x >> y >> w; w--;
                u = lca(x,y);
                int answ=-1;
                if(ht[x]-ht[u]>=w){
                    answ = lift(x,w);
                }
                else{
                    w-=(ht[x]-ht[u]);
                    answ = lift(y,ht[y]-ht[u]-w);
                }
                cout << answ <<'\n';
            }
        }

        cout<<'\n';
    }
    return 0;
}