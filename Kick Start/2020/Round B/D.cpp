#include<bits/stdc++.h>
#define maxn 500
#define ld long double
using namespace std;

ld dp[maxn][maxn];

int main(){
    int t, caso=0;
    int u, d, l, r, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m >> l >> u >> r >> d;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                dp[i][j] = 0;
        
        dp[1][1] = 1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(l<=i && i<=r && u<=j && j<=d)
                    dp[i][j] = 0;
                else if(i==n)
                    dp[i][j+1] += dp[i][j];
                else if(j==m)
                    dp[i+1][j] += dp[i][j];
                else{    
                    dp[i+1][j] += dp[i][j]/2.0;
                    dp[i][j+1] += dp[i][j]/2.0;
                }
            }
        }

        cout <<"Case #" << ++caso << ": " << setprecision(10) << dp[n][m] <<'\n';
    }

    return 0;
}