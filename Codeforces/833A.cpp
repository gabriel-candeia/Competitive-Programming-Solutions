#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const ll INF = int(1e6)+5;

ll cubic_root(ll x){
    ll l = 0, r = INF, med, answ;
    while(l<=r){
        med = l +(r-l)/2;
        if(med*med*med>=x){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    return answ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, a, b, x;

    cin >> n;
    while(n--){
        cin >> a >> b;

        x = cubic_root(a*b);
        if(1ll*x*x*x == 1ll*a*b && a%x==0 && b%x==0){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }

    }

    return 0;
}