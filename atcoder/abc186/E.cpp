#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main(){
    ll t;

    cin >> t;
    while(t--){
        ll n, s, k, x, y, answ = -1, d;
        cin >> n >> s >> k;
        
        d = gcd(k,n,x,y);
        if((n-s)%d==0){
            x = x*((n-s)/d);
            x = (x%(n/d)+(n/d))%(n/d);
            answ = x;
        }
        cout << answ << '\n';
    }

    return 0;
}