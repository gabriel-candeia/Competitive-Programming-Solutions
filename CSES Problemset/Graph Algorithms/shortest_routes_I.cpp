#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

const ll inf = 1e18;
int n, m;
vector<pair<ll,ll>> adj[maxn];

vector<ll> dijkstra(int s){
    vector<ll> dist(n+1,inf);
    priority_queue<tuple<ll,ll>> pq;
    ll d, u;
    dist[s] = 0, pq.push({-dist[s],s});
    while(pq.size()){
        tie(d,u) = pq.top(), pq.pop(); d *= -1;
        if(d>dist[u]) continue;
        for(auto e:adj[u])
            if(d+e.second<dist[e.first])
                dist[e.first] = d+e.second, pq.push({-dist[e.first],e.first});
    }

    return dist;
}

int main(){
    ll a, b, c;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    auto answ = dijkstra(1);
    for(int i=1;i<=n;i++)
        cout << answ[i] << " ";
    cout << '\n';

    return 0;
}