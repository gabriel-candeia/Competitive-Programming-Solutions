#include<bits/stdc++.h>
#define maxn 105
#define maxm int(1e5+5)
#define ll long long
using namespace std;

/*
    In the iterative implementation it is possible to use preffix sum to optimize the following 
    summation:
            dp[i+1][j+x]+=dp[i][j] for 0<=x<=a[i]
    Hence, the complexity becomes O(n*k).
*/
const ll mod = 1e9+7;
ll a[maxn], dp[2][maxm], n, k;
ll solve(){
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        int curr = i%2, nxt = (i+1)%2;
        for(int j=0;j<=k;j++){
            dp[nxt][j] = (dp[nxt][j]+dp[curr][j])%mod;
            if(j+a[i]+1<maxm) dp[nxt][j+a[i]+1] = (dp[nxt][j+a[i]+1]-dp[curr][j])%mod;
            dp[curr][j+1] = (dp[curr][j+1]+dp[curr][j])%mod;
            dp[curr][j] = 0;
        }
    }
    return (dp[n%2][k]%mod+mod)%mod;
}

/*
    In the recursive implementation I could not find a way to optimize the summation shown above.
    Hence, the complexity becomes O(a[0]*k+a[1]*k+a[2]*k+..a[n-1]*k) which, since a[i] = o(k), 
    is o(n*k*k).
*/
/*ll memo[maxn][maxm];
ll solve_rec(int i, int j){
    if(j==k)
        return memo[i][j] = 1;
    else if(i==n || j>k)
        return memo[i][j] = 0;
    if(memo[i][j]!=-1)
        return memo[i][j];
    memo[i][j] = 0;
    for(int k=0;k<=a[i];k++){
        memo[i][j] = (memo[i][j]+solve_rec(i+1,j+k))%mod;
    }
    return memo[i][j];
}*/

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << solve() <<'\n';

    memset(memo,-1,sizeof(memo));
    cout << solve_rec(0,0) <<'\n';
    return 0;
}