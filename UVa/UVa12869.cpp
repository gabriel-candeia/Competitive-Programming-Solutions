#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt(ll n){
    return n/5;
}

int main(){
    ll low, high;

    while(cin >> low >> high){
        if(!low && !high){
            break;
        }
        cout << (cnt(high) - cnt(low)+1) << '\n';
    }

    return 0;
}
