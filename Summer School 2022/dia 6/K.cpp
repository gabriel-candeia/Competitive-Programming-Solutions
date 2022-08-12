#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define ll long long
using namespace std;

const ll mod = 998244353;
vector<int> adj[maxn];

ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y/=2){
        if(y&1){
            answ = (answ*x)%mod;
        }
        x = (x*x)%mod;
    }
    return answ;
}

ll dp[maxn][2];
ll solve(int u, int in){
    if(adj[u].size()==0)
        return 1;
    if(dp[u][in]!=-1)
        return dp[u][in];
    if(in==0){
        dp[u][in] = 1;
        for(auto v:adj[u])
            dp[u][in] = (dp[u][in]*(solve(v,0))%mod)%mod;
        dp[u][in] = (dp[u][in] + solve(u,1))%mod;
    }
    else{
        dp[u][in] = 1;
        vector<ll> todos;
        for(auto v:adj[u]){
            todos.push_back(solve(v,0));
        }
        for(int i=0;i<todos.size();i++){
            dp[u][in] = (dp[u][in]*(todos[i]+1))%mod;
        }
        dp[u][in] = (dp[u][in] - 1 + mod)%mod;
        for(int i=0;i<todos.size();i++){
            dp[u][in] = (dp[u][in] - todos[i] + mod)%mod;
        }
    }
    return dp[u][in];
}


int main(){
    int n;

    cin >> n;
    for(int i=2;i<=n;i++){
        int a;
        cin >> a;
        adj[a].push_back(i);
    }

    memset(dp,-1,sizeof(dp));
    cout << solve(1,0) << "\n";

    return 0;
}