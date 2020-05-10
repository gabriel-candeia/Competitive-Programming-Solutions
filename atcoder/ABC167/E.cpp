#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
vector<ll> fat;

void precompute(ll n){
    fat.clear();
    fat.push_back(1);
    for(int i=1;i<=n;i++){
        fat.push_back((fat.back()*i)%mod);
    }
}

ll binpow(ll a, ll b){
    if(b==0){
        return 1ll;
    }
    ll temp = binpow(a,b/2)%mod;
    if(b%2){
        return (((temp*temp)%mod)*a)%mod;
    }
    return (temp*temp)%mod;
}

ll modInverse(ll x){
    return binpow(x,mod-2);
}

ll c(ll n, ll m){
    return (fat[n]*modInverse(fat[m])%mod * modInverse(fat[n-m]%mod)%mod)%mod;
}

int main(){
    ll n, m, k, acm=0;

    cin >> n >> m >> k;
    precompute(n);
    for(int i=0;i<=k;i++){
        acm = (acm + 1ll*((c(n-1,i)%mod)*((m*binpow(m-1,n-1-i))%mod))%mod)%mod;
    }

    cout << acm%mod << '\n';

    return 0;
};
