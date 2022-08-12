#include<bits/stdc++.h>
#define ll long long
#define maxn int(5e5+5)
using namespace std;

const ll mod = 1e9+7;
ll fat[maxn], inv[maxn];

ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y/=2){
        if(y&1)
            answ = (answ*x)%mod;
        x = (x*x)%mod;
    }
    return answ;
}

void precomp(){
    fat[0] = inv[0] = 1;
    for(ll i=1;i<maxn;i++){
        fat[i] = (fat[i-1]*i)%mod;
        inv[i] = binpow(fat[i],mod-2);
    }
}

ll comb(ll n, ll k){
    return (((fat[n]*inv[k])%mod)*inv[n-k])%mod;
}

int main(){
    precomp();
    int n;
    cin >> n;
    
    ll answ = 1;
    for(int i=n;i>=2;i--){
        answ = (answ*comb(i,2))%mod;
    }

    cout << answ <<"\n";

    return 0;
}