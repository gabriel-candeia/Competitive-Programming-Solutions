#include<bits/stdc++.h>
#define N int(2e4+5)
#define ll long long
using namespace std;

const ll mod = 1e9+7;
ll fat[N]; 

ll binpow(ll x, ll y){
    ll result = 1;
    while(y){
        if(y%2){
            result = (result*x)%mod;
        }
        x = (x*x)%mod;
        y/=2;
    }
    return (result%mod);
}

ll inv(ll n){
    return binpow(n,mod-2);
}

ll comb(ll n, ll m){
    if(n-m<0 || n<0 || m<0){
        cout << 0 << '\n';
        return 0;
    }
    return ((fat[n]*inv(fat[m]))%mod*inv(fat[n-m]))%mod;
}

int main(){
    ll n, m, k, answ=0;

    cin >> n >> m >> k;

    fat[0] = 1;
    for(int i=1;i<N;i++){
        fat[i] = (i*(fat[i-1]))%mod;
    }

    ll sign = 1;
    for(int i=0;n-i*k>=m && m>=i;i++){
        answ = (answ+(sign*comb(m,i)*comb(n-i*k-1,m-1))%mod)%mod; 
        sign *= -1;
    }
    
    cout << (answ+mod)%mod << '\n';
    return 0;
}