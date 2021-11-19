#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll h, r, answ = 0, x;

    cin >> r >> h;
    answ = 2*(h/r)+1;
    x = h%r;
    answ+=(x>=r/2+r%2);
    answ+=(3*r*r < (h%r)*(h%r)*4);
    cout << answ <<"\n";

    return 0;
}