#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool dfs1(vector<vector<int>>& adj, int u, int avoid, vector<bool>& visited){
    visited[u] = true;
    if(u==avoid){
        return true;
    }
    for(auto v:adj[u]){
        if(!visited[v]){
            if(dfs1(adj,v,avoid,visited)){
                return true;
            }
        }
    }
    visited[u] = false;
    return false;
}

int dfs2(vector<vector<int>>& adj, int u, vector<bool>& visited){
    visited[u] = true;
    int cnt = 0;
    for(auto v:adj[u]){
        if(!visited[v]){
            cnt += dfs2(adj,v,visited);
        }
    }
    return cnt+1;
}

int main(){
    ll n, x, y, a, b;
    vector<bool> visited;
    vector<vector<int>> adj;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x >> y;

    adj.assign(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited.assign(n+1,false);
    dfs1(adj,x,y,visited);
    a = dfs2(adj,x,visited);
    b = dfs2(adj,y,visited);

    ll answer = n*(n-1) - (a*b);

    cout << answer << '\n';

    return 0;
}
