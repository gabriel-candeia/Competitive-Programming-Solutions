#include<bits/stdc++.h>
#define ll int
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define maxn int(4e6+10)
#define maxm int(1e6+10)
using namespace std;

ll n, m, x, y, k, v;
ll s[maxm], small[maxm], big[maxm], st[maxn][2];

void build(ll k, ll p, ll l, ll r){
    if(l==r){
        st[p][k] = maxn;
        return;
    }
    ll mid = l + (r-l)/2;
    build(k,2*p,l,mid);
    build(k,2*p+1,mid+1,r);
    st[p][k] = min(st[2*p][k],st[2*p+1][k]);
}

void update(ll k, ll p, ll l, ll r, ll i, ll v){
    if(l==r){
        st[p][k] = min(st[p][k],v);
        return;
    }
    ll mid = l + (r-l)/2;
    if(i<=mid)
        update(k,2*p,l,mid,i,v);
    else
        update(k,2*p+1,mid+1,r,i,v);
    st[p][k] = min(st[2*p][k],st[2*p+1][k]);
}

ll get(ll k, ll p, ll l, ll r, ll i, ll j){
    if(j<l || r<i)
        return maxn;
    if(i<=l && r<=j)
        return st[p][k];
    ll mid = l + (r-l)/2;    
    return st[p][k] = min(get(k,2*p,l,mid,i,j),get(k,2*p+1,mid+1,r,i,j));
}


int main(){
    fastio();
    cin >> n >> m;

    s[0] = 1;
    for(ll i=1;i<=n;i++)
        cin >> s[i];
    s[n+1] = m;
    cin >> x >> y;
    n+=2;
    
    int ptr = 0;
    for(int i=0;i<n;i++){
        while(ptr<n && s[ptr]-s[i]<=x)
            ptr++;
        small[i] = ptr-1;
    }

    ptr = 0;
    for(int i=0;i<n;i++){
        while(ptr<n && s[ptr]-s[i]<=y)
            ptr++;
        big[i] = ptr-1;
    }

    build(0,1,0,n-1);
    build(1,1,0,n-1);

    update(0,1,0,n-1,n-1,0);
    update(1,1,0,n-1,n-1,0);
    for(ll i=n-1;i>=0;i--){
        ll v0, v1;
        v0 = get(0,1,0,n-1,i+1,small[i]);
        v1 = get(1,1,0,n-1,i+1,big[i]);
        update(1,1,0,n-1,i,v0+1);
        update(0,1,0,n-1,i,min(v0,v1)+1);
    }
    ll answ = min(get(0,1,0,n-1,0,0),get(1,1,0,n-1,0,0));
    if(answ>=maxn)
        answ = -1;
    cout << answ << '\n';

    return 0;
}