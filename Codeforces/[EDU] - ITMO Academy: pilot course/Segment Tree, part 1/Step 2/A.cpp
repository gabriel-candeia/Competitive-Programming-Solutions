#include<bits/stdc++.h>
#define maxn int(4e5+5)
#define ll long long
using namespace std;

struct node{
    ll sum, preff, suff, answ;
    node(){

    }

    node(ll x){
        sum = x;
        suff = preff = answ = max(x,0ll);
    }
};

const ll inf = -1e18;
node st[maxn];
ll arr[maxn];

node combine(node left, node right){
    node x;
    x.sum = left.sum+right.sum;
    x.preff = max(left.preff,left.sum+right.preff);
    x.suff = max(right.suff,right.sum+left.suff);
    x.answ = max({left.answ,right.answ,left.suff+right.preff});
    return x;
}

node build(ll p, ll l, ll r){
    if(l==r)
        return st[p] = node(arr[l]);
    ll med = l + (r-l)/2;
    return st[p] = combine(build(2*p,l,med), build(2*p+1,med+1,r));
}

node update(ll p, ll l, ll r, ll i, ll v){
    if(l==r)
        return st[p] = node(v);
    ll med = l + (r-l)/2;
    if(i<=med)
        return st[p] = combine(update(2*p,l,med,i,v), st[2*p+1]);
    return st[p] = combine(st[2*p], update(2*p+1,med+1,r,i,v));
}

node get(ll p, ll l, ll r, ll i, ll j){
    if(j < l || r < i)
        return node(inf);
    else if(i<=l && r<=j)
        return st[p];
    ll med = l + (r-l)/2;
    return combine(get(2*p,l,med,i,j), get(2*p+1,med+1,r,i,j));
}

int main(){
    ll n, m, x, y;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    build(1,0,n-1);
    cout << st[1].answ <<'\n';
    for(int i=0;i<m;i++){
        cin >> x >> y;
        update(1,0,n-1,x,y);
        cout << st[1].answ <<'\n';
    }
    return 0;
}