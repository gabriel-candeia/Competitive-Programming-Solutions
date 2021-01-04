#include<bits/stdc++.h>
#define ll long long
#define maxn 25
using namespace std;

const ll mod = 1e9+7;
ll fat[maxn], n;

void precomp(){
    fat[0] = fat[1] = 1;
    for(int i=2;i<=20;i++)
        fat[i] = (i*fat[i-1])%mod;
}

ll binpow(ll a, ll b){
    ll result = 1;
    while(b){
        if(b%2)
            result = (result*a)%mod;
        a = (a*a)%mod;
        b/=2;
    }
    return result;
}

ll inv(ll x){
    return binpow(x,mod-2);
}

ll comb(ll n, ll k){
    return ((fat[n]*inv(fat[k]))%mod*inv(fat[n-k]))%mod;
}

int main(){
    cin >> n;
    precomp();
    ll answ = 0;
    for(int i=0;i<=n;i++){
        answ = (answ+((i%2) ? -1 : 1)*(comb(n,i)*fat[n-i])%mod)%mod;
    }

    cout << (answ+mod)%mod <<'\n';
}