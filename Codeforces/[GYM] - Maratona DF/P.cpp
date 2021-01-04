#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    return ((!b) ? a : gcd(b,a%b));
}

int main(){
    ll d, s, f;
    cin >> d >> s >> f;

    cout << gcd(gcd(d,s),f) <<'\n';

    return 0;
}