#include<bits/stdc++.h>
using namespace std;
#define maxn int(3e6+5)
#define ll __int128

ll dp[maxn], aux[maxn];
ll bb(ll x){
    ll l = 1, r = x, med, answ = 1;
    while(l<=r){
        med = l + (r-l)/2;
        if(med*med<=x){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

void precomp(ll x){
    ll raiz = bb(x);
    dp[1] = aux[1] = 1;
    for(ll i=2;i*i<=raiz;i++){
        ll raiz2 = bb(i);
        dp[i] = aux[raiz2];
        aux[i] = dp[i] + aux[i-1];
    }
}

ll solve(ll x){
    ll raiz = bb(x), answ = 0;
    for(ll i=1;i*i<=raiz;i++){
        answ += (raiz-i*i+1)*dp[i];
    }
    return answ;
}

int main(){ 
    int t;
    cin >> t;
    precomp(9e18+10);
    while(t--){
        long long x;
        cin >> x;
        cout << ((unsigned long long) solve(x)) <<"\n";
    }

    return 0;
}