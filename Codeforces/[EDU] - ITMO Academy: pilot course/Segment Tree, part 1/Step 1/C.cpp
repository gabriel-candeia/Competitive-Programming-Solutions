#include<bits/stdc++.h>
#define maxn int(4e5+5)
#define ll long long
using namespace std;

const ll inf = 1e18;
pair<ll,ll> st[maxn];
ll arr[maxn];

pair<ll,ll> combine(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first < b.first)
        return a;
    else if(b.first < a.first)
        return b;
    else    
        return {a.first, a.second+b.second};
}

pair<ll,ll> build(ll p, ll l, ll r){
    if(l==r)
        return st[p] = {arr[l], 1};
    ll med = l + (r-l)/2;
    return st[p] = combine(build(2*p,l,med), build(2*p+1,med+1,r));
}

pair<ll,ll> update(ll p, ll l, ll r, ll i, ll v){
    if(l==r)
        return st[p] = {v, 1};
    ll med = l + (r-l)/2;
    if(i<=med)
        return st[p] = combine(update(2*p,l,med,i,v), st[2*p+1]);
    return st[p] = combine(st[2*p], update(2*p+1,med+1,r,i,v));
}

pair<ll,ll> get(ll p, ll l, ll r, ll i, ll j){
    if(j < l || r < i)
        return {inf, 0};
    else if(i<=l && r<=j)
        return st[p];
    ll med = l + (r-l)/2;
    return combine(get(2*p,l,med,i,j), get(2*p+1,med+1,r,i,j));
}

int main(){
    ll n, m, op, x, y;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    build(1,0,n-1);
    for(int i=0;i<m;i++){
        cin >> op >> x >> y;
        if(op==1)
            update(1,0,n-1,x,y);
        else{
            auto answ = get(1,0,n-1,x,y-1);
            cout << answ.first << " " << answ.second <<'\n';
        }
    }
    return 0;
}