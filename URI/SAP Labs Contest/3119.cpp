#include<bits/stdc++.h>
#define maxn int(1e4+5)
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
using namespace std;

const ll inf = 1e18;
ll n, m;
vector<pair<ll,ll>> adj[maxn];

ll dijkstra(ll s, ll t){
    vector<ll> dist(n+1,inf);
    priority_queue<tuple<ll,ll>> pq;
    ll u, d;

    dist[s] = 0;
    pq.push({-dist[s],s});

    while(pq.size()){
        tie(d,u) = pq.top(); pq.pop(); d *= -1;
        
        if(d>dist[u]) continue;


        for(auto e:adj[u]){
            if(d+e.second < dist[e.first] ){
                dist[e.first] = d+e.second;
                pq.push({-dist[e.first],e.first});
            }
        }
    }

    return dist[t];
}

int main(){
    fastio();
    int t;
    ll answ = 0;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<=n;i++)
            adj[i].clear();

        int x, y, w;
        for(int i=0;i<m;i++){
            cin >> x >> y >> w;
            adj[x].push_back({y,w});
        }

        answ += dijkstra(1,n);
    }  

    cout << answ <<'\n';
    return 0;
}