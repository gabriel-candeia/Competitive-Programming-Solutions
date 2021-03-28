#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define maxn int(4e6+24+5)
using namespace std;


ll st[maxn], lazy[maxn], def[maxn];
vector<pair<ll,ll>> atk;

ll build(ll p, ll l, ll r){
    if(l==r)
        return st[p] = -def[l];
    int med = l + (r-l)/2;
    return st[p] = max(build(2*p,l,med),build(2*p+1,med+1,r));
}

void push(ll p, ll l, ll r){
    st[p] += lazy[p];
    if(l!=r){
        lazy[2*p] += lazy[p];
        lazy[2*p+1] += lazy[p];
    }
    lazy[p] = 0;
}

ll update(ll p, ll l, ll r, ll i, ll j, ll v){
    push(p,l,r);
    if(j<l || r<i)
        return -1e18;
    if(i<=l && r<=j){
        lazy[p] += v;
        push(p,l,r);
        return st[p];
    }
    ll med = l + (r-l)/2, answ = max(update(2*p,l,med,i,j,v),update(2*p+1,med+1,r,i,j,v));
    st[p] = max(st[2*p],st[2*p+1]);
    return answ;
}

int main(){
    fastio();
    ll  p, x, y, n, m;
    
    cin >> n >> m >> p;

    atk.assign(n,{0,0});
    for(auto &p:atk)
        cin >> p.first >> p.second;

    for(int i=0;i<maxn;i++)
        def[i]  = 1e18;

    for(int i=0;i<m;i++){
        cin >> x >> y;
        def[x] = min(def[x],y);
    }
    
    vector<array<ll,3>> monsters(p);
    for(auto &p:monsters){
        for(int j=0;j<3;j++)
            cin >> p[j];
    }

    build(1,1,int(1e6));
    ll answ = -1e18;
    sort(atk.begin(),atk.end());
    sort(monsters.begin(),monsters.end());
    for(int i=0, j=0;i<n;i++){
        for(;j<p && monsters[j][0]<atk[i].first;j++)
            update(1,1,int(1e6),monsters[j][1]+1,int(1e6),monsters[j][2]);
        answ = max(answ,-atk[i].second+st[1]);
    }

    cout << answ << '\n';

    return 0;
}