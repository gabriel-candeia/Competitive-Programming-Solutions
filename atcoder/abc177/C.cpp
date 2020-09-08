#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

int main(){
    ll n, sum=0;
    vector<ll> a;

    cin >> n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum= (sum + a[i])%mod;
    }

    ll answ=0;
    for(int i=0;i<n;i++){
        sum = ((sum-a[i])%mod+mod)%mod;
        answ = (answ + (a[i]*sum)%mod)%mod;
    }

    cout << answ <<'\n';

    return 0;
}