#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const ll inf = 101112131415161718;

ll digitos(ll i){
    int answ = 0;
    for(;i;i/=10,answ++);
    return answ;
}

ll pot(ll x,ll y){
    ll acm = 1;
    for(int i=0;i<y;i++)
        acm = acm*x;
    return acm;
}


ll teste(string &s, ll n, ll k, ll i){    
    ll acm = 0;
    for(;acm<=n;i++)
        acm = acm*pot(10,digitos(i))+(i);
    return acm;
}

ll func(string &s, ll n, ll k){
    ll i = 0;
    for(int j=0;j<k;j++)
        i = i*10+(s[j]-'0');

    ll answ = inf;
    for(int j=0;j<10;j++)
        answ = min(teste(s,n,k,i*10+j),answ);
        
    return answ;
}

int main(){
    int t, caso=0;

    cin >> t;
    while(t--){
        ll n, answ= inf ;
        string s;
        cin >> n; s = to_string(n);
        for(int i=0;i<s.size()-1;i++)
            answ = min(answ,func(s,n,i));

        ll x = s.size()+1;
        for(int j=1;j<x;j++)
            if(x%j==0)
                answ = min(answ,teste(s,n,0,pot(10,j-1)));

        cout << "Case #" << ++caso << ": " << answ <<'\n';

    }
    return 0;
}