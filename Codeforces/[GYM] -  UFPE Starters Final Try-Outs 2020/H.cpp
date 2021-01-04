#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

const ll inf = 1ll<<61;
ll n, m, k;
vector<vector<pair<ll,ll>>> adj;
vector<ll> t, start, dist;

void dijsktra(){
    dist.assign(n+1,inf);
    priority_queue<tuple<ll,ll>> pq;
    ll u, d;
    for(auto v:start){
        dist[v] = 0;
        pq.push({-dist[v],v});
    }

    while(pq.size()){
        tie(d,u) = pq.top(); pq.pop(); d*=-1;

        if(d>dist[u]) continue;

        d+=t[u];
        for(auto e:adj[u]){
            if(d+e.second<dist[e.first]){
                dist[e.first] = d+e.second;
                pq.push({-dist[e.first],e.first});
            }
        }
    }

}

int main(){
    fastio();
    cin >> n >> m >> k;
    adj.assign(n+1,vector<pair<ll,ll>>());
    t.assign(n+1,0);
    
    start.assign(k,0);
    ll x, y, w;
    for(ll i=0;i<m;i++){
        cin >> x >> y>> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    
    for(ll i=1;i<=n;i++){
        cin >> t[i];
    }

    for(ll i=0;i<k;i++){
        cin >> start[i];
    }
    dijsktra();
    for(int i=1;i<=n;i++){
        cout << dist[i]+t[i] << "\n";
    }

    return 0;
}