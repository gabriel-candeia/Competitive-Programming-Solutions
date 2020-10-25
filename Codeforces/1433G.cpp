#include<bits/stdc++.h>
#define maxn 1005
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<pair<int,int>> paths;
vector<int> cnt;
int n, m, k, dist[maxn][maxn];
const int inf = 1e9;

void dijkstra(int x){
    for(int i=1;i<=n;i++)
        dist[x][i] = inf;
    priority_queue<tuple<int,int>> pq;
    int u, d;

    dist[x][x] = 0;
    pq.push({-dist[x][x],x});

    while(pq.size()){
        tie(d, u) = pq.top(); pq.pop();
        d*=-1;
        if(d>dist[x][u]) continue;

        for(auto e:adj[u]){
            if(d+e.second < dist[x][e.first]){
                dist[x][e.first] = d+e.second;
                pq.push({-dist[x][e.first],e.first});
            }
        }
    }
}

int main(){
    cin >> n >> m >> k;
    int x, y, z;
    adj.assign(n+1,vector<pair<int,int>>());
    for(int i=0;i<m;i++){
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    for(int i=1;i<=n;i++)
        dijkstra(i);

    for(int i=0;i<k;i++){
        cin >> x >> y;
        paths.push_back({x,y});
    }

    int res=inf;
    for(int u=1;u<=n;u++){
        for(auto e:adj[u]){
            int v = e.first, answ=0;
            for(auto p:paths)
                answ += min({dist[p.first][p.second],dist[p.first][u]+dist[p.second][v],dist[p.first][v]+dist[p.second][u]});
            res = min(res,answ);
        }
    }

    cout << res <<'\n';

    return 0;
}