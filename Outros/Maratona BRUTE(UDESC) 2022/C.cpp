#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> tot(ll n){
    vector<ll> phi(n+1);

    for(int i=0;i<=n;i++) 
        phi[i] = i;

    for(int i=2;i<=n;i++)
        if(phi[i]==i)
            for(int j=i;j<=n;j+=i)
                phi[j] -= phi[j]/i;

    return phi;
}

int main(){
    int n;

    cin >> n;

    auto phi = tot(n);
    const ll mod = 1e9+7;
    ll answ = 0;
    for(int i=2;i<=n;i++){
        answ = (answ+phi[i])%mod;
    }

    cout << answ <<"\n";

    return 0;
}