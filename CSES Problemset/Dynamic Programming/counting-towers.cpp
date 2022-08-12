#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e6+5)
using namespace std;

const ll mod = 1e9+7;
ll dp[maxn][3];

int main(){

    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    for(int i=1;i<maxn;i++){
        dp[i][1] = dp[i-1][2];
        dp[i][0] = dp[i-1][1];
        dp[i][2] = (dp[i][0] + dp[i][1] + dp[i-1][2])%mod;
        dp[i][1] = (dp[i][1] + 4*dp[i-1][1])%mod;
    }
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (dp[n][2]-dp[n-1][2] + mod)%mod <<"\n";
    }

    return 0;
}