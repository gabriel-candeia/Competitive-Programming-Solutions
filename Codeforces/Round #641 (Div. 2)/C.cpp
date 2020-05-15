#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    ll n;
    vector<ll> a;

    cin >> n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    ll answ=a[0];
    for(int i=0;i<n;i++){
        answ = gcd(answ,a[i]);
    }

    for(int i=0;i<n;i++){
        a[i] /= answ;
    }
    vector<ll> gcdUpTo(n,0); 
    ll acm=a[0];
    gcdUpTo[0] = a[1];

    for(int i=1;i<n;i++){
        gcdUpTo[i] = acm;
        acm = gcd(acm,a[i]);
    }

    acm =  a[n-1];
    for(int i=1;i<n;i++){
        gcdUpTo[n-1-i] = gcd(acm,gcdUpTo[n-1-i]);
        acm = gcd(acm,a[n-1-i]);
    }

    for(int i=0;i<n;i++){
        answ *= gcdUpTo[i];
    }

    cout << answ << '\n'; 

    return 0;
}