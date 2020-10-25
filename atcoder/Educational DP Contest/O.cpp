#include<bits/stdc++.h>
#define maxn 25
#define maxm int(3e6)
#define ll long long
using namespace std;

const ll mod = 1e9+7;
ll dp[maxn][maxm], mat[maxn][maxn], n;
ll solve(ll i, ll msk){
    if(i==n)
        return dp[i][msk] = (msk==0);
    if(dp[i][msk]!=-1)
        return dp[i][msk];
    dp[i][msk] = 0;
    for(int j=0;j<n;j++){
        if(mat[i][j] && (msk&(1ll<<j)))
            dp[i][msk] = (dp[i][msk] + solve(i+1,msk^(1ll<<j)))%mod;
    }
    return dp[i][msk];
}



int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> mat[i][j];
    memset(dp,-1,sizeof(dp));
    cout << solve(0,(1ll<<n)-1) <<'\n';
    return 0;
}