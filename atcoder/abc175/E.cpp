#include<bits/stdc++.h>
#define ll long long
#define maxn 3005
using namespace std;

ll dp[maxn][maxn][4], grid[maxn][maxn];

int main(){ 
    ll r, c, k, ri, ci, vi;

    cin >> r >> c >> k;
    for(int i=0;i<k;i++){
        cin >> ri >> ci >> vi;
        grid[ri][ci] = vi;
    }

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            for(int k=0;k<=3;k++){ 
                if(k<3){
                    dp[i][j+1][k+1] = max(dp[i][j+1][k+1],dp[i][j][k]+grid[i][j]);
                    dp[i+1][j][0] = max(dp[i+1][j][0],dp[i][j][k]+grid[i][j]);
                }
                dp[i+1][j][0] = max(dp[i+1][j][0],dp[i][j][k]);
                dp[i][j+1][k] = max(dp[i][j+1][k],dp[i][j][k]);
            }
        }
    }

    ll answ = dp[r][c][3];
    for(int i=0;i<3;i++){
        answ = max(answ,dp[r][c][i]+grid[r][c]);
    }

    cout << answ <<'\n';

    return 0;
}