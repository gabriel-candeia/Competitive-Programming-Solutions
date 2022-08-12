#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1e9+9;

ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y>>=1){
        if(y&1){
            answ = (x*answ)%mod;
        }
        x = (x*x)%mod;
    }
    return answ;
}

int main(){
    ll n, k, answ = 0, sinal = 1;
    cin >> n >> k;
    
    for(int j=n-1;j>=1;j--){
        answ = ((answ + (sinal*k*binpow(k-1,j))%mod)%mod + mod)%mod;
        sinal = ((sinal==1) ? -1 : 1);
    }

    cout << answ <<"\n";

    return 0;
}