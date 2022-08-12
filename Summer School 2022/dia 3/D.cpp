#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;
#define ll long long

bool ok(ll x, ll y, ll a, ll b, ll r){
    return (((x-a)*(x-a)) + ((y-b)*(y-b))) <= r*r;
}

int main(){
    fastio();
    ll x, y, r, n, a, b;
    cin >> x >> y >> r >> n;
    set<pair<ll, ll>> cj;
    for(ll i = 0; i < n; i++){
        cin >> a >> b;
        a -= x; b -= y;
        ll gcd = ((a==0 || b==0) ? 1 : __gcd(abs(a), abs(b)));
        if(ok(0, 0, a, b, r))
            cj.insert({a/gcd, b/gcd});
    }
    cout << cj.size() << "\n";
    return 0;
}