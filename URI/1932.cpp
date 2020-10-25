#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

ll arr[maxn], n, c, dp[maxn][2];

int solve(int i, bool t){
    if(dp[i][t]!=-1)
        return dp[i][t];
    if(i==n)
        return dp[i][t] = n;
    dp[i][t] = solve(i+1,t);
    if(t)
        dp[i][t] = max(dp[i][t],solve(i+1,!t)+arr[i]);
    else
        dp[i][t] = max(dp[i][t],solve(i+1,!t)-arr[i]-c);
    return dp[i][t];
}

ll solve_it(){
    dp[0][1] = -1e16;
    for(int i=0;i<=n;i++){
        dp[i+1][0] = max(dp[i][0],dp[i][1]+arr[i]);
        dp[i+1][1] = max(dp[i][1],dp[i][0]-arr[i]-c);
    }
    return dp[n][0];
}

int main(){
    cin >> n >> c;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        //dp[i][0] = -1;
        //dp[i][1] = -1;
    }
    cout << solve_it()<<'\n';
    return 0;
}