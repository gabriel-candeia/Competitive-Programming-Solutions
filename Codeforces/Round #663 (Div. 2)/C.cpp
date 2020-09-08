#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

int main(){
    ll n, fat=1, pot=1;


    cin >> n;
    for(ll i=1;i<=n;i++){
        fat = (fat*i)%mod;   
    }
    for(ll i=1;i<=n-1;i++){
        pot = (pot*2ll)%mod;
    }
    cout << ((fat-pot)%mod+mod)%mod <<'\n';

    return 0;
}