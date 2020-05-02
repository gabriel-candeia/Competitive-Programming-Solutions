#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll products(vector<ll>& k,ll t){
    ll num=0;

    for(int i=0;i<k.size();i++){
        num+=(t/k[i]);
    }

    return num;
}

ll min(ll a, ll b){
    return (a<b) ? a : b;
}

int main(){
    ll n, t, mn = 1e10;
    vector<ll> k;

    cin >> n >> t;
    k.assign(n,0);

    for(int i=0;i<n;i++){
        cin >> k[i];
        mn = min(k[i],mn);
    }

    ll l=0, r=1ll*t*mn, med, comp, answ=-1;
    while(l<=r){
        med = l + (r-l)/2;
        comp = products(k,med);
        if(comp>=t){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }

    cout << answ << '\n';

    return 0;
}