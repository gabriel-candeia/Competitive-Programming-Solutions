#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

const ll mod = 1e9+7;
int n, m;
vector<int> ord, adj[maxn], visited;

void dfs(int u){
    visited[u] = 1;
    for(auto v:adj[u])
        if(!visited[v])
            dfs(v);
    ord.push_back(u);
}

int main(){
    cin >> n >> m;
    int a, b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    visited.assign(n+1,0);
    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs(i);

    reverse(ord.begin(),ord.end());
    vector<ll> dp(n+1,0); dp[1] = 1;
    for(auto u:ord)
        for(auto v:adj[u])
            dp[v] = (dp[u]+dp[v])%mod;

    cout << dp[n] << "\n";

    return 0;   
}