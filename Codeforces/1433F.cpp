#include<bits/stdc++.h>
#define ll long long
#define maxn 72
using namespace std;

const ll inf = -1e16;
ll dp[maxn][maxn][maxn][maxn], n, m, mod, mat[maxn][maxn];
ll solve(ll i, ll j, ll l, ll r){
    if(i==n)
        return ((!r) ? 0 : inf);
    if(dp[i][j][l][r]!=-1)
       return  dp[i][j][l][r];
    ll answ=0;
    if(j==m-1)
        answ = max(solve(i+1,0,m/2,r),((l) ? solve(i+1,0,m/2,(r+mat[i][j])%mod)+mat[i][j] : inf));
    else
        answ = max(solve(i,j+1,l,r),((l) ? solve(i,j+1,l-1,(r+mat[i][j])%mod)+mat[i][j] : inf));
    dp[i][j][l][r] = max(answ,((!r) ? 0 : inf));
    return dp[i][j][l][r];
}


int main(){
    cin >> n >> m >> mod;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j];
    
    memset(dp,-1,sizeof(dp));
    cout << solve(0,0,m/2,0) << '\n';
    return 0;
}