#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

const ll mod = 1e9+7;
ll dp[maxn][2], n;
vector<vector<ll>> adj;

ll solve(ll u, ll p, bool c){
    if(dp[u][c]!=-1)
        return dp[u][c];
    dp[u][c] = 1;
    ll acm;
    for(auto v:adj[u]){
        acm = 0;
        if(v!=p){
            if(!c)
                acm = (solve(v,u,1))%mod;
            acm += (solve(v,u,0))%mod;
            dp[u][c] = (acm*dp[u][c])%mod;
        }
    }

    return dp[u][c];
}

int main(){
    cin >> n;
    adj.assign(n+1,vector<ll>());
    ll x, y;
    for(int i=1;i<n;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(dp,-1,sizeof(dp));
    cout << (solve(1,-1,0)+solve(1,-1,1))%mod <<'\n';

    return 0;
}