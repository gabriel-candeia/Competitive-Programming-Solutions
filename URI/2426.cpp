#include<bits/stdc++.h>
#define N 1000
using namespace std;

int n, u, v, m;
int x, y, z;
vector<pair<int,int>> adj[N];
const int inf = 1e9;

int bfs(int u, int v){
    
    vector<int> dist[3];    
    for(auto &v:dist)
        v = vector<int>(n+1,inf);
    queue<pair<int,int>> q;
    pair<int,int> p;
    int w, d;
    
    q.push({u,0});
    dist[0][u] = 0;

    while(q.size()){
        tie(w, d) = q.front(); q.pop();

        for(auto e:adj[w]){
            int v = e.first, t = e.second;
            if(((!t&&d%3)||(t&&!(d%3))) && dist[(d+1)%3][v]>d+1){
                dist[(d+1)%3][v]=d+1;
                q.push({v,d+1});
            }
        }
    }
    
    return min({dist[0][v],dist[1][v],dist[2][v]});
}       

int main(){
    cin >> n >> u >> v >> m;
    while(m--){
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y,z));
    }
    x=bfs(u,v);
    if((x==inf))
        cout << '*' <<'\n';
    else
        cout << x  <<'\n';

    return 0;
}

