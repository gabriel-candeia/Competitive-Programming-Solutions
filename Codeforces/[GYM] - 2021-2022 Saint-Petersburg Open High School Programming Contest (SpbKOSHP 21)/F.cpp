#include<bits/stdc++.h>
#define ld long double
#define ll long long
using namespace std;

int n;
vector<ll> v, s;

pair<ll,ll> tempo(ll i, ll j, ll k){
    ll a = (s[j]-s[i])*(k-i) - (s[k]-s[i])*(j-i), b = (v[k]-v[i])*(j-i)-(v[j]-v[i])*(k-i);
    if(a==0){
        b = 1;
    }
    if(b!=0 && a!=0){
        ll d = __gcd(abs(a),abs(b));
        a/=d, b/=d;
        if(b<0) a = -a, b = -b;
    }
    return {a,b};
}

int main(){

    cin >> n;
    v.assign(n+1,0);
    s.assign(n+1,0);

    for(int i=1;i<=n;i++)
        cin >> s[i] >> v[i];


    int answ = (n<=2) ? n : 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            map<pair<ll,ll>,int> mp;
            int acm = 2;
            for(int k=j+1;k<=n;k++){
                auto p = tempo(i,j,k);
                if(p.second==0){
                    acm+=(p.first==0);
                }
                else if(p.first>=0){
                    mp[p]++;
                }
            }
            answ = max(answ,acm);
            for(auto &p:mp){
                answ = max(answ,p.second+acm);
                p.second = 0;
            }
        }
    }

    cout << answ <<"\n";
    return 0;
}