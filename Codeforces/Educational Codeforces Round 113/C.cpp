#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define ll long long
using namespace std;

const ll mod = 998244353;
ll fact[maxn];

void precomp(){
    fact[0] = 1;
    for(int i=1;i<maxn;i++)
        fact[i] = (fact[i-1]*i)%mod;
}

ll binpow(ll x, ll y){
    ll answ = 1;
    while(y){
        if(y&1)
            answ = (answ*x)%mod;
        x = (x*x)%mod;
        y>>=1;
    }
    return answ;
}

ll inv(ll x){
    return binpow(x,mod-2);
}

ll comb(ll n, ll m){
    return (((fact[n]*inv(fact[m]))%mod)*inv(fact[n-m]))%mod;
}

int main(){
    precomp();
    int t;
    cin >> t;
    while(t--){
        int n;
        vector<int> arr;
        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        sort(arr.begin(),arr.end());

        if(arr[n-1]-arr[n-2]==0){
            cout << fact[n] << "\n";
        }
        else if(arr[n-1]-arr[n-2]>1){
            cout << 0 <<"\n";
        }
        else{
            ll answ = ((fact[n] - fact[n-1])%mod + mod)%mod;
            int k = 0;
            for(int i=0;i<n && arr[i]<arr[n-2];i++){
                k++;
            }
            for(int i=1;i<=k;i++){
                answ = ((answ - (((fact[n-1-i]*fact[i])%mod)*comb(k,i))%mod)%mod+mod)%mod;
            }
            cout << answ <<"\n";
        }
    }

    return 0;
}