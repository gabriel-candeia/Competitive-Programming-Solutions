#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;
ll binpow(ll x, ll y, const ll m){
    ll answ = 1;
    while(y){
        if(y&1)
            answ = (answ*x)%m;
        y >>= 1;
        x = (x*x)%m;
    }
    return answ;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        cout << binpow(2,x+y-1,mod) <<"\n";
    }

    return 0;
}