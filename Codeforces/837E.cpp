#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e6)
using namespace std;

vector<ll> primos, sieve;

ll gcd(ll a, ll b){
    return (b) ? gcd(b,a%b) : a;
}

ll f(ll a, ll b){
    if(b<=1)
        return  b;
    ll d = gcd(a,b), nxt=0; ll a_=a/d;
    a/=d; b/=d;
    for(auto p:primos){
        if(a%p==0)
            nxt = max(nxt,b-b%p);
        while(a%p==0)
            a/=p;
    }
    if(a!=1){
        nxt = max(nxt,b-b%a);
    }
    return f(a_,nxt)+(b-nxt);
}

int main(){
    sieve.assign(1e6,true);
    for(int i=2;i<maxn;i++){
        if(sieve[i]){
            primos.push_back(i);
            for(int j=i;j<maxn;j+=i)
                sieve[j] = false;
        }
    }
    ll x, y;
    cin >> x >> y;
    cout << f(x,y) <<'\n';

    return 0;
}