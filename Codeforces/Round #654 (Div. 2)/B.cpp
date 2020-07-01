#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t, n, r;

    cin >> t;
    while(t--){
        cin >> n >> r;
        if(r>=n){
            cout << 1ll*n*(n-1)/2 + 1 << '\n';
        }
        else{
            cout << 1ll*r*(r+1)/2 << '\n';
        }
    }

    return 0;
}