#include<bits/stdc++.h>
#define maxn int(4e5+5)
#define ll long long
using namespace std;

const ll inf = 1e18;
ll st[maxn], arr[maxn];

ll build(ll p, ll l, ll r){
    if(l==r)
        return st[p] = arr[l];
    ll med = l + (r-l)/2;
    return st[p] = min(build(2*p,l,med), build(2*p+1,med+1,r));
}

ll update(ll p, ll l, ll r, ll i, ll v){
    if(l==r)
        return st[p] = v;
    ll med = l + (r-l)/2;
    if(i<=med)
        return st[p] = min(update(2*p,l,med,i,v), st[2*p+1]);
    return st[p] = min(st[2*p], update(2*p+1,med+1,r,i,v));
}

ll get(ll p, ll l, ll r, ll i, ll j){
    if(j < l || r < i)
        return inf;
    else if(i<=l && r<=j)
        return st[p];
    ll med = l + (r-l)/2;
    return min(get(2*p,l,med,i,j), get(2*p+1,med+1,r,i,j));
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
        else
            cout << get(1,0,n-1,x,y-1) <<'\n';
    }
    return 0;
}