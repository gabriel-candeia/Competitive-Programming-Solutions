#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t, l, r;

    cin >> t;
    while(t--){
        cin >> l >> r;
        if(2*l<=r){
            cout << l << " " << 2*l <<'\n';
        }
        else{
            cout << -1 << " " << -1 <<'\n';
        }
    }

    return 0;
}