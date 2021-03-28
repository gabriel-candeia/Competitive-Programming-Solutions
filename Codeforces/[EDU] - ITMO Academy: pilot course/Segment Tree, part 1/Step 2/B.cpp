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
    return st[p] = build(2*p,l,med)+build(2*p+1,med+1,r);
}

ll update(ll p, ll l, ll r, ll i){
    if(l==r)
        return st[p] = !st[p];
    ll med = l + (r-l)/2;
    if(i<=med)
        return st[p] = update(2*p,l,med,i)+st[2*p+1];
    return st[p] = st[2*p]+update(2*p+1,med+1,r,i);
}

ll find(ll p, ll l, ll r, ll k){
    if(l==r)
        return l;
    ll med = l + (r-l)/2;
    if(k <= st[2*p])
        return find(2*p,l,med,k);
    return find(2*p+1,med+1,r,k-st[2*p]);
}

int main(){
    ll n, m, op, x;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    build(1,0,n-1);
    for(int i=0;i<m;i++){
        cin >> op >> x;
        if(op==1)
            update(1,0,n-1,x);
        else
            cout << find(1,0,n-1,x+1) <<'\n';
    }
    return 0;
}