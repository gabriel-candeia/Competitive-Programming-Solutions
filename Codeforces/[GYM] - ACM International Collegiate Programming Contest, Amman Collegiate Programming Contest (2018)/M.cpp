#include<bits/stdc++.h>
#define LOG 22
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

vector<vector<int>> adj, parent;
map<pair<int,int>,int> edges;
vector<ll> fromRoot, toRoot, ht;

void precomp(int u, int p){
    parent[u][0] = p;
    for(int k=1;k<LOG;k++)
        if(parent[u][k-1]!=-1)
            parent[u][k] = parent[parent[u][k-1]][k-1];

    for(auto v:adj[u]){
        if(v!=p){
            fromRoot[v] = fromRoot[u] + edges[{u,v}];
            toRoot[v] = toRoot[u] + edges[{v,u}];
            ht[v] = ht[u] + 1;
            precomp(v,u);
        }
    }
}

int lift(int u, int x){
    for(int k=LOG-1;k>=0;k--){
        if(parent[u][k]!=-1 && (1<<k)<=x){
            x -= 1<<k;
            u = parent[u][k];
        }
    }
    return u;
}

int lca(int u, int v){
    if(ht[u]<ht[v])
        swap(u,v);
    u = lift(u,ht[u]-ht[v]);
    if(u==v)
        return v;
    for(int k=LOG-1;k>=0;k--){
        if(parent[u][k]!=parent[v][k]){
            u = parent[u][k];
            v = parent[v][k];
        }
    }
    return parent[u][0];
}

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        int n;
        ll total = 0;
        cin >> n;
        adj.assign(n+1,vector<int>());
        parent.assign(n+1,vector<int>(LOG,-1));
        edges.clear();

        for(int i=0;i<n-1;i++){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            edges[{a,b}] = c;
            edges[{b,a}] = d;
            adj[a].push_back(b);
            adj[b].push_back(a);
            total += c;
            total += d;
        }

        fromRoot.assign(n+1,0);
        toRoot.assign(n+1,0);
        ht.assign(n+1,0);
        precomp(1,-1);
        int q;
        cin >> q;
        
        while(q--){
            int a, b, c;
            cin >> a >> b;
            c = lca(a,b);
            //cout << a << " " << b << " " << c <<"\n";
            ll dist = fromRoot[a]-fromRoot[c]+toRoot[b]-toRoot[c];
            cout << total-dist <<"\n";
        }
        
    }

    return 0;
}