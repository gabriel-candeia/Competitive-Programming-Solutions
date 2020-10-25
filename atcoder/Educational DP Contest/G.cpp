#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int n, m, dp[maxn];
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u){
    visited[u]=true;
    for(auto v:adj[u]){
        if(!visited[v])
            dfs(v);
        dp[u] = max(dp[u],dp[v]+1);
    }
}

int main(){
    int x, y;

    cin >> n >> m;
    adj.assign(n+1,vector<int>());
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
    }

    visited.assign(n+1,false);
    int answ=0;
    for(int i=1;i<=n;i++){
        if(!visited[i])
            dfs(i);
        answ = max(answ,dp[i]);
    }
    cout << answ <<'\n';

    return 0;   
}