#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, answ = 1e18;

    cin >> n;
    for(ll i=0;(i-1)*(i-1)*(i-1)<=n;i++){
        ll l = 0, r = i, med;
        while(l<=r){
            med = l + (r-l)/2;
            ll a = i*i*i, b = med*med*med, c = i*i*med, d = med*med*i;
            ll cmp = n-a-b;
            if(cmp<=c+d){
                answ = min(answ,a+b+c+d);
                r = med-1;
            }
            else{
                l = med+1;
            }
        }
    }

    cout << answ <<"\n";

    return 0;
}