#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a,ll b){
    return (a<b) ? b : a;
}

int main(){
    ll n, d;
    vector<ll> h;
    set<pair<ll,ll>> s;
    vector<int> prev;

    cin >> n >> d;
    h.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> h[i];
    }

    s.insert({1e16,0});
    s.insert({-1e16,0});
    for(int i=0;i<n;i++){
        auto gt = s.lower_bound({h[i]+d,0});
        auto ls = s.upper_bound({h[i]-d,n});
        ls--;
        if((*gt).second>(*ls).second){
            s.insert({h[i],(*gt).second+1});
            s.erase(gt);
        }
        else{
            s.insert({h[i],(*ls).second+1});
            s.erase(ls);
        }
    }

    ll answ = 0;
    for(auto p:s){
        answ = max(answ,p.second);
    }

    cout << answ << '\n';
    
    return 0;
}