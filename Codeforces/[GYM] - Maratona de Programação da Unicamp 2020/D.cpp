#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int dp[maxn][maxn], n, m, c[maxn];

int solve(int i, int k){
    if(i>n)
        return dp[i][k] = 0;
    if(dp[i][k]!=-1)
        return dp[i][k];
    if(k==0){
        dp[i][k] = 0;
        int acm=0;
        for(int j=i;j<=n;j++){
            acm+=c[j];
            dp[i][k]+=acm;
        }
        return dp[i][k];
    }
    dp[i][k] = 1<<30;
    int acm=0, total=0;
    for(int j=i;j<=n;j++){
        acm += c[j];
        dp[i][k] = min(dp[i][k],total+solve(j+1,k-1));
        total += acm;  
    }
    return dp[i][k];
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> c[i];

    memset(dp,-1,sizeof(dp));
    cout << solve(1,m) <<'\n';

    return 0;
}