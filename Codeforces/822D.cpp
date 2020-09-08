#include<bits/stdc++.h>
#define ll long long
#define N int(5e6+7)
using namespace std;

const ll mod = 1e9+7;
ll fat[N], f[N], sieve[N];

void init(){
    fat[0] = 1;
    for(int i=1;i<N;i++){
        fat[i] = (i*fat[i-1])%mod;
    }
}

ll binpow(ll x, ll y){
    ll result = 1;
    while(y){
        if(y%2)
            result = (result*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return result;
}

ll inv(ll x){
    return binpow(x,mod-2);
}

ll comb(ll n, ll m){
    return ((fat[n]*inv(fat[m]))%mod*inv(fat[n-m]))%mod;
}

int main(){
    ll t, l, r;
    cin >> t >> l >> r;
    init();
    memset(sieve,0,sizeof(sieve));
    for(int i=2;i<=r;i++){
        if(!sieve[i]){
            f[i] = comb(i,2);
            for(int j=i;j<=r;j+=i){
                if(!sieve[j]){
                    sieve[j] = j/i;
                }
            }
        }
    }

    for(int i=2;i<=r;i++){
        if(sieve[i]!=1){
            int j = sieve[i];
            f[i] = (f[j] + (j*f[i/j])%mod)%mod;
        }
    } 

    ll answ=0, acm=1;
    for(int i=l;i<=r;i++){
        answ = (answ + acm*f[i])%mod;
        acm = (acm*t)%mod;
    }   

    cout << (answ+mod)%mod <<'\n';

    return 0;
}