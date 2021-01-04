#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1e9+7;
ll binpow(ll x, ll y){
    ll result = 1;
    while(y){
        if(y%2)
            result = (result*x)%mod;
        x = (x*x)%mod;
        y/=2;
    }
    return result;
}

ll inv(ll x, ll p){
    return binpow(x,p-2);
}

ll fat(ll x){
    ll answ = 1;
    for(int i=1;i<=x;i++)
        answ = (answ*i)%mod;
    return answ;
}

int main(){
    ll n, m, x, y;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
    }
    ll answ = ((fat(n)*inv(fat(n-2*m),mod))%mod*inv(binpow(2,m),mod))%mod;
    answ = (answ*fat(n-2*m))%mod;
    cout <<  answ << '\n';
    return 0;
}
