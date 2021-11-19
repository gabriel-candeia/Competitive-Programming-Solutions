#include<bits/stdc++.h>
#define maxn 2505
#define ll long long
using namespace std;

const ll inf = 1e18;
ll n, m;
vector<ll> dist, v1, v2;
vector<vector<ll>> adj1, adj2;
vector<array<ll,3>> edges;

ll bellman_ford(int u, int s){
    dist.assign(n+1,inf); dist[u] = 0;
    for(int i=0;i<n;i++)
        for(auto e:edges)
            if(v1[e[0]] && v2[e[0]])
                dist[e[1]] = min(dist[e[1]],dist[e[0]]+e[2]);
    for(auto e:edges) 
        if(v1[e[0]] && v2[e[0]] && dist[e[1]] > dist[e[0]]+e[2])
            return -1;
    return -dist[s];
}

void dfs(int u, vector<vector<ll>> &adj ,vector<ll> &visited){
    visited[u] = 1;
    for(auto v:adj[u])
        if(!visited[v])
            dfs(v,adj,visited);
}

int main(){
    ll a, b, c;

    cin >> n >> m;
    adj1.assign(n+1,vector<ll>());
    adj2.assign(n+1,vector<ll>());
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        edges.push_back({a,b,-c});
        adj1[b].push_back(a);
        adj2[a].push_back(b);
    }

    v1.assign(n+1,0);v2.assign(n+1,0);
    dfs(n,adj1,v1), dfs(1,adj2,v2);

    cout << bellman_ford(1,n) << "\n";

    return 0;
}