#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll a, ll b){
    ll x=0, pot=1;
    while(a && b){
        x += pot*(a%2 || b%2);
        pot*=2;
        a/=2;
        b/=2;
    }
    return x;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll x = 0, a, b;
        cin >> a >> b;
        x = solve(a,b); 
        cout << ((a^x)+(b^x)) <<'\n';
    }
    return 0;
}