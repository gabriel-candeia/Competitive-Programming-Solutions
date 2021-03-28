#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b, ll&x, ll &y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    ll d = gcd(b,a%b,x,y);
    ll x1 = y;
    ll y1 = x-(a/b)*y;
    x = x1; y = y1;
    return d;
}

ll lcm(ll a, ll b){
    return (a/__gcd(a,b))*b;
}


int main(){
    ll n, m, x, y, d;

    cin >> n >> m;
    d = gcd(n,m,x,y);
    if(n==1 && m==1){
        cout << 1 << '\n';
    }
    else if(n==1 || m==1){
        cout << 2 << '\n';
    }
    else if(d==1){
        x = min(abs(x)%(m/d),(x+m/d)%(m/d));
        y = min(abs(y)%(n/d),(y+n/d)%(n/d));
        cout << min(max(n*x,m*y),lcm(n,m)) << "\n";
    }
    else{
        cout << lcm(n,m) << "\n";
    }
    return 0;
}