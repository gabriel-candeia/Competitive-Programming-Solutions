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

ll find(ll p, ll l, ll r, ll i, ll x){
    if(l==r)
        return (st[p]>=x) ? l : -1;
    ll med = l + (r-l)/2, answ=-1;
    if((i <= l || i<=med) && x<=st[2*p])
        answ = find(2*p,l,med,i,x);
    if(answ==-1 && x<=st[2*p+1])
        answ = find(2*p+1,med+1,r,i,x);
    return answ;
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
            cout << find(1,0,n-1,y,x) <<'\n';
    }
    return 0;
}