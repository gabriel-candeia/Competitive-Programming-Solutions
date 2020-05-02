#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int u, vector<int>& answ, vector<bool>& visited){
    visited[u] = true;
    for(auto w:adj[u]){
        if(!visited[w]){
            answ[w] = u;
            dfs(adj,w,answ,visited);
        }
    }
}

int main(){
    int n, r1, r2, p;
    vector<vector<int>> adj;
    vector<int> answ;
    vector<bool> visited;

    cin >> n >> r1 >> r2;
    adj.assign(n+1,vector<int>());
    answ.assign(n+1,-1);
    visited.assign(n+1,false);
    for(int i=1;i<=n;i++){
        if(i==r1){
            continue;
        }
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    dfs(adj,r2,answ,visited);
    for(int i=1;i<=n;i++){
        if(i!=r2){
            cout << answ[i] << ' ';
        }
    }
    cout << '\n';
    return 0;
}