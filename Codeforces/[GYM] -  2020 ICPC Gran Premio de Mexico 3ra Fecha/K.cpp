#include <bits/stdc++.h>
using namespace std;
#define maxn int(1e5+10)
typedef long long int ll;

const ll mod = 1e9+7;
ll t;
ll fat[maxn], invfat[maxn];

ll binpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans;
}

ll inv(ll a){
    return binpow(a, mod-2);
}

ll comb(ll n, ll k){
    if(n<k) return 0;
    return (((fat[n]*invfat[k])%mod)*invfat[n-k])%mod;
}

ll comp(int a, int b, int k){
    ll answ = 0;
    for(int i=max(1,k-b); i<=min(a,k) ;i++){
        if(i<=k && k-i<=b && k-i>=1){
            answ = (answ + comb(a,i)*comb(b,k-i))%mod;
        }
    }
    return answ;
}

int main(){
    int t;
    cin >> t;
    
    fat[0] = 1;
    invfat[0] = 1;
    for(int i = 1; i < maxn;i++){
        fat[i] = (fat[i-1]*i)%mod;
        invfat[i] = inv(fat[i]);
    }
    
    while(t--){
        ll a, b, c, k, rem;

        cin >> a >> b >> c >> k >> rem;
        
        ll answ = 0;
        k-=rem;
        answ = (comb(c,rem)*((comb(a+b,k) - comb(a,k) - comb(b,k))%mod+mod)%mod)%mod;
        cout << answ <<"\n";
    }

    return 0;
}