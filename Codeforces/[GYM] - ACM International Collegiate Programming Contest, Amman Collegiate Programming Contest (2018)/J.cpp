#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

ll aux(ll x){
    ll answ = 0, pot = 1;
    while(pot<x){
        answ |= pot;
        pot = (pot<<1);
    }
    return answ;
}

int main(){
    fastio();
    int t;

    cin >> t;
    while(t--){
        ll a, b, c;

        cin >> a >> b >> c;
        ll answ = 0;
        if(a<=c)
            answ = min(b-a+1,aux(c));
        
        cout << answ <<"\n";
    }

    return 0;
}