#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll pot[60], pref[60];

void precomp(){
    pot[1] = pot[2] = 2;
    pref[1] = 2, pref[2] = 6;
    for(int i=3;i<32;i++){
        pot[i] = 2*pot[i-1];
        pref[i] = i*pot[i] + pref[i-1];
    }
}

ll digitos(ll x){
    if(x==0) return 1;
    ll answ = 0;
    while(x){
        answ++;
        x/=2;
    }
    return answ;
}

ll piso(ll x){
    if(x==1) return 0;
    ll answ = 1;
    while(2*answ<=x){
        answ = 2*answ;
    }
    return answ;
}

ll calc(ll n){
    if(n==0) return 1;
    return pref[digitos(n)-1] + digitos(n)*(n-piso(n)+1);
}

ll bb(ll n){
    ll l = 0, r = 1e9, med, answ;
    while(l<=r){
        med = (l+r)/2;
        if(calc(med)<=n){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

ll teste(string s){
    ll answ = 0, acm = 0;
    for(auto c:s){
        if(c=='0')
            acm = 0;
        else
            acm = acm+1;
        answ = max(answ,acm);
    }
    return answ;
}

string binario(int x){
    string answ = "";
    while(x){
        answ.push_back(x%2+'0');
        x/=2;
    }
    reverse(answ.begin(),answ.end());
    return answ;
}

int main(){
    int t;
    precomp();
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        ll aux = bb(k), answ = 0;
        if(k!=1){    
            answ = teste(binario(piso(aux)-1)+binario(piso(aux)));
            string s = binario(aux), t = binario(aux+1);
            for(int i=0, rem = k-calc(aux);i<rem;i++)
                s+=t[i];
            answ = max(answ,teste(s));
        }
        cout << answ << "\n";
    }

    return 0;
}