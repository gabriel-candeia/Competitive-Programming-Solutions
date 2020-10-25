#include<bits/stdc++.h>
#define maxn 500
using namespace std;

const int inf = 1e8;
int cost[maxn][maxn], k, n, dp[maxn][maxn];
string s;

int transform(int l, int r){
    int answ=0;
    for(int i=0;i<=(r-l)/2;i++)
        answ += min(abs(s[r-i]-s[l+i]),26-abs(s[r-i]-s[l+i]));
    return answ;
}

int solve(int i, int k){
    if(dp[i][k]!=-1)
        return dp[i][k];
    if(k==0 && i!=n)
        return dp[i][k] = inf;
    else if(i==n)
        return dp[i][k] = 0;
    dp[i][k] = inf;
    for(int j=i;j<n;j++){
        dp[i][k] = min(dp[i][k],cost[i][j]+solve(j+1,k-1));
    }
    return dp[i][k];
}

int main(){
    cin >> n >> k;
    cin >> s;

    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            cost[i][j] = transform(i,j);

    memset(dp,-1,sizeof dp);

    cout << solve(0,k) <<'\n';
    return 0;
}   