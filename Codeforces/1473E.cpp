#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

const ll inf = 1e17;
vector<pair<ll,ll>> adj[maxn];
ll dist[maxn][2][2];

void dijkstra(){
    for(int i=0;i<maxn;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                dist[i][j][k] = inf;

    priority_queue<tuple<ll,ll,ll,ll>> pq; dist[1][0][0] = 0;
    pq.push({-dist[1][0][0],1,0,0});

    ll u, mn, mx, d;
    while(pq.size()){
        tie(d,u,mx,mn) = pq.top(); pq.pop(); d *= -1;
        //cout << u << " " << mx << " " << mn << " " << d << "\n";

        if(d>dist[u][mx][mn]) continue;
        for(auto e:adj[u]){
            for(int i=0;i<=1-mx;i++){
                for(int j=0;j<=1-mn;j++){
                    if(dist[e.first][mx|i][mn|j] > dist[u][mx][mn] + (1-i+j)*e.second){
                        dist[e.first][mx|i][mn|j] = dist[u][mx][mn] + (1-i+j)*e.second;
                        pq.push({-dist[e.first][mx|i][mn|j],e.first,mx|i,mn|j});
                    }
                }
            }
        }
    }

}

int main(){
    ll n, m, x, y, w;
    cin >> n >> m;
    for(int i=0;i<m;i++){   
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    dijkstra();
    for(int i=2;i<=n;i++)   
        cout << dist[i][1][1] << " ";
    cout<<'\n';
    return 0;
}