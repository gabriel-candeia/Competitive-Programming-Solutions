#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

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

ll comb(ll n, ll k){
    vector<ll> fat(n+1,1);
    for(int i=2;i<=n;i++)
        fat[i] = (i*fat[i-1])%mod;
    return (((fat[n]*binpow(fat[k],mod-2))%mod)*binpow(fat[n-k],mod-2))%mod;    
}


int main(){ 
    ll t;
    int n;
    vector<ll> c;

    cin >> t;
    while(t--){
        cin >> n;
        c.assign(n,0);

        for(int i=0;i<n;i++){
            cin >> c[i];
        }

        sort(c.begin(),c.end());
        int i=n-1,qtd=0;
        while(i>=0 && c[i]==c[n-1]){
            i--;
            qtd++;
        }i++;

        ll answ=0;
        answ = binpow(2,qtd);
        if(qtd%2==0)
            answ =((answ-comb(qtd,qtd/2))+mod)%mod;
        answ = (answ*binpow(2,i))%mod;
        cout << answ <<'\n';
    }

    return 0;
} 



