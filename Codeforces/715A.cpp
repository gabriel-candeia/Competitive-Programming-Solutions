#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    return ((a/gcd(a,b))*b);
}

int main(){
    ll n;

    cin >> n;

    cout << 2 <<'\n';
    for(int i=2;i<=n;i++){
        cout << 1ll*(i+1)*(i+1)*i-(i-1) << '\n';
    }

    return 0;
}