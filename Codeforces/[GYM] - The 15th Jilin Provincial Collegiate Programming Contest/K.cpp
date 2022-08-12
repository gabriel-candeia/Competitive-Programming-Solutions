#include <bits/stdc++.h>

using namespace std;

#define mod ll(1e9+7)
#define maxn ll(2e5+10)

typedef long long int ll;

ll fat[maxn], inv[maxn];

ll binpow(ll a, ll e){
   ll ans = 1;
   while(e){
      if(e&1) ans = (ans*a)%mod;
      a = (a*a)%mod;
      e >>= 1;
   }
   return ans;
}

ll invC(ll num){
   return binpow(num, mod-2);
}

ll comb(ll a, ll b){
   return (((fat[a]*inv[b])%mod)*inv[a-b])%mod;
}

int main(){
   ll n, k; cin >> n >> k;
   fat[0] = 1;
   for(int i = 1; i <= 2*n; i++) fat[i] = (fat[i-1]*i)%mod, inv[i] = invC(fat[i]);

    ll answ = comb(2*n,n);
    answ = (((answ*invC(n+1))%mod)*binpow(k,n))%mod;

    cout << answ <<"\n";
    return 0;
}
