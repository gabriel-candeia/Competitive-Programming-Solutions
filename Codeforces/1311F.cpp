#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

ll ft[2][maxn];

int lsone(int x){
    return x&(-x);
}

void update(ll k, ll r, ll v){
    if(r==0) return;
    for(;r<maxn;r+=lsone(r))
        ft[k][r]+=v;
}

ll query(ll k, ll r){
    ll sum = 0;
    for(;r;r-=lsone(r))
        sum += ft[k][r];
    return sum;
}

int main(){

    ll n;
    vector<pair<ll,ll>> arr;
    map<ll,ll> mp;

    cin >> n;
    arr.assign(n,{0ll,0ll});
    for(int i=0;i<n;i++)
        cin >> arr[i].first;

    for(int i=0;i<n;i++){
        cin >> arr[i].second;
        mp[arr[i].second];
    }

    ll cnt = 0;
    for(auto &p:mp)
        p.second = ++cnt;

    for(int i=0;i<n;i++)
        arr[i].second = mp[arr[i].second];

    ll answ = 0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        answ += arr[i].first*query(0,arr[i].second) - query(1,arr[i].second);
        update(0,arr[i].second,1);
        update(1,arr[i].second,arr[i].first);
    }

    cout << answ <<'\n';

    return 0;
}