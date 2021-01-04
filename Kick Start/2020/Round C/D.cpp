#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define ll long long
using namespace std;

ll st[2][4*maxn+4], arr[maxn];

void build(ll p, ll l, ll r){
    if(l==r){
        st[0][p] = st[1][p] = arr[l];
        return;
    }
    ll med = l + (r-l)/2, sign = ((med-l+1)%2 ? -1 : 1);
    build(2*p,l,med); build(2*p+1,med+1,r);
    st[1][p] = st[1][2*p] + sign*st[1][2*p+1];
    st[0][p] = st[0][2*p] + sign*(st[0][2*p+1]+(med-l+1)*st[1][2*p+1]);
}

void update(ll p, ll l, ll r, ll i, ll x){
    if(l==r){
        st[0][p] = st[1][p] = x;
        return;
    }
    ll med = l + (r-l)/2, sign = ((med-l+1)%2 ? -1 : 1);
    if(i<=med)
        update(2*p,l,med,i,x);
    else
        update(2*p+1,med+1,r,i,x);
    st[1][p] = st[1][2*p] + sign*st[1][2*p+1];
    st[0][p] = st[0][2*p] + sign*(st[0][2*p+1]+(med-l+1)*st[1][2*p+1]);
}

pair<ll,ll> get(ll p, ll l, ll r, ll x, ll y){
    if(y<l || r<x)
        return {0,0};
    else if(x<=l && r<=y)
        return {st[0][p],st[1][p]};
    ll med = l+(r-l)/2, sign = ((max(min(y,med)-max(x,l)+1,0ll))%2 ? -1 : 1);
    pair<ll,ll> left = get(2*p,l,med,x,y), right = get(2*p+1,med+1,r,x,y);
    return {left.first + sign*(right.first + (max(min(y,med)-max(x,l)+1,0ll))*right.second),left.second+sign*right.second};   
}

int main(){
    ll t, n, q, x, y, caso=0;

    cin >> t;
    while(t--){
        cin >> n >> q;
        for(ll i=0;i<n;i++)
            cin >> arr[i];

        build(1,0,n-1);

        ll answ = 0;
        char op;
        
        for(ll i=0;i<q;i++){
            cin >> op >> x >> y; x; y;
            if(op == 'Q'){
                x--; y--;
                answ += get(1,0,n-1,x,y).first;
            }
            else{
                x--;
                update(1,0,n-1,x,y);
            }
        }

        cout << "Case #" << ++caso << ": " << answ <<'\n';

    }

    return 0;
}