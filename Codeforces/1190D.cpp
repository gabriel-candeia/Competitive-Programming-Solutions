#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

ll ft[maxn], freq[maxn];

ll lsone(ll x){
    return x&(-x);
}

void update(ll r, ll v){
    if(r==0) return;
    for(;r < maxn;r+=lsone(r))
        ft[r]+=v;
}

ll get(ll r){
    ll sum = 0;
    for(;r;r-=lsone(r))
        sum += ft[r];
    return sum;
}

ll get(ll l, ll r){
    if(l>r) return 0;
    return get(r)-get(l-1);
}

int main(){
    ll n;
    vector<pair<ll,ll>> pt;
    map<ll,ll> compress;

    cin >> n;
    pt.assign(n,{0,0});
    for(auto &p:pt){
        cin >> p.second >> p.first;
        compress[p.second];
    }

    ll cnt = 0;
    for(auto &p:compress){
        p.second = (++cnt);        
    }

    ll answ = 0;
    pt.push_back({0,0});
    sort(pt.begin(),pt.end());
    for(ll i=pt.size()-1;i>=0;i--){
        pt[i].second = compress[pt[i].second];
        if(i!=pt.size()-1 && pt[i].first!=pt[i+1].first){
            ll x, last=0;
            for(ll j=i+1;j<pt.size() && pt[j].first==pt[i+1].first;j++){
                update(pt[j].second,(freq[pt[j].second]++)==0);
                x = get(last+1,pt[j].second-1);
                answ -= (x*(x-1))/2 + x;
                last = pt[j].second;
            }
            x = get(maxn-1);
            answ += (x*(x-1))/2 + x;

            x = get(last+1,maxn-1);
            answ -= (x*(x-1))/2 + x;
        }
    }

    cout << answ <<'\n';

    return 0;
}