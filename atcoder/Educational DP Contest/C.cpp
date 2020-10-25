#include<bits/stdc++.h>
#define maxn int(1e5)+5
#define ll long long
using namespace std;

ll dp[maxn][3], h[3][maxn], n;

ll solve(ll n){
    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++){
            dp[i+1][(j+1)%3] = max(dp[i+1][(j+1)%3],dp[i][j]+h[j][i]);
            dp[i+1][(j+2)%3] = max(dp[i+1][(j+2)%3],dp[i][j]+h[j][i]);
        }
    
    return max({dp[n][0],dp[n][1],dp[n][2]});
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> h[0][i] >> h[1][i] >> h[2][i];

    cout << solve(n) <<'\n';
    return 0;
}