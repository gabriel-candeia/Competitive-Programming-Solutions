#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x;

ll isOK (ll n){
    ll a;
    if(n%2){
        a = 41+(-135+98*n);
    }
    else{
        a = -41+(-135+98*n);
    }
    a/=4;
    return (a<=x);
}

int main(){
    cin >> x;   

    ll l=1, r=1e16+8, answ=-1, med; 
    
    while(l<=r){
        med = l+(r-l)/2;
        if(isOK(med)){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    
    cout << answ << '\n';

    return 0;
}