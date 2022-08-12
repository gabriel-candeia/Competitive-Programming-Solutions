#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y/=2){
        if(y&1){
            answ = (x*answ)%mod;
        }
        x = (x*x)%mod;
    }
    return answ;
}

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, total;
        string s;

        cin >> n >> s;
        total = n/2 + n%2;
        ll answ = 0;
        for(int i=0;i<n/2;i++){
            answ = (answ + (s[i]-'A')*(binpow(26,total-i-1)))%mod;
        }

        if(n%2){
            string t = s.substr(0,n/2), aux;
            reverse(t.begin(),t.end());
            t = s.substr(0,n/2)+s[n/2]+t;
            answ = (answ + (s[n/2]-'A') + (t<=s))%mod;
        }
        else{
            string t = s.substr(0,n/2), aux;
            reverse(t.begin(),t.end());
            t = s.substr(0,n/2)+t;
            //cout << t << "\n";
            answ = (answ + (t<=s))%mod;
        }
        //cout << n <<"\n";
        cout << answ <<"\n";
    }

    return 0;
}

