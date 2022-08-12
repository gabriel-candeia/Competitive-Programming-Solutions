#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

const ll mod = 1e9+7;
ll binpow(ll x, ll y, const ll m){
    ll answ = 1;
    while(y){
        if(y&1)
            answ = (answ*x)%m;
        y >>= 1;
        x = (x*x)%m;
    }
    return answ;
}

ll inv(ll x){
    return binpow(x,mod-2,mod);
}

ll fat[maxn];
void precomp(){
    fat[0] = fat[1] = 1;
    for(int i=2;i<maxn;i++){
        fat[i] = (i*fat[i-1])%mod;
    }
}

ll comb(ll n, ll k){
    return (((fat[n]*inv(fat[k]))%mod)*inv(fat[n-k]))%mod;
}

int main(){
    precomp();
    int n;
    vector<ll> arr;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    ll answ = 0;
    for(int i=0;i<n;i++){
        answ = (answ + comb(n-1,i)*arr[i])%mod;
        
    }

    cout << answ <<"\n";

    return 0;
}