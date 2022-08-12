#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const ll mod = 998244853;
int n, m, k;
map<tuple<int,int,int>,int> edges;
map<pair<int,int>,int> sz;

ll binpow(ll a, ll e){
    if(e<0) return 0;
   ll ans = 1;
   while(e){
      if(e&1) ans = (ans*a)%mod;
      a = (a*a)%mod;
      e >>= 1;
   }
   return ans;
}

ll inv(ll num){
   return binpow(num, mod-2);
}

int main(){
    fastio();
    cin >> n >> m >> k;

    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[{min(a,b),max(a,b),c}]++;
        sz[{min(a,b),max(a,b)}]++;
    }

    vector<int> seq(k,0);
    for(int i=0;i<k;i++){
        cin >> seq[i];
    }
    
    bool ok = true;
    ll answ = 0;
    for(int i=0;i<k-1;i++){
        bool ok1 = false;
        int a = min(seq[i],seq[i+1]), b = max(seq[i],seq[i+1]);
        ll total = inv(sz[{a,b}]), pot = binpow(10,k-i-2);
        for(ll peso = 1;peso<10;peso++){
            ll qtd = edges[{a,b,peso}];
            if(qtd) ok1 = true;
            answ = (answ + ((((pot*peso)%mod)*qtd)%mod)*total)%mod;
            
        }
        if(!ok1) ok = false;
    }
    
    if(ok){
        cout << answ <<"\n";
    }
    else{
        cout << "Stupid Msacywy!" <<"\n";
    }

    return 0;
}