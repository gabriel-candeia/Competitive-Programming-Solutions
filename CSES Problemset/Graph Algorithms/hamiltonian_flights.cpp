#include<bits/stdc++.h>
#define maxn 21
#define maxm int(1<<21)
#define ll long long
using namespace std;
 
const ll mod = 1e9+7;
ll n, m, dp[maxn][maxm];
vector<int> adj[maxn];
 
ll solve(int u, int msk){
    if(msk==0 && u==n-1){
        return 1;
    }
    if(u==n-1){
        return 0;
    }
    if(dp[u][msk]!=-1){
        return dp[u][msk];
    }
    dp[u][msk] = 0;
    for(auto v:adj[u]){
        if((msk&(1<<v))){
            dp[u][msk] = (dp[u][msk] + solve(v,msk^(1<<v)))%mod;
        }
    }
    return dp[u][msk];
}
 
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);    
    }
    
    memset(dp,-1,sizeof(dp));
    cout << solve(0,((1<<n)-1)^1) << "\n";
 
    return 0;
}