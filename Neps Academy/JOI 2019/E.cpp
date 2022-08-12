#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, m;

    vector<ll> dp, prev, arr;

    cin >> n >> m;
    arr.assign(n,0); dp.assign(n,0), prev.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    for(int i=0;i<n;i++)
        prev[i] = i;

    for(int i=0;i<m;i++){
        ll l, r;
        cin >> l >> r;
        l--, r--;
        prev[r] = min(prev[r],l);
    }
    
    for(int i=n-2;i>=0;i--){
        prev[i] = min(prev[i+1],prev[i]);
    }
    
    for(int i=0;i<n;i++){
        if(i-1>=0)
            dp[i] = dp[i-1];
        ll acm = ((prev[i]-1>=0) ? dp[prev[i]-1] : 0);
        dp[i] = max(dp[i],arr[i]+acm);
    }

    cout << dp[n-1] <<"\n";

    return 0;
}