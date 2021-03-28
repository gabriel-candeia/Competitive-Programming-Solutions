#include<bits/stdc++.h>
#define maxn int(4e5+5)
#define ll long long
using namespace std;

ll st[maxn];

ll build(ll p, ll l, ll r){
    if(l==r)
        return st[p] = 0;
    ll med = l + (r-l)/2;
    return st[p] = build(2*p,l,med)+build(2*p+1,med+1,r);
}

ll update(ll p, ll l, ll r, ll i, ll v){
    if(l==r)
        return st[p] += v;
    ll med = l + (r-l)/2;
    if(i<=med)
        return st[p] = update(2*p,l,med,i,v)+st[2*p+1];
    return st[p] = st[2*p]+update(2*p+1,med+1,r,i,v);
}

ll get(ll p, ll l, ll r, ll i, ll j){
    if(j < l || r < i)
        return 0;
    else if(i<=l && r<=j)
        return st[p];
    ll med = l + (r-l)/2;
    return get(2*p,l,med,i,j)+get(2*p+1,med+1,r,i,j);
}

int main(){
    ll n, m, op, x, y, v;
    cin >> n >> m;

    build(1,0,n-1);
    for(int i=0;i<m;i++){
        cin >> op;
        if(op==1){
            cin >> x >> y >> v;
            update(1,0,n-1,x,v);
            if(y<n) update(1,0,n-1,y,-v);
        }
        else{
            cin >> x;
            cout << get(1,0,n-1,0,x) << '\n';
        }
    }
    return 0;
}