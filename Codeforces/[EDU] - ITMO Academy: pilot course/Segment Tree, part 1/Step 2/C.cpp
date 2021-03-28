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
    return st[p] = max(build(2*p,l,med), build(2*p+1,med+1,r));
}

ll update(ll p, ll l, ll r, ll i, ll v){
    if(l==r)
        return st[p] = v;
    ll med = l + (r-l)/2;
    if(i<=med)
        return st[p] = max(update(2*p,l,med,i,v), st[2*p+1]);
    return st[p] = max(st[2*p], update(2*p+1,med+1,r,i,v));
}

ll find(ll p, ll l, ll r, ll x){
    if(l==r)
        return (st[p]>=x) ? l : -1;
    ll med = l + (r-l)/2;
    if(x<=st[2*p])
        return find(2*p,l,med,x);
    return find(2*p+1,med+1,r,x);
}

int main(){
    ll n, m, op, x, y;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    build(1,0,n-1);
    for(int i=0;i<m;i++){
        cin >> op;
        if(op==1){
            cin >> x >> y;
            update(1,0,n-1,x,y);
        }
        else{
            cin >> x;
            cout << find(1,0,n-1,x) <<'\n';
        }
    }
    return 0;
}