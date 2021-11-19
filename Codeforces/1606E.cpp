#include<bits/stdc++.h>
#define ll long long
#define maxn 505
using namespace std;

const ll mod = 998244353;
ll comb[maxn][maxn], dp[maxn][maxn];

void precomp(){
    for(int i=0;i<maxn;i++){
        comb[i][0] = comb[i][i] = 1;
        for(int j=1;j<i;j++){
            comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%mod;
        }   
    }
}

ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y>>=1){
        if(y&1)
            answ = (answ*x)%mod;
        x = (x*x)%mod;
    }
    return answ;
}

int main(){
    int n, x;
    
    precomp();
    
    cin >> n >> x;

    dp[0][0] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(j==1){
                dp[i][j] = 1;
            }
            else if(j<=i-1){
                dp[i][j] = (binpow(j,i) - binpow(j-1,i)+mod)%mod;
            }
            else{
                for(int mortos=0;mortos<i;mortos++){    
                    dp[i][j] = (dp[i][j] + (((dp[i-mortos][j-(i-1)]*binpow(i-1,mortos))%mod)*comb[i][mortos])%mod)%mod;
                }
            }
        }
    }

    ll answ = 0;
    for(int j=0;j<=x;j++){
        //cout << dp[n][j] << " ";
        answ = (answ+dp[n][j])%mod;
    }
    //cout<<'\n';
    cout << answ <<"\n";

    return 0;
}