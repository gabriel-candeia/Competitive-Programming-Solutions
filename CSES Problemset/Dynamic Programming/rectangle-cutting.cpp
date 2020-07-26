#include<bits/stdc++.h>
#define N 505
#define ll long long
using namespace std;

const ll inf = 1e9;

int dp[N][N];

int main(){
    int n, m;

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==j) continue;
            dp[i][j] = inf;
            for(int k=1;k<i;k++){
                dp[i][j] = min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
            }
            for(int k=1;k<j;k++){
                dp[i][j] = min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
            }
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}