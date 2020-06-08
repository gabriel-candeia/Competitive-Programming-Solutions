#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll binpow(ll a, ll b, ll mod){
    if(b==0){
        return 1ll;
    }
    ll temp = binpow(a,b/2,mod);
    temp = (temp*temp)%mod;
    if(b%2){
        return (temp*a)%mod;
    }
    return temp;
}

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    map<pair<ll,ll>,ll> cnt;
    ll n, a, b, zero=0, temp;

    const ll mod = 1000000007;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        if(a==0 && b==0){
            zero++;
        }
        else if(a==0){
            cnt[{1,0}]++;
        }
        else if(b==0){
            cnt[{0,1}]++;
        }
        else{
            temp = gcd(a,b);
            if(temp<0){ temp*=-1;}
            a /= temp;
            b /= temp;

            if(b<0){ b*=-1; a*=-1;}
            cnt[{a,b}]++;
 
        }
    }

    ll answ = 1ll;
    answ = (answ + (binpow(2,cnt[{0,1}],mod)-1) + (binpow(2,cnt[{1,0}],mod)-1))%mod;
    cnt[{0,1}] = 0;
    cnt[{1,0}] = 0;

    for(auto p:cnt){    
        ll last = answ%mod;
        a = p.first.first; b = p.first.second;
        
        if(a<0){
            a*=-1ll;
            b*=-1ll;
        }       
        
        if(p.second){
            answ = (last + (1ll*last*(binpow(2ll,p.second,mod)+mod-1ll))%mod)%mod;
            if(cnt[{-1ll*b,a}]){
                answ = (answ + (1ll*last*(binpow(2ll,cnt[{-1ll*b,a}],mod)+mod-1ll))%mod)%mod;
            }
        }

        cnt[{-b,a}] = 0;
    }
    cout << (answ+zero-1+mod)%mod << '\n';

    return 0;
}