#include<bits/stdc++.h>
#define maxn int(4e5+5)
#define ll long long
using namespace std;

ll st[maxn], arr[maxn];

ll build(ll p, ll l, ll r){
    if(l==r)
        return st[p] = arr[l];
    ll med = l + (r-l)/2;
    return st[p] = build(2*p,l,med)+((med-l+1)%2==1 ? -1 : 1)*build(2*p+1,med+1,r);
}

ll update(ll p, ll l, ll r, ll i, ll v){
    if(l==r)
        return st[p] = v;
    ll med = l + (r-l)/2;
    if(i<=med)
        return st[p] = update(2*p,l,med,i,v)+((med-l+1)%2==1 ? -1 : 1)*st[2*p+1];
    return st[p] = st[2*p]+((med-l+1)%2==1 ? -1 : 1)*update(2*p+1,med+1,r,i,v);
}

ll get(ll p, ll l, ll r, ll i, ll j){
    if(j < l || r < i)
        return 0;
    else if(i<=l && r<=j)
        return st[p];
    ll med = l + (r-l)/2;
    if(i<=med)
        return get(2*p,l,med,i,j)+((med-max(i,l)+1)%2==1 ? -1 : 1)*get(2*p+1,med+1,r,i,j);
    return get(2*p+1,med+1,r,i,j);
}

int main(){
    ll n, m, op, x, y;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    build(1,0,n-1);
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> op >> x >> y;
        if(op==0)
            update(1,0,n-1,x-1,y);
        else
            cout << get(1,0,n-1,x-1,y-1) <<'\n';
    }

    return 0;
}