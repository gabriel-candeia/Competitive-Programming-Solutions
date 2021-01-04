#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define ll long long
using namespace std;

ll n, c[maxn], inc[maxn], ht[maxn], acm;
vector<ll> adj[maxn];
vector<pair<ll,ll>> edges;

void dfs(ll v, ll p){
    ht[v] = ht[p]+1;
    acm+=inc[v];
    c[v]+=acm;
    for(auto u:adj[v])
        if(u!=p)
            dfs(u,v);
    acm-=inc[v];
}


int main(){ 
    cin >> n;
    ll a, b;
    for(ll i=0;i<n-1;i++){
        cin >> a >> b;
        edges.push_back({a,b});
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    dfs(1,0);

    ll q, t, e, x;
    cin >> q;
    while(q--){
        cin >> t >> e >> x;
        a = edges[e-1].first, b = edges[e-1].second;
        if(t==2)
            swap(a,b);
        
        if(ht[a]>ht[b]){
            inc[a]+=x;
        }
        else{
            inc[1]+=x;
            inc[b]-=x;
        }
    }

    dfs(1,0);

    for(ll i=1;i<=n;i++)
        cout <<  c[i] << "\n";
    return 0;
}