#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e6+5)
using namespace std;

const ll mod = 1e9+7;
ll binpow(ll x, ll y, const ll mod){
    ll answ = 1;
    for(;y;y>>=1){
        if(y&1){
            answ = (answ*x)%mod;
        }
        x = (x*x)%mod;
    }
    return answ;
}

ll fat[maxn], inv[maxn];
void precomp(){
    fat[0] = fat[1] = 1;
    inv[0] = inv[1] = 1;
    for(int i=2;i<maxn;i++){
        fat[i] = (i*fat[i-1])%mod;
        inv[i] = binpow(fat[i],mod-2,mod);
    }
}

ll comb(ll n, ll k){
    return (((fat[n]*inv[n-k])%mod)*inv[k])%mod;
}

int main(){
    precomp();
    ll n, k, m;
    cin >> n >> m >> k;

    ll answ = 0;
    if(n>=k){
        for(int i=0;i<k;i++){
            ll sinal = (i%2 ? -1 : 1);
            answ = (answ + sinal*(comb(k,i)*binpow(k-i,n,mod))%mod)%mod;
            if(answ<0) answ += mod;
        }
        answ = (answ*comb(m,k))%mod;
    }

    cout << answ <<"\n";

    return 0;
}