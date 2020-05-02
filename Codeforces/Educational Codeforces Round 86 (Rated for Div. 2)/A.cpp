#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll min(ll x, ll y){
    return (x<y) ? x : y;
}

ll abs1(ll x){
    return (x>0) ? x : -x;
}

int main(){
    ll n, a, b, x, y;

    cin >> n;
    while(n--){
        cin >> x >> y;
        cin >> a >> b;

        cout << min(a*x+a*y,a*(abs1(y-x))+b*min(x,y)) << '\n';
    }
    return 0;
}