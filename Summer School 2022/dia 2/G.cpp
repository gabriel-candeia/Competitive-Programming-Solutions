#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e17;

int main(){
    int n, k, l;

    cin >> n >> l >> k;
    vector<ll> dist, speed;
    dist.assign(n,0);
    for(auto &x:dist)
        cin >> x;
    speed.assign(n,0);
    for(auto &x:speed)
        cin >> x;

    dist.push_back(l);
    speed.push_back(0);
    
    vector<vector<ll>> dp(n+10,vector<ll>(k+10,inf));
    dp[0][0] = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            if(j-1>=0)
                dp[i][j] = min(dp[i][j],dp[i][j-1]);
            for(int l=0;i+l+1<=n && j+l<=k;l++){
                dp[i+l+1][j+l] = min(dp[i+l+1][j+l],(dist[i+l+1]-dist[i])*speed[i]+dp[i][j]);
            }
        }
    }
    
    cout << dp[n][k] <<"\n";

    return 0;
}