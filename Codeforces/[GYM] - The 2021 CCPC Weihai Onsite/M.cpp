#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

ll n, m, k, fat[maxn], inv[maxn];
const ll mod = 998244353;

ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y>>=1){
        if(y&1)
            answ = (answ*x)%mod;
        x = (x*x)%mod;
    }
    return answ;
}

void precomp(){   
    fat[0] = inv[0] = 1;
    for(int i=1;i<maxn;i++){
        fat[i] = (i*fat[i-1])%mod;
        inv[i] = binpow(fat[i],mod-2);
    }
}

ll comb(ll n, ll k){
    if(n<k) return 0;
    return (((fat[n]*inv[k])%mod)*inv[n-k])%mod;    
}

ll solve(ll k){
    ll answ = 0, sinal = -1, grupos = n-m+1;
    answ = comb(m+grupos-1,grupos-1);
    for(int i=1;i<=grupos;i++){
        answ = (answ + sinal*(comb(m+grupos-1-k*i,grupos-1)*comb(grupos,i))%mod)%mod;
        if(answ<0) answ = (answ+mod)%mod;
        sinal = -sinal;
    }
    return answ;
}

int main(){
    precomp();
    cin >> n >> m >> k;
    ll answ = ((solve(k+1)-solve(k))%mod+mod)%mod;
    if(k==0) answ = (m==0);
    cout << answ <<"\n";
    return 0;
}