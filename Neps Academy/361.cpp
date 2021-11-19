#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
#define ll long long
using namespace std;

int n, m;
const ll inf = 1e18;
vector<vector<array<ll,4>>> adj;

int main(){
    fastio();
    cin >> n >> m;
    adj.assign(n+1,vector<array<ll,4>>());

    for(int i=0;i<m;i++){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        adj[a].push_back({b,c,d,e});
        //adj[b].push_back({a,c,d,e});
    }

    vector<ll> dist(n+1,inf);
    priority_queue<tuple<ll,ll>> pq;
    ll u, d;
    dist[1] = 0;
    pq.push({0,1});

    while(pq.size()){
        tie(d, u) = pq.top(), pq.pop(), d = -d;

        if(d>dist[u]) continue;
        
        for(auto e:adj[u]){
            ll dist1;
            if((d+e[1])%(e[2]+e[3]) < e[2]){
                dist1 = d+e[1];
            }
            else{
                //dist1 = d+e[1];
                dist1 = (d+e[1]) + (e[2]+e[3]) - (d+e[1])%(e[2]+e[3]);
            }

            if(dist1 < dist[e[0]]){
                dist[e[0]] = dist1;
                pq.push({-dist[e[0]],e[0]});
            }

        }
    }
    
    ll answ = -1;
    if(dist[n]<inf)
        answ = dist[n];

    cout << answ << "\n";

    return 0;
}