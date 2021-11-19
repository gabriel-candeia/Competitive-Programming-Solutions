#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

ll binpow(ll x, ll y){
    if(y<0) return 0;
    ll answ = 1;
    for(;y;y>>=1, x = (x*x)%mod){
        if(y&1)
            answ = (answ*x)%mod;
    }
    return answ;
}

int main(){
    int n;
    string s;

    cin >> n >> s;

    map<char,ll> freq;
    ll fx=0, fc=0, fxx=0, fxc=0, fbx=0, fbc=0, answ=0;
    for(auto c:s) freq[c]++;

    for(int i=n-1;i>=0;i--){
        if(s[i]=='a'){
            answ = (answ+(fbc*binpow(3,freq['?']))%mod)%mod;
            answ = (answ+(fbx*binpow(3,freq['?']-1))%mod)%mod;
            answ = (answ+(fxc*binpow(3,freq['?']-1))%mod)%mod;
            answ = (answ+(fxx*binpow(3,freq['?']-2))%mod)%mod;
        }
        if(s[i]=='b'){
            fbc = (fbc+fc)%mod;
            fbx = (fbx+fx)%mod;
        }
        if(s[i]=='c'){
            fc = (fc+1)%mod;
        }
        if(s[i]=='?'){
            answ = (answ+(fbc*binpow(3,freq['?']-1))%mod)%mod;
            answ = (answ+(fbx*binpow(3,freq['?']-2))%mod)%mod;
            answ = (answ+(fxc*binpow(3,freq['?']-2))%mod)%mod;
            answ = (answ+(fxx*binpow(3,freq['?']-3))%mod)%mod;

            fxc = (fxc+fc)%mod;
            fxx = (fxx+fx)%mod;

            fx = (fx+1)%mod;
        }
    }

    cout << answ <<'\n';

    return 0;   
}