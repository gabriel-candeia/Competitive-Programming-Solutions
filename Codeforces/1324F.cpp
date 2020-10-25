#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, x, y;
vector<int> color, dp, answ;
vector<vector<int>> adj;

int dfs(int u, int p){
    dp[u]=color[u];
    for(auto v:adj[u])
        if(v!=p)
            dp[u] += max(0,dfs(v,u));
    return max(0,dp[u]);
}

void rerooting(int u, int p){
    dp[p] = dp[p] - max(0,dp[u]);
    dp[u] = dp[u] + max(0,dp[p]);
    answ[u] = dp[u];

    for(auto v:adj[u])
        if(v!=p)
            rerooting(v,u);

    dp[u] = dp[u] - max(0,dp[p]);
    dp[p] = dp[p] + max(0,dp[u]);
}

int main(){
    cin >> n;

    color.assign(n+1,0);
    adj.assign(n+1,vector<int>());
    dp.assign(n+1,-1);
    answ.assign(n+1,-1);

    for(int i=1;i<=n;i++){
        cin >> color[i];
        if(!color[i]) color[i] = -1;
    }

    for(int i=1;i<n;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);
    rerooting(1,0);

    for(int i=1;i<=n;i++)
        cout << answ[i] << " ";
    cout <<'\n';

    return 0;
}