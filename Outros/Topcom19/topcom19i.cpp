#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

ll acm(ll x){
    ll acm = 0, pot = 5;
    while(pot<=x){
        acm += x/pot;
        pot = pot*5;
    }
    return acm;
}

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        ll l = 0, r = 1e10, med, answ = -1;
        while(l<=r){
            med = l + (r-l)/2;
            if(acm(med)>=n){
                answ = med;
                r = med-1;
            }
            else{
                l = med+1;
            }
        }

        cout << answ <<"\n";
    }

    return 0;
}
