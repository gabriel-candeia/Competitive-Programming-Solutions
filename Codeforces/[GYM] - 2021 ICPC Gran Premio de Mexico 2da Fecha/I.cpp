#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll prod(ll a){
    ll answ = 1;
    while(a){
        answ = answ*(a%10);
        a/=10;
    }
    return answ;
}

ll solve(ll a){
    if(a<10)
        return 0;
    return 1+solve(prod(a));
}

int main(){
    int t;

    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << solve(n) <<"\n";
    }
    return 0;
}