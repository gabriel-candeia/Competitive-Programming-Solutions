#include<bits/stdc++.h>
#define maxn int(3e6+1)
#define ll long long
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

const ll inf = 1e18;
ll st[4*maxn];

void update(ll p, ll l, ll r, ll i, ll v){
    if(l==r){
        st[p] = v;
        return;
    }
    ll med = l + (r-l)/2;
    if(i<=med)
        update(2*p,l,med,i,v);
    else
        update(2*p+1,med+1,r,i,v);
    st[p] = max(st[2*p],st[2*p+1]);
}

ll get(ll p, ll l, ll r, ll i, ll j){
    if(j<l || r<i)
        return -inf;
    if(i<=l && r<=j)
        return st[p];
    ll med = l+ (r-l)/2;
    return max(get(2*p,l,med,i,j),get(2*p+1,med+1,r,i,j));
}

int main(){
    fastio();
    ll n, m;
    map<ll,ll> compress;
    vector<array<ll,3>> queries, traps;
    vector<pair<ll,ll>> p, q;
    vector<bool> answ;

    cin >> n >> m;
    answ.assign(m,true);
    for(ll i=0, x, y, r;i<n;i++){
        cin >> x >> y >> r;
        traps.push_back({y, x, r});
        compress[x];
    }

    p.assign(m,{0,0}), q.assign(m,{0,0}), queries.assign(m,{0,0,0});
    for(ll i=0;i<m;i++){
        cin >> p[i].first >> p[i].second >> q[i].first >> q[i].second >> queries[i][0] >> queries[i][1];
        compress[p[i].first], compress[q[i].first];
        queries[i][2] = i;
    }

    ll cnt=0;
    for(auto &p:compress)
        p.second = cnt++;
    
    for(ll i=0;i<n;i++)
        traps[i][1] = compress[traps[i][1]];   
    
    for(ll i=0;i<m;i++){
        p[i].first = compress[p[i].first];
        q[i].first = compress[q[i].first];
    }

    //
    for(ll i=0;i<n;i++) traps[i][0] -= traps[i][2];
    for(int i=0;i<4*maxn;i++) st[i] = -inf;
    sort(traps.begin(),traps.end());
    sort(queries.begin(),queries.end());
    for(ll i=0, j=0;i<m;i++){
        for(;j<n && traps[j][0] <= queries[i][0];j++)
            update(1,0,maxn-1,traps[j][1],2*traps[j][2]+traps[j][0]);
        ll l = p[queries[i][2]].first, r = q[queries[i][2]].first;
        answ[queries[i][2]] = answ[queries[i][2]]&&((get(1,0,maxn-1,min(l,r),max(l,r)) < queries[i][1]));
        swap(queries[i][0],queries[i][1]);
    }
    
    for(ll i=0;i<m;i++){
        cout << (answ[i] ? "YES" : "NO") << '\n';
    }

    return 0;
}
