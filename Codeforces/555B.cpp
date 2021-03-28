#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m;
    vector<pair<ll,ll>> arr;
    vector<array<ll,3>> polls;
    multiset<array<ll,3>> st;
    vector<pair<ll,ll>> val;
    vector<ll> answ;

    cin >> n >> m;
    for(ll i=0, l, r;i<n;i++){
        cin >> l >> r;
        arr.push_back({l,r});
    }  

    for(ll i=1;i<n;i++)
        polls.push_back({arr[i].first-arr[i-1].second,arr[i].second-arr[i-1].first,i});

    val.assign(m,{0,0}); answ.assign(n,-1);
    ll cnt = 0;
    for(auto &x:val){
        cin >> x.first;
        x.second = ++cnt;
    }
    
    sort(val.begin(),val.end());
    sort(polls.begin(),polls.end());
    ll ptr = 0, poss = 0;
    for(auto x:val){
        for(;ptr<polls.size() && polls[ptr][1]<x.first;ptr++);

        for(;ptr<polls.size() && polls[ptr][0]<=x.first && x.first<=polls[ptr][1];ptr++)
            st.insert({polls[ptr][1],-polls[ptr][0],polls[ptr][2]});

        auto it = st.lower_bound({x.first,-x.first,0});

        if(it!=st.end()){
            //cout << (*it)[0] << " " << (*it)[1] << " " << " " <<S x.first << "\n";
            answ[(*it)[2]] = x.second;
            st.erase(it);
            poss++;
        }
    }

    if(poss==n-1){
        cout << "Yes\n";
        for(ll i=1;i<n;i++)
            cout << answ[i]<< " ";
        cout << '\n';
    }
    else{
        cout << "No\n";
    }

    return 0;
}