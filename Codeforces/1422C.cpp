#include<bits/stdc++.h>
#define ll long long
using namespace std;


const ll mod = 1e9+7;
ll binpow(ll x, ll y){
    ll ret = 1;
    while(y){
        if(y%2)
            ret=(ret*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return ret;
}

int main(){
    string s;
    ll n, qtd, answ=0, acm=0;

    cin >> s;
    n = s.size();
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++){
        qtd = ((n-i-1)*(n-i-2)/2 +(n-i-1))%mod;
        //cout << qtd*(s[i]-'0') << " " << acm*(s[i]-'0') <<'\n';
        answ = (answ+(qtd*(s[i]-'0')*binpow(10,i))%mod)%mod;
        answ = (answ+(acm*(s[i]-'0'))%mod)%mod;
        acm = (acm+(i+1)*binpow(10,i))%mod;
    }

    cout << answ <<'\n';
    return 0;
}