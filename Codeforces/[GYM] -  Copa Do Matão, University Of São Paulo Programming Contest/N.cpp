#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e4+5)
using namespace std;

vector<ll> solve(vector<ll> wt, vector<ll> v){
    ll n = wt.size();
    vector<ll> dp(maxn,0);

    for(ll i=0;i<n;i++){
        for(ll j=maxn-1;j>=wt[i];j--){
            dp[j] = max(dp[j],dp[j-wt[i]] + v[i]);
        }
    }

    return dp;
}

int main(){
    ll n, k, l;
    vector<ll> c, wp, v, wi;

    cin >> n >> k >> l;
    wp.assign(n,0); c.assign(n,0);
    for(ll i=0;i<n;i++){
        cin >> c[i] >> wp[i];
    }

    v.assign(k,0), wi.assign(k,0);
    for(ll i=0;i<k;i++){
        cin >> wi[i] >> v[i];
    }

    auto aux = solve(wi,v);
    for(auto &x:c){
        x = aux[x];
    }
    aux = solve(wp,c);

    cout << aux[l]  << "\n";

    return 0;
}