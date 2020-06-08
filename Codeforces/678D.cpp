#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = int(1e9)+7;

ll binpow(ll a, ll b, ll mod){
    if(b==0){
        return 1;
    }
    ll temp = binpow(a,b/2,mod);
    temp = (temp*temp)%mod;
    if(b%2){
        return (temp*a)%mod;
    }
    return temp;
}

ll modularinverse(ll x, ll p){
    return binpow(x,p-2,p);
}   

int main(){
    ll a, b, x, n, an;

    cin >> a >> b >> n >> x;
    if(a==1){
        cout << (x + (1ll*b*(n%mod))%mod)%mod << '\n';
    }
    else{
        an = binpow(a,n,mod);

        cout << ((an*x)%mod + (1ll*(b*((an-1+mod)%mod))%mod*modularinverse(a-1,mod))%mod)%mod << '\n';
    }
    return 0;
}