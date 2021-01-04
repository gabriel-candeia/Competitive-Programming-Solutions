#include<bits/stdc++.h>
#define maxn 200
#define maxm 15005
#define ll long long
using namespace std;


const ll mod = 1e9+7;
ll dp[2][maxn][maxm], coin[2][maxn], lim[2], w, dif;
void solve(ll k){
    ll n = lim[k];
    dp[k][0][0] = 1;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<=w;j++){
            if(!dp[k][i][j]) continue;
            dp[k][i+1][j] = (dp[k][i+1][j]+dp[k][i][j])%mod;
            if(j+coin[k][i]<=w)    
                dp[k][i+1][j+coin[k][i]] = (dp[k][i+1][j+coin[k][i]]+dp[k][i][j])%mod;
        }
    }
}

ll calc(){
    ll acm=0;
    for(ll i=0;i<=w;i++)
        if(abs(w-2*i)<=dif)
            acm = (acm+(dp[0][lim[0]][i])*(dp[1][lim[1]][w-i])%mod);
    return (acm+mod)%mod;
}

int main(){
     ll t;
    cin >> t;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin >> lim[0] >> lim[1] >> dif >> w;
        for(ll j=0;j<2;j++)
            for(ll i=0;i<lim[j];i++)
               cin >> coin[j][i];

        solve(0);
        solve(1);

        cout << calc() <<'\n';
    }


    return 0;
}