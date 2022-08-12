#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;

ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y>>=1, x = (x*x)%mod)
        if(y&1)
            answ = (answ*x)%mod;
    return answ;
}

int main(){
    int n, l;
    vector<ll> arr;

    cin >> n >> l;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        ll msk = 0;
        for(auto c:s){
            msk = msk | (1<<(c-'a'));
        }
        arr.push_back(msk);
    }

    ll answ = 0;
    for(int i=1;i<(1<<n);i++){
        ll st = (1<<26)-1;
        for(int j=0;j<n;j++)
            if(i&(1<<j))
                st = st&arr[j];
        
        ll x = __builtin_popcountll(st);
        if(__builtin_popcountll(i)%2)
            answ = (answ + binpow(x,l))%mod;
        else
            answ = ((answ - binpow(x,l))%mod + mod)%mod;
    }

    cout << answ <<"\n";

    return 0;
}