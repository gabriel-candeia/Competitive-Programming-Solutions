//something with baby step giant step but code is wrong.

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, x0, mod, x;

ll binpow(ll a, ll e){
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

ll fraiz(ll x){
    ll answ = 0;
    for(;answ*answ<x;answ++);
    return answ;
}

int main(){ 
    cin >> a >> b >> mod >> x0 >>  x;
    if(a==0){
        cout << ((x==x0 || x==b) ? "YES" : "NO") <<"\n";
    }
    else if(a==1){
        cout << ((b!=0 || (b==0 && x0==x)) ? "YES" : "NO") <<"\n";
    }
    else{
        //714618103
        ll raiz = fraiz(mod), aux = x0, curr = x0;
        set<ll> st;
        st.insert(curr);

        for(int i=1;i<=raiz;i++){
            curr = (((curr*a)%mod+b)%mod);   
            st.insert(curr);
        }
        for(int i=1;i<raiz;i++){
            aux = (((aux-b+mod)%mod)*inv(a))%mod;
        }
        bool ok = false;
        for(int i=0;i<raiz;i++){
            if(st.find(x)!=st.end()){
                ok = true;
                break;
            }
            else{
                x = (x*aux)%mod;
            }   
        }
        cout << ((ok) ? "YES" : "NO") <<"\n";
    }

    return 0;
}