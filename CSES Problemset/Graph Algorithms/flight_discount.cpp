#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

int n, m;
const ll inf = 1e18;
vector<pair<ll,ll>> adj[maxn];
ll solve(int s, int t){
    vector<vector<ll>> dist(n+1,vector<ll>(2,inf));
    priority_queue<tuple<ll,ll,ll>> pq;
    ll d, u, taken;

    dist[s][0] = 0;
    pq.push({-dist[s][0],s,0});
    while(pq.size()){
        tie(d,u,taken) = pq.top(), pq.pop(); d = -d;
        if(d > dist[u][taken]) continue;
        for(auto e:adj[u]){
            if(d+e.second < dist[e.first][taken]){
                dist[e.first][taken] = d+e.second;
                pq.push({-dist[e.first][taken],e.first,taken});
            }
            if(taken==0 && d+e.second/2 < dist[e.first][1]){
                dist[e.first][1] = d+e.second/2;
                pq.push({-dist[e.first][1],e.first,1});
            }
        }
    }

    return dist[t][1];
}



int main(){
    ll a, b, c;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    cout << solve(1,n) << "\n";
    return 0;
}