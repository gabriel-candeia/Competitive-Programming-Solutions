#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

int main(){
    int t;
    int caso = 0;

    cin >> t;
    while(t--){
        int n, last;
        string s;
        vector<ll> dp;

        cin >> n >> s;
        last = n;
        dp.assign(n+1,0);

        for(int i=n-1;i>=0;i--){
            dp[i] = dp[i+1];
            if(last<n && (s[last]=='O' && s[i]=='X') || (s[last]=='X' && s[i]=='O')){
                dp[i] = (dp[i] + n-last)%mod;
            }            
            if(s[i]!='F'){
                last = i;
            }
        }
        
        ll answ = 0;
        for(int i=n-1;i>=0;i--){
            answ = (answ + dp[i])%mod;
        }

        cout << "Case #" << ++caso << ": " << answ <<"\n";

    }

    return 0;
}