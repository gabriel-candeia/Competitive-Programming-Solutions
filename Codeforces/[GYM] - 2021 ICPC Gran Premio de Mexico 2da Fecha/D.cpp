#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll _ceil(ll a, ll b){
    return a/b + (a%b!=0);
}

int main(){ 
    int t;

    cin >> t;
    while(t--){
        ll c, r, s;

        cin >> c >> r >> s;
        ll total = _ceil(c+r,s), minimum = total - _ceil(r,s), maximum = max(total-r,0ll);

        cout << minimum << " " << maximum << "\n";
    }
    return 0;
}