#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
vector<array<ll,3>> p;
vector<vector<pair<ll,ll>>> adj;
vector<ll> dist;

void dijkstra(ll u){
    const ll inf = 1e18;
    dist.assign(adj.size(),inf);
    priority_queue<tuple<ll,ll>> pq;
    ll d;

    dist[u] = 0;
    pq.push({-dist[u],u});

    while(pq.size()){
        tie(d, u) = pq.top(); pq.pop();
        d*=-1;
        
        if(d>dist[u]) continue;
        for(auto e:adj[u]){
            if(d+e.second < dist[e.first]){
                dist[e.first] = d+e.second;
                pq.push({-dist[e.first],e.first});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    adj.assign(m+2,vector<pair<ll,ll>>());
    p.assign(m,array<ll, 3>());
    ll fx, fy, sx, sy;

    cin >> sx >> sy;
    cin >> fx >> fy;
    for(ll i=0;i<m;i++){
        cin >> p[i][0] >> p[i][1];
        p[i][2] = i+1;
        adj[0].push_back({i+1,abs(sx-p[i][0])});
        adj[i+1].push_back({0,abs(sx-p[i][0])});

        adj[0].push_back({i+1,abs(sy-p[i][1])});
        adj[i+1].push_back({0,abs(sy-p[i][1])});
    }
    if(m){
        for(ll j=0;j<2;j++){
            sort(p.begin(),p.end());
            for(ll i=0;i<m-1;i++){
                ll dist = min(abs(p[i+1][0]-p[i][0]),abs(p[i+1][1]-p[i][1]));
                adj[p[i][2]].push_back({p[i+1][2],dist});
                adj[p[i+1][2]].push_back({p[i][2],dist});
                swap(p[i][0],p[i][1]);
            }   
            swap(p[m-1][0],p[m-1][1]);
        }
    }

    dijkstra(0);
    ll answ = abs(sx-fx)+abs(sy-fy);
    for(int i=0;i<m;i++)
        answ = min(answ,dist[p[i][2]]+abs(fx-p[i][0])+abs(fy-p[i][1]));
    
    cout << answ <<'\n';

    return 0;
}