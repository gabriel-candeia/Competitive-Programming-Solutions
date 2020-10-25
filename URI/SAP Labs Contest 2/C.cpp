#include<bits/stdc++.h>
#define ll int
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define maxn int(4e6+5)
using namespace std;

ll n, m, x, y;
vector<ll> s, small, big;

ll st[maxn][2], lazy[maxn][2];

void push(ll k, ll p, ll l, ll r){
    st[p][k] = min(st[p][k],lazy[p][k]);
    if(l!=r){
        lazy[2*p][k] = min(lazy[2*p][k],lazy[p][k]);
        lazy[2*p+1][k] = min(lazy[2*p+1][k],lazy[p][k]);
    }
    lazy[p][k] = maxn;
}

ll build(ll k, ll p, ll l, ll r){
    lazy[p][k] = maxn;
    if(l==r)
        return st[p][k] = maxn;
    ll mid = l + (r-l)/2;
    return st[p][k] = min(build(k,2*p,l,mid),build(k,2*p+1,mid+1,r));
}

ll update(ll k, ll p, ll l, ll r, ll i, ll j, ll v=maxn){
    push(k,p,l,r);
    if(j<l || r<i)
        return maxn;
    if(i<=l && r<=j){
        lazy[p][k] = min(lazy[p][k],v);
        push(k,p,l,r);
        return st[p][k];
    }
    ll mid = l + (r-l)/2;
    return st[p][k] = min(update(k,2*p,l,mid,i,j,v),update(k,2*p+1,mid+1,r,i,j,v));
}

ll get(ll k, ll p, ll l, ll r, ll i){
    push(k,p,l,r);
    if(i<l || r<i)
        return maxn;
    if(l==r)
        return st[p][k];
    ll mid = l + (r-l)/2;    
    return st[p][k] = min(get(k,2*p,l,mid,i),get(k,2*p+1,mid+1,r,i));
}

int main(){
    fastio();
    cin >> n >> m;
    s.assign(n+2,0);
    small.assign(n+2,0);
    big.assign(n+2,0);

    s[0] = 1;
    for(ll i=1;i<=n;i++)
        cin >> s[i];
    s[n+1] = m;
    cin >> x >> y;
    n=s.size();
    
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

    update(0,1,0,n-1,0,0,0);
    update(1,1,0,n-1,0,0,0);
    for(ll i=0;i<n;i++){
        ll v0, v1;
        v0 = get(0,1,0,n-1,i);
        v1 = get(1,1,0,n-1,i);
        
        update(1,1,0,n-1,i+1,big[i],v0+1);
        update(0,1,0,n-1,i+1,small[i],min(v0,v1)+1);
    }
    ll answ = min(get(0,1,0,n-1,n-1),get(1,1,0,n-1,n-1));
    if(answ>=maxn)
        answ = -1;
    cout << answ << '\n';

    return 0;
}