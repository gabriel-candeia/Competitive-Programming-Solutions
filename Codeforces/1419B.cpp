#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll x, t;

    cin >> t;
    while(t--){
        cin >> x;

        ll cnt = 0, pot = 0, acm=0;
        while(acm<=x){
            pot = 2*pot+1;
            acm+=pot*(pot+1)/2;
            cnt++;
        }
        cout << cnt-1 <<'\n';

    }

    return 0;
}

