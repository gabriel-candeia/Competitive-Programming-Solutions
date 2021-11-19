#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;

ll binpow(ll x, ll y){
    ll answ = 1;
    while(y){
        if(y&1)
            answ = (answ*x)%mod;
        x = (x*x)%mod;
        y/=2;
    }
    return answ;
}

int dist(int x){
    int answ = 0;
    while(x){
        x/=2;
        answ++;
    }
    return answ;
}

int up(int x, int k){
    while(k){
        x/=2;
        k--;
    }
    return x;
}

int main(){
    ll n, d;
    cin >> n >> d;
    ll answ = 0, ub = (binpow(2,n)-1+mod)%mod;

    if(d>2*(n-1)){
        answ = 0;
    }
    else if(d%2){
        for(int k=min(d-1,n);k>d/2;k--){
            ll left = (ub-binpow(2,k)+mod+1)%mod, right = binpow(2,d-k-1);
            answ = (answ + (left*right)%mod)%mod;
            if(k!=d/2)
                answ = (answ + (left*right)%mod)%mod;
        }
    }
    else{
        for(int k=min(d-1,n);k>=d/2;k--){
            ll left = (ub-binpow(2,k)+mod+1)%mod, right = binpow(2,d-k-1);
            answ = (answ + (left*right)%mod)%mod;
            if(k!=d/2)
                answ = (answ + (left*right)%mod)%mod;
        }
    }
    if(d<n){
        answ = (answ + ((ub-binpow(2,d)+mod+1))%mod)%mod;
        answ = (answ + ((ub-binpow(2,d)+mod+1))%mod)%mod;
    }

/*
    ll teste = 0;
    for(int i=1;i<(1<<n);i++){
        for(int j=1;j<(1<<n);j++){
            int u = i, v = j;
            if(dist(v)>dist(u)){
                swap(u,v);
            }
            u = up(u,dist(u)-dist(v));

            while(u!=v){
                u/=2, v/=2;
            }

            if(dist(i)+dist(j)-2*dist(u)==d){
                teste++;
                cout << i << " " << j << "\n";
            }
        }
    }
*/
  
    cout << answ <<"\n";

    return 0;
}