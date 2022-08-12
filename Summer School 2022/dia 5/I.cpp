#include<bits/stdc++.h>
#define ll long long
#define maxn int(105)
using namespace std;

int d, k, n;
const ll mod = 1e9+7;
ll dp[maxn][2];

ll solve(int i, int j){
    if(i==0)
        return j;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j] = 0;
    for(int w=1;w<=k;w++)
        if(i-w>=0)
            dp[i][j] = (dp[i][j] + solve(i-w,max(j,(int)(w>=d))))%mod;
    return dp[i][j];
}

int main(){
    cin >> n >> k >> d;
    memset(dp,-1,sizeof(dp));

    cout << solve(n,0)<<'\n';

    return 0;
}