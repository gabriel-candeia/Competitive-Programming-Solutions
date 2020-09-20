#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+9;
ll binpow(ll x, ll y){
    ll result = 1;
    while(y){
        if(y%2)
            result = (result*x)%mod;
        x = (x*x)%mod;
        y /=2;
    }
    return result;
}

ll inv(ll x){
    return binpow(x,mod-2);
}

int main(){
    ll n, a, b, k, lim;
    vector<int> sign;
    char op;

    cin >> n >> a >> b >> k;

    ll sum = 0, acm = 0;
    sign.assign(k,0);
    for(int i=0;i<k;i++){
        cin >> op;
        sign[i] = (((op=='+') ? 1 : -1));
    }
    lim = sqrt(n);
    lim = min(max(lim-lim%k,k),n+1);

    for(int i=0;i<lim;i++){
        sum = ((sum + sign[i%k]*(binpow(a,n-i)*binpow(b,i))%mod)%mod+mod)%mod;
        //sum = ((sum + sign[i%k]*(binpow(a,n-i)*binpow(b,i))));
    }

    acm = sum;
    if(lim<n){  
        for(int i=lim;i+lim<=n;i+=lim){
            acm = (acm + ((sum*binpow(b,i))%mod*inv(binpow(a,i)))%mod)%mod;
            //acm = (acm + ((sum*binpow(b,i))/(binpow(a,i))));
        }

        for(int i=n-n%lim;i<=n;i++){
            acm = ((acm + sign[i%k]*(binpow(a,n-i)*binpow(b,i))%mod)%mod+mod)%mod;
            //cout << " " << (sign[i%k]*(binpow(a,n-i)*binpow(b,i))) << "\n";
        }
    }
    cout << (acm+mod)%mod <<'\n';
    return 0;
}