#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e5)+5
using namespace std;

const ll inf = 1e17;
ll dp[maxn], h[maxn], n, k;

ll solve(int n){
    for(int i=0;i<=n;i++)
        dp[i] = inf;
    dp[0] = 0;
    
    for(int i=0;i<n;i++)
        for(int j=1;j<=k;j++)
            dp[i+j] = min(dp[i+j],dp[i]+abs(h[i]-h[i+j]));
    
    return dp[n-1];
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> h[i];

    cout << solve(n) <<'\n';
    return 0;
}