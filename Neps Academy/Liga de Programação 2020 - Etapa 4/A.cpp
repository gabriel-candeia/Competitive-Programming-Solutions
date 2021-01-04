#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, p, x, y;

    cin >> n >> p >> x >> y;

    if(n*p<x*y)
        cout << "BUFF\n";
    else
        cout << "NERF\n";
    return 0;
}