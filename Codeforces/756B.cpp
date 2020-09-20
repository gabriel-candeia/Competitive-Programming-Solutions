#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e16;
int main(){
    ll n;
    vector<ll> dp, x;

    cin >> n;
    x.assign(n+1,0);
    for(int i=0;i<n;i++)
        cin >> x[i];

    dp.assign(n+1,inf); dp[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n && x[j]<=x[i]+90-1;j++)
            dp[j+1] = min(dp[j+1],dp[i]+50);
        for(int j=i;j<n && x[j]<=x[i]+1440-1;j++)
            dp[j+1] = min(dp[j+1],dp[i]+120);
        dp[i+1] = min(dp[i+1],dp[i]+20);
    }

    for(int i=1;i<=n;i++)
        cout << dp[i]-dp[i-1] <<'\n';

    return 0;
}