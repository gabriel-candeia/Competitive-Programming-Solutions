#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll binpow(ll x, ll y ,ll mod){
    ll result = 1;
    for(;y;y/=2, x = (x*x)%mod){
        if(y%2)
            result = (result*x)%mod;
    }
    return result;
}

int main(){
    ll n, m, q, r;

    cin >> n >> m;
    q = binpow(10,n,m);
    r  = (binpow(10,n,m*m)-q)%(m*m);
    cout << r/m << '\n';
}

