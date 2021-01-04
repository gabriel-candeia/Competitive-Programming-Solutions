#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;

ll dp[maxn][maxn], a[maxn], b[maxn], n, m;

ll solve(ll i, ll j)    {
    if(i==n || j==m)
        return max(n-i,m-j);
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j] = min(solve(i+1,j)+1,solve(i,j+1)+1);
    dp[i][j] = min(solve(i+1,j+1)+(a[i]!=b[j]),dp[i][j]);
    return dp[i][j];
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<m;i++)
        cin >> b[i];

    memset(dp,-1,sizeof(dp));
    cout << solve(0,0) <<'\n';
    return 0;

}