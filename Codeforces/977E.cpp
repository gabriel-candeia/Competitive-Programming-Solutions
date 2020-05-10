#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, int i, vector<bool>& visited){
    bool ret = (adj[i].size()==2);
    visited[i] = true;
    for(auto w:adj[i]){
        if(!visited[w]){
            ret = (dfs(adj,w,visited) && ret);
        }
    }
    return ret;
}

int main(){
    int n, m, answ = 0;
    int a, b;
    vector<vector<int>> adj;
    vector<bool> visited;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    adj.assign(n+1,vector<int>());
    visited.assign(n+1,false);
    for(int i=0;i<m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            answ += dfs(adj,i,visited);
        }
    }

    cout << answ << '\n';

    return 0;
}