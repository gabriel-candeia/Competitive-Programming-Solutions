#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
using namespace std;

char grid[maxn][maxn];
ll dp[maxn][maxn], last[maxn][maxn], up[maxn][maxn], diag[maxn][maxn], n, m;
const ll mod = 1e9+7;

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> grid[i][j];

    dp[1][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]=='#') continue;
            dp[i][j] += (last[i][j-1]+up[i-1][j]+diag[i-1][j-1])%mod;
            last[i][j] = (dp[i][j]+last[i][j-1])%mod;
            up[i][j] = (up[i-1][j]+dp[i][j])%mod;
            diag[i][j] = (dp[i][j]+diag[i-1][j-1])%mod;
        }
    }
    cout << dp[n][m] <<'\n';
    return 0;
}