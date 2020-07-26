#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t, answ;
    ll n, x, y;

    cin >> t;
    while(t--){
        cin >> x >> y >> n;
        answ = ((n)/x)*x + y;
        if(answ>n){
            answ-=x;
        }
        cout << answ << '\n';
    }

    return 0;
}