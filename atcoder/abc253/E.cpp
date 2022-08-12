#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;

int main(){
    ll n, m, k;

    cin >> n >> m >> k;
    vector<ll> dp(m+1,0), suff(m+2,0), preff(m+2,0);

    if(k==0){
        ll answ = 1;
        for(int i=0;i<n;i++)
            answ = (answ*m)%mod;
        cout <<answ <<"\n";
    }
    else{
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=m;j++){
                dp[j] = 0;
                if(j-k>0) dp[j] = (dp[j] + preff[j-k])%mod;
                if(j+k<=m) dp[j] = (dp[j] + suff[j+k])%mod;
                if(i==n-1) dp[j] = 1;
            }
            for(int j=1;j<=m;j++){
                preff[j] = (preff[j-1]+dp[j])%mod;
            }
            for(int j=m;j>0;j--){
                suff[j] = (suff[j+1]+dp[j])%mod;
            }
        }

        cout << suff[1] <<"\n";
    }

    return 0;
}