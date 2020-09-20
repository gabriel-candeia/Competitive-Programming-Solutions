#include<bits/stdc++.h>
#define maxn int(4e5+5)
#define ll long long
using namespace std;
//using fenwick tree

ll ft[maxn], n, cnt, d, f, w;
vector<tuple<ll,ll,ll>> arr;
map<ll,ll> compress;

ll lsOne(ll x){
    return x&(-x);
}

void update(ll l, ll v){
    if(l==0) return;
    for(;l<maxn;l+=lsOne(l))
        ft[l] = max(ft[l],v);
}

ll query(ll r){
    ll answ = 0;
    for(;r;r-=lsOne(r))
        answ = max(ft[r],answ);
    return answ;
}

int main(){
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> d >> f >> w;
        compress[d];
        compress[f];
        arr.push_back({f,d,w});
    }

    cnt = 0;
    for(auto &p:compress){
        p.second = ++cnt;
    }

    sort(arr.begin(),arr.end());
    for(ll i=0;i<n;i++){
        tie(f,d,w) = arr[i];
        update(compress[f],query(compress[d]-1)+w);
    }

    ll answ=0;
    for(ll i=0;i<maxn;i++)
        answ = max(answ,ft[i]);
    cout << answ <<'\n';

    return 0;
}