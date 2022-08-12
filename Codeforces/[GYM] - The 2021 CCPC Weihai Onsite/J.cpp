#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, d, mult;
        cin >> a >> b;
        d = __gcd(a,b);
        a/=d; b/=d;
        mult = 180ll/__gcd(180ll,a);
        cout << (b*(mult)-1) << "\n";
    }

    return 0;
}