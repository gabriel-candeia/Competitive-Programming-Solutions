#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define maxm 55
using namespace std;
#define ll long long

const ll inf =  1e18;
vector<pair<ll,ll>> adj[maxn];
ll dist[maxn][maxm];

void dijkstra(int s){
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxm;j++)
            dist[i][j] = inf;
    priority_queue<tuple<ll,ll,ll>> pq;
    
    int u, w, d;
    pq.push({dist[s][0] = 0,s,0});


    while(pq.size()){
        tie(d,u,w) = pq.top(); pq.pop(); d *= -1;
        if(dist[u][w]<d) continue;

        if(w==0){
            for(auto e:adj[u])
                if(d < dist[e.first][e.second])
                    pq.push({-(dist[e.first][e.second] = d),e.first,e.second});
        }
        else{
            for(auto e:adj[u])
                if(d + (w+e.second)*(w+e.second) < dist[e.first][0])
                    pq.push({-(dist[e.first][0] = d + (w+e.second)*(w+e.second)),e.first,0});
        }
    }
    

    for(int i=0;i<maxn;i++)
        if(dist[i][0] == inf) dist[i][0] = -1;
}

int main(){
    int n, m, w, x, y;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    dijkstra(1);
    for(int i=1;i<=n;i++)
        cout << dist[i][0] << " ";
    cout<<'\n';

    return 0;
}