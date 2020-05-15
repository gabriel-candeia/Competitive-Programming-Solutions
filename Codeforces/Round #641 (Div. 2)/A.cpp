#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll minDivisor(ll n){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            return i;
        }
    }
    return 0;
}

int main(){
    int t;
    ll n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n%2){
            k--;
            n+=minDivisor(n);
        }
        n+=k*2;
        cout << n << '\n';
    }

    return 0;
}