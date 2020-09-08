#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

vector<vector<int>> adj;
vector<int> dist;
int n, x, y;

int bfs(int u){
    dist.assign(n+1,0);
    queue<int> q;
    q.push(u);
    dist[u] = 1;
    while(q.size()){
        u = q.front(); q.pop();
        for(auto v:adj[u]){
            if(!dist[v]){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    return u;
}

int main(){
    fastio();
    cin >> n;
    adj.assign(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << 3*(dist[bfs(bfs(1))]-1) <<'\n';
    return 0;
}