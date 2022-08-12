#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y/=2){
        if(y&1){
            answ = (answ*x)%mod;
        }
        x = (x*x)%mod;
    }
    return answ;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, m, k;
        vector<vector<ll>> dp;
        cin >> n >> m >> k;

        ll inv2 = binpow(2,mod-2);
        //cout << 5*inv2 <<"\n";
        dp.assign(n+1,vector<ll>(m+1,0));
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=min(i,m);j++){
                if(i==j) dp[i][i] = (k*i)%mod;
                else dp[i][j] = ((((dp[i-1][j]-dp[i-1][j-1]+mod)%mod)*inv2)%mod +dp[i-1][j-1])%mod;
                //cout << dp[i][j] << " ";
            }
            //cout<<"\n";
        }
        cout << dp[n][m] <<"\n";
    }

    return 0;
}