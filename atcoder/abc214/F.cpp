#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = int(1e9+7);

int main(){
    int n;
    string s;
    vector<ll> dp, last;
    map<char,ll> mp;

    cin >> s;
    n = s.size();
    
    dp.assign(n+10,0);
    last.assign(n+10,0);
    dp[0] = 1, dp[1] = 1;

    for(int i=0;i<n;i++){
        last[i+2] = mp[s[i]];
        mp[s[i]] = i+2;
    }

    for(int i=2;i<n+2;i++){
        if(last[i]!=i-1){
            dp[i] = dp[i-2];
            if(last[i]-1>=0)
                dp[i] = (dp[i]-dp[last[i]-1])%mod;
        }
        dp[i] = (dp[i]+dp[i-1])%mod;
    }

    cout << (dp[n+1]-1+mod)%mod << "\n";

    return 0;
}