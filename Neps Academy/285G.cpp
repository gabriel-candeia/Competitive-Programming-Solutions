#include<bits/stdc++.h>
#define INF int(1e8)
using namespace std;

int dijkstra(vector<vector<pair<int,int>>>& adj, int u, int n){
    vector<int> dist(n+1,INF);
    pair<int,int> p;
    int d;
    priority_queue<pair<int,int>> h;
    h.push({0,u});

    while(h.size()){
        p = h.top(); h.pop();
        u = p.second;
        d = p.first;

        for(auto v:adj[u]){
            if(dist[v.first]>d+v.second){
                dist[v.first] = d+v.second;
                h.push({dist[v.first],v.first});
            }
        }
    }

    return dist[n];
}

int main(){
    int n, m;
    int a, b, c;
    vector<vector<pair<int,int>>> adj;

    cin >> n >> m;
    adj.assign(n+1,vector<pair<int,int>>());
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    cout << dijkstra(adj,1,n) << '\n';

    return 0;
}