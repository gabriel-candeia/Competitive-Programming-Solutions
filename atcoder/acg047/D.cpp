#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

int main(){
    ll l, h, n;
    vector<ll> p, acm, rem;

    cin >> h;
    l = 1<<(h-1);
    n = 2*l;
    p.assign(l,0);
    acm.assign(2*l,0);
    rem.assign(2*l,0);
    for(int i=0;i<l;i++){
        cin >> p[i];
    }

    acm[1] = 1;
    for(int i=1;i<l;i++){
        acm[2*i] = (2*i*acm[i])%mod;
        acm[2*i+1] = ((2*i+1)*acm[i])%mod;
    }

    rem[1] = 1;
    for(int i=1;i<l;i++){
        rem[2*i] = ((rem[i]*rem[i])%mod*(2*i))%mod;
        rem[2*i+1] = ((rem[i]*rem[i])%mod*(2*i+1))%mod;
    }

    int answ = 0;
    for(int i=l+1;i<n;i++){
        answ += acm[l]*acm[l+p[0]-1]*acm[i]*acm[i+p[i]-1]
    }


    return 0;
}