#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;

    cin >> n;

    ll a, b;
    for(ll i = 1;i*i<=n;i++){
        if(n%i==0){
            a = i, b = n/i;
        }
    }

    cout << a << " " << b <<"\n";

    return 0;
}