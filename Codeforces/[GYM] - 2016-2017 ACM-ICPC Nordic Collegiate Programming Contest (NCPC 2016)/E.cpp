#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll tot(ll n){
    ll answ = n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            answ -= answ/i;
            while(n%i==0) n/=i;
        }
    }
    if(n!=1) answ -= answ/n;
    return answ;
}

ll binpow(ll x, ll y, ll mod){
    ll answ = 1%mod;
    for(;y;y/=2){
        if(y&1)
            answ = (answ*x)%mod;
        x = (x*x)%mod;
    }
    return answ;
}

ll teste(ll n, ll m){
    if(n==1) return 1;
    return binpow(n,teste(n-1,1e9),m);
}

ll solve(ll n, ll m){
    if(m==1) return 0;
    if(n<=5) return teste(n,m);
    ll mod = tot(m);
    ll answ = binpow(n,mod+solve(n-1,mod),m);
    return answ;
}


int main(){
    ll n, m;

    cin >> n >> m;
    cout << solve(n,m) <<"\n";

    return 0;
}