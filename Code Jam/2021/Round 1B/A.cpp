#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll grau = 1000000000;
vector<ll> t;
bool testa(vector<ll> p, ll rotacao){
    vector<ll> d = {(ll)1,(ll)12,(ll)720}, lim = {12,60,60}, d2 = {(ll)3600e9,(ll)60e9,(ll)1e9};
    t = vector<ll>(p.begin(),p.end());
    ll mn = 0;
    for(int i=0;i<3;i++){
        t[i]/=d[i];   
        t[i] -= rotacao;
        if(t[i]<0) t[i] + grau*12*3600;
    }
    vector<ll> resto = {t[1],t[2],0};
    for(int i=0;i<3;i++){
        if(resto[i]!=t[i]%d2[i])
            return false;
        t[i] = t[i]/d2[i];
        if(t[i]>=lim[i])
            return false;
    }
    t.push_back(0);
    return true;
}

int main(){
    ll a, b, c, caso, casos=0;

    cin >> caso;
    while(caso--){
        cin >> a >> b >> c;
        vector<ll> p = {a,b,c};
        bool poss = false;
        for(int i=0;i<12*3600 && !poss;i++){
            if(testa(p,i*grau)){
                poss = true;
                break;
            }
            for(;next_permutation(p.begin(),p.end());){
                if(testa(p,i*grau)){
                    poss = true;
                    break;
                }
            }
        }
        if(poss){
            cout <<"Case #" << ++casos <<": "<< t[0] << " " << t[1] << " " << t[2] << " " << t[3] << '\n';
        }
        else{
            cout << "no\n";
        }
    }
    return 0;
}