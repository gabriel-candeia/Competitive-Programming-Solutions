#include <bits/stdc++.h>

using namespace std;

typedef long long int ll ;

#define maxn 10010
#define mod 1000000007

ll n, m, k;
ll dp[maxn][11][11];

ll solve(int pos, int cor, int rep){
    if(rep>m)
        return 0;
    if(pos == n)
        return 1;
    if(dp[pos][cor][rep] != -1)
        return dp[pos][cor][rep];
    dp[pos][cor][rep] = 0;
    for(int i = 1; i <= k; i++){
        dp[pos][cor][rep] = (dp[pos][cor][rep]+solve(pos+1, i, ((i==cor) ? rep+1: 1)))%mod;
    }
    return dp[pos][cor][rep]%mod;
}

int main(){
    cin >> n >> k >> m;
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    cout << solve(0,0,0) << '\n';
    /*for(int i = 1; i <= m; i++){
        ans += 1+(solve(1, i, 1))%mod;
    }
    cout << ans << "\n";*/
    return 0;
}
