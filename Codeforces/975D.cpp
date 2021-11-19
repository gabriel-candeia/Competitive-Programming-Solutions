#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, a, b;
    map<pair<ll,ll>,ll> repetidos;
    map<ll,ll> mp;
    ll answ = 0;

    cin >> n >> a >> b;
    for(int i=0;i<n;i++){
        ll x, y, vx, vy;
        cin >> x >> vx >> vy;
        answ += (mp[{a*vx-vy}]-repetidos[{vx,vy}]);
        mp[{a*vx-vy}]++;
        repetidos[{vx,vy}]++;
    }

    cout << 2*answ <<"\n";

    return 0;
}