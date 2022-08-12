#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll soma(ll x){
    return (x*(x+1))/2;
}

int main(){
    ll n, a, b, d;

    cin >> n >> a >> b;
    d = (a*b)/__gcd(a,b);

    cout << soma(n) - (a*soma(n/a) + b*soma(n/b)) + d*soma(n/d) <<"\n";

    return 0;
}