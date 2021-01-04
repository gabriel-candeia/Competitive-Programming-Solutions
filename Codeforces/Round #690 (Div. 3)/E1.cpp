#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

const ll mod = 1e9+7;
ll fat[maxn];

void precomp(){
    fat[0] = fat[1] = 1;
    for(int i=2;i<maxn;i++)
        fat[i] = (i*fat[i-1])%mod;
}

ll binpow(ll x, ll y){
    ll result = 1;
    for(;y;y/=2, x = (x*x)%mod)
        if(y%2)
            result = (result*x)%mod;
    return result;
}

ll inv(ll x){
    return binpow(x,mod-2);
}

ll comb(ll n, ll k){
    ll answ = 1;
    for(ll i=n;i>n-k;i--)
        answ = answ*i;
    return answ/2;
}

int main(){
    precomp();

    ll t;
    cin >> t;
    while(t--){
        ll n, m, k;
        vector<ll> arr;
        
        cin >> n; k = 2; m = 3;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        ll answ = 0;
        sort(arr.rbegin(),arr.rend());
        for(int i=0,j=0;i<n;i++){
            for(;j<n && arr[i]-arr[j]<=k;j++);
            //cout << i << " " << j << " " << arr[i] << " " << arr[j] << " " << comb(j-i-1,m-1)<< "\n";
            answ = (answ+comb(j-i-1,m-1));
        }
        cout << answ <<'\n';
    }

    return 0;
}