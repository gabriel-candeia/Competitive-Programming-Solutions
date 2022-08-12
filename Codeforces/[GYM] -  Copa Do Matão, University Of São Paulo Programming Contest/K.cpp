#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll n, k;
ll v[int(1e6)+10];
map<ll, ll> mapa;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cin >> n >> k;
    bool ok = true;
    for(ll i = 0; i < n; i++) cin >> v[i];
    for(ll i = 0, num; i < n; i++){
        cin >> num;
        v[i] = (v[i]+num)%k;
    }
    for(ll i = 0; i < n; i++){
        mapa[v[i]]++;
        if(mapa[v[i]] >= 2) ok = false;
        if(v[i] >= n) ok = false;
    }
    cout << (ok ? "S" : "N") << "\n";
    return 0;
}