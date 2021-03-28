#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll x){
    return ((x%2) ? f(x/2) : x/2);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll game = 0, n;
        cin >> n;
        for(ll i=0, x;i<n;i++){
            cin >> x;
            game ^= f(x);
        }

        
        cout << ((game) ? "YES" : "NO") << '\n';
    }


    return 0;
}