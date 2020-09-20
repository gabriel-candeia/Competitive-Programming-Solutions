#include<bits/stdc++.h>
#define maxn 505
#define maxm 65000
#define ll long long
using namespace std;

ll dp[maxn][maxm];
const ll mod = 1e9+7;
ll binpow(ll a, ll b){
    ll result=1;
    while(b){
        if(b%2)
            result=(result*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return result;
}

ll inverso(ll a, ll p){
    return binpow(a,p-2);
}

int main(){
    ll n, m;

    cin >> n;
    m = (n*(n+1))/4;
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            if(j+i+1<=m)
                dp[i+1][j+i+1]=(dp[i+1][j+i+1]+dp[i][j])%mod;
            if(abs(j-(i+1))<=m)
                dp[i+1][abs(j-(i+1))]=(dp[i+1][abs(j-(i+1))]+dp[i][j])%mod;
        }       
    }

    cout << (dp[n][0]*inverso(2,mod))%mod << '\n';

    return 0;
}