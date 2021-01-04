#include<bits/stdc++.h>
#define maxn int(1e4+5)
#define ll long long
using namespace std;

ll dp[maxn][4], n, arr[maxn], cost[maxn][maxn];
ll solve(int i, int k){
    if(i==n-1)
        return 0;
    if(dp[i][k]!=-1)
        return dp[i][k];
    dp[i][k] = n+1;
    for(int j=0;j<4;j++){
        dp[i][k] = min(solve(i+1,j)+((j==k && arr[i]!=arr[i+1]) || (k<j && arr[i]>=arr[i+1]) || (k>j && arr[i]<=arr[i+1])),dp[i][k]);
    }
    return dp[i][k];
}

int main(){ 
    int t, caso=0;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> arr[i];
        ll answ = n+1;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<4;i++)
            answ = min(answ,solve(0,i));
        cout << "Case #" << ++caso << ": " << answ <<'\n';
    }

    return 0;
}   