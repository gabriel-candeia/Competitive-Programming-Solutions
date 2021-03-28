#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;
ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y/=2, x = (x*x)%mod)
        if(y&1)
            answ = (answ*x)%mod;
    return answ;
}

ll fat(ll x){
    ll answ = 1;
    for(ll i = 1;i<=x;i++)
        answ = (answ*i)%mod;
    return answ;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n,0);
        for(auto &x:arr)
            cin >> x;
        sort(arr.rbegin(),arr.rend());
        ll p = 0, q = 0;
        for(int i=0;i<n;i++)
            p+=(arr[i]==arr[k-1]);

        for(int i=0;i<k;i++)
            q+=(arr[i]==arr[k-1]);

        ll answ = ((fat(p)*binpow(fat(q),mod-2))%mod*binpow(fat(p-q),mod-2))%mod;
        cout << answ << '\n';
    }

    return 0;
}