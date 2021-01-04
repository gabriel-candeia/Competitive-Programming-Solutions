#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e4+5)
#define maxm 105
#define maxd 11
using namespace std;

const ll mod = 1e9+7;
ll dp[maxn][maxd][maxm], n, m, k;
ll nxt[10][3] = {{4,6,-1},{6,8,-1},{7,9,-1},{4,8,-1},{0,3,9},{-1,-1,-1},{1,7,0},{2,6,-1},{1,3,-1},{2,4,-1}};
string t;

ll solve(ll i, ll d, ll j){
    if(j==m && m!=0)
        return dp[i][d][j] = 0;
    if(i==n)
        return dp[i][d][j] = 1;
    if(dp[i][d][j]!=-1)
        return dp[i][d][j];
    dp[i][d][j] = 0;
    for(int k=0;k<3;k++){
        if(nxt[d][k]!=-1 && m!=0 && nxt[d][k]==(t[j]-'0')){
            dp[i][d][j] = (dp[i][d][j] + solve(i+1,nxt[d][k],j+1))%mod;
        }
        else if(nxt[d][k]!=-1){
            dp[i][d][j] = (dp[i][d][j] + solve(i+1,nxt[d][k],(t[0]-'0')==nxt[d][k]))%mod;
        }
    }
    return dp[i][d][j];
}

int main(){

    memset(dp,-1,sizeof(dp));
    cin >> n >> m >> k >> t;
    cout << solve(0,k,0) << '\n';
    return 0;
}