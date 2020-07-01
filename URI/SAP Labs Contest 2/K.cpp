#include<bits/stdc++.h>
using namespace std;
const int INF = int(1e9)+1;
vector<vector<pair<int,int>>> adj;
vector<int> wt, visited;
int n, x, y, w;

void dfs(int u){
    visited[u] = true;

    for(auto v:adj[u]){
        if(!visited[v.first]){
            wt[v.first] = min(wt[u],v.second);
            dfs(v.first);
        }
    }
}

int main(){
    cin >> n;
    visited.assign(n+1,false);
    wt.assign(n+1,INF);
    adj.assign(n+1,vector<pair<int,int>>());
    for(int i=0;i<n-1;i++){
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    dfs(n);
    for(int i=1;i<n-1;i++){
        cout << wt[i] << " ";
    }
    cout << wt[n-1] << '\n';

    return 0;
}