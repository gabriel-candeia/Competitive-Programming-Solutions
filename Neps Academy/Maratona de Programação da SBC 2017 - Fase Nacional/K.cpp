#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e5+5)
using namespace std;

ll ft[maxn];
ll lsone(ll x){
    return x&(-x);
}

void update(ll r, ll v){
    if(r==0) return;
    for(;r<maxn;r+=lsone(r))
        ft[r]=max(v,ft[r]);
}

ll query(ll r){
    ll sum=0;
    for(;r;r-=lsone(r))
        sum=max(ft[r],sum);
    return sum;
}

int main(){
    ll n, x, y, w;
    map<pair<ll,ll>,ll> mp;
    map<ll,ll> compress;
    vector<array<ll,3>> arr;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y >> w;
        mp[{x,-y}]+=w;
    }

    for(auto p:mp){
        arr.push_back({p.first.first,-p.first.second,p.second});
        compress[-p.first.second];
    }

    int cnt=0;
    for(auto &p:compress){
        p.second = ++cnt;
    }
    
    for(auto p:arr){
        p[1] = compress[p[1]];
        update(p[1],query(p[1]-1)+p[2]);
    }

    cout << query(maxn-1) <<'\n';

    return 0;
}