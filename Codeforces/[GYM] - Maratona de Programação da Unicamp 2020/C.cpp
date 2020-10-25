#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 18014398241046527;
const ll p = 11;

int main(){
    map<ll,ll> points;
    string s;
    ll n, d, x;

    cin >> n >> d;
    for(ll i=0;i<n;i++){
        cin >> s >> x;
        ll hash = 0, pot = 1;
        for(ll j=s.size()-2;j>=0;j--){
            hash = (hash + ((s[j]-'A'+1)*pot)%mod)%mod;
            pot=(p*pot)%mod;
        }
        points[hash] = x;
    }
    cin >> s;
    ll answ=0;
    for(ll i=0;i<s.size();i++){
        if(s[i]!='X')
            continue;
        ll ptr = i-1, acm=d, hash=0, pot=1;
        while(ptr>=0 && s[ptr]!='X'){
            hash = (hash+((s[ptr]-'A'+1)*pot)%mod)%mod;
            acm = max(acm,points[hash]);
            pot=(p*pot)%mod;
            ptr--;
        }
        answ += acm;
    }

    cout << answ <<'\n';
    return 0;
}