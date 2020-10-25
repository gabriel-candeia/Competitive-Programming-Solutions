#include<bits/stdc++.h>
#define maxn 405
#define ll long long
using namespace std;

const ll inf = 1e18;
ll dp[maxn][maxn],a[maxn],n;
ll solve(int i, int j){
    if(dp[i][j]!=-1)
        return dp[i][j];
    else if(j-i+1==2)
        return dp[i][j] = a[j]-a[i-1];
    else if(j-i+1==1)
        return 0;
    dp[i][j] = inf;
    for(int k=i;k<j;k++)
        dp[i][j] = min(dp[i][j],solve(i,k)+solve(k+1,j));
    dp[i][j]+=(a[j]-a[i-1]);
    return dp[i][j];
}


int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }

    memset(dp,-1,sizeof(dp));
    cout << solve(1,n) <<'\n';

    return 0;
}