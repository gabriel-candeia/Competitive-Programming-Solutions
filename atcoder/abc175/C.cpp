#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll modulo(ll x){
    return (x>0) ? x : -x;
}

int main(){
    ll x, k, d, q, answ;

    cin >> x >> k >> d;

    q = modulo(x)/d;

    if(q>=k){
        answ = modulo(x) - k*d;
    }
    else if((k-q)%2){
        answ = d-modulo(x)%d;
    }
    else{
        answ = modulo(x)%d;   
    }

    cout << answ << '\n';

    return 0;
}