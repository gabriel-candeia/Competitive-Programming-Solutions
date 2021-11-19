#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int n, m;
    ll soma = 0;
    set<ll> arr, comp;
    cin >>n ;
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        soma+=x;
        arr.insert(x);
    }

    for(auto x:arr) comp.insert(soma-x);

    cin >> m;
    while(m--){
        ll x, y;
        cin >> x >> y;
        ll answ =  max(x-*(arr.begin()),0ll) + max(y-soma+*(arr.begin()),0ll);    

        auto it = arr.upper_bound(x);
        if(it!=arr.end()){
            answ = min(answ,max(x-(*it),0ll) + max(y-soma+(*it),0ll));
        }

        if(it!=arr.begin()){
            it--;
            answ = min(answ,max(x-(*it),0ll) + max(y-soma+(*it),0ll));
        }

        it = comp.upper_bound(y);
        if(it!=comp.end()){
            answ = min(answ,max(x-soma+(*it),0ll) + max(y-(*it),0ll));
        }

        cout << answ <<"\n";
    }

    return 0;
}