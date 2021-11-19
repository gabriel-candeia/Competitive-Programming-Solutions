#include<bits/stdc++.h>
#define ll long long
#define maxn int(3e5+5)
using namespace std;

ll ft[maxn];

ll lsone(ll x){
    return (x&(-x));
}

void update(ll x, ll v){
    if(x<=0) return;
    for(;x;x-=lsone(x))
        ft[x]+=v;
}

ll get(ll x){
    ll sum=0;
    for(;x<maxn;x+=lsone(x))
        sum += ft[x];
    return sum;
}

int main(){
    ll n, q;
    vector<array<ll,3>> query;
    vector<ll> arr;
    map<ll,ll> mp;

    cin >> q >> n;
    mp[0];
    arr.assign(n+1,0ll);
    for(int i=0;i<q;i++){
        ll op, x, y;
        cin >> op >> x;
        if(op==1){
            cin >> y;
            arr[x]+=y;
            mp[arr[x]];
        }
        else{
            mp[x+1];
        }
        query.push_back({op,x,y});
    }

    int cnt = 0;
    for(auto &p:mp)
        p.second = ++cnt;
    arr.assign(n+1,0);
    for(auto q:query){
        ll op, x, y;
        op = q[0], x = q[1], y = q[2];
        if(op==1){
            update(mp[arr[x]],-1);
            arr[x]+=y;
            update(mp[arr[x]],+1);
        }
        else{
            cout << get(mp[x+1]) << "\n";
        }
    }
    

    return 0;
}