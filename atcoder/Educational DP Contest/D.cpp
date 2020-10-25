#include<bits/stdc++.h>
#define ll long long
#define maxn 105
#define maxm int(1e5+5)
using namespace std;

const ll inf = 1e17;
ll n, W, dp[maxm], v[maxn], w[maxn];

ll solve(ll n){
    for(int i=0;i<n;i++)
        for(int j=W;j>=w[i];j--)
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
    return dp[W];
}

int main(){
    cin >> n >> W;
    for(int i=0;i<n;i++)
        cin >> w[i] >> v[i];

    cout << solve(n) <<'\n';
    return 0;
}