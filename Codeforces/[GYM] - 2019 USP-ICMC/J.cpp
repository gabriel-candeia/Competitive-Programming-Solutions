#include <bits/stdc++.h>
#define ll long long
#define maxn int(1e5+5)
using namespace std;

bool prime(ll n){
    ll root = sqrt(n);
    if(n==1) return false;
    for(ll i = 2; i <= root; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

ll gt(ll n){
    for(ll i = n; ; i++)
        if(prime(i))
            return i;
    return -(1ll<<45);
}

ll ls(ll n){
    for(ll i = n; i >= 2; i--)
        if(prime(i))
            return i;
    return -(1ll<<45);;
}

int main(){
    ll n, v[maxn], mediana;
    cin >> n;
    
    for(ll i = 0; i < n; i++)
        cin >> v[i];
        
    sort(v, v+n);
    mediana = v[n/2];

    ll x = ls(mediana), y = gt(mediana), soma1=0, soma2=0;
    
    for(ll i = 0; i < n; i++){
        soma1+=abs(v[i]-x);
        soma2+=abs(v[i]-y);
    }

    cout << min(soma1, soma2) << "\n";
    return 0;
}