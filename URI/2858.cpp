#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b, ll &x, ll &y){
    if(b==0){
        x = 1;
        y = 1;
        return a;
    }
    ll d = gcd(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t-(a/b)*y;
    return d;
}

int main(){
    ll e, d, x, y, resp;

    cin >> e >> d;
    resp = gcd(e,d,x,y);
    if(resp==1){
        cout << min(abs(x+d)+abs(y-e),abs(x-d)+abs(y+e))<<'\n';
    }
    else{
        cout << "IMPOSSIVEL" <<'\n';
    }

    return 0;
}