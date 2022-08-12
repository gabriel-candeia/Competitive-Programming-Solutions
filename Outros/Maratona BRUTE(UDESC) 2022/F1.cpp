#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
#define maxn int(1e5+10)
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define f first
#define s second
const ll LINF = 1e18;

namespace beats {
    struct node {
        int tam;
        ll sum, lazy; // lazy pra soma
        ll mi1, mi2, mi; // mi = #mi1
    
        node(ll x = 0) {
            sum = mi1 = x;
            mi2 = LINF;
            mi = tam = 1;
            lazy = 0;
        }
        node(const node& l, const node& r) {
            sum = l.sum + r.sum, tam = l.tam + r.tam;
            lazy = 0;
            if (l.mi1 > r.mi1) {
                mi1 = r.mi1, mi = r.mi;
                mi2 = min(l.mi1, r.mi2);
            } else if (l.mi1 < r.mi1) {
                mi1 = l.mi1, mi = l.mi;
                mi2 = min(r.mi1, l.mi2);
            } else {
                mi1 = l.mi1, mi = l.mi+r.mi;
                mi2 = min(l.mi2, r.mi2);
            }
        }
        void setmax(ll x) {
            if (x <= mi1) return;
            sum += (x - mi1)*mi;

            mi1 = x;
        }
    };
    
    node seg[4*maxn];
    int n;
    ll *v;
    
    node build(int p=1, int l=0, int r=n-1) {
        if (l == r) return seg[p] = {v[l]};
        int m = (l+r)/2;
        return seg[p] = {build(2*p, l, m), build(2*p+1, m+1, r)};
    }
    void build(int n2, ll *v2) {
        n = n2, v = v2;
        build();
    }
    void prop(int p, int l, int r) {
        if (l == r) return;
        for (int k = 0; k < 2; k++) {
            seg[2*p+k].setmax(seg[p].mi1);
        }
    }
    ll query(int a, int b, int p=1, int l=0, int r=n-1) {
        if (b < l or r < a) return 0;
            if (a <= l and r <= b) return seg[p].sum;
            prop(p, l, r);
        int m = (l+r)/2;
        auto L = query(a, b, 2*p, l, m), R = query(a, b, 2*p+1, m+1, r);
        return L+R;
    }
    node updatemax(int a, int b, ll x, int p=1, int l=0, int r=n-1) {
        if (b < l or r < a or seg[p].mi1 >= x) return seg[p];
        if (a <= l and r <= b and seg[p].mi2 > x) {
            seg[p].setmax(x);
            return seg[p];
        }
        prop(p, l, r);
        int m = (l+r)/2;
        return seg[p] = {updatemax(a, b, x, 2*p, l, m),
            updatemax(a, b, x, 2*p+1, m+1, r)};
    }
};

ll t;
ll pos[maxn], sz[maxn], volta[maxn];
ll wei[maxn], val[maxn];
ll h[maxn], dad[maxn], hei[maxn];
vector<int> adj[maxn];

void build_hld(ll u, ll p, ll f, ll hh){
    hei[u] = hh;
    volta[t] = u;
    val[pos[u] = t++] = wei[u]; sz[u] = 1;
    for(auto &v:adj[u]){
        if(v != p){
            dad[v] = u;
            h[v] = (v == adj[u][0] ? h[u] : v);
            build_hld(v, u, f, hh+1);
            sz[u] += sz[v];
            if(sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
        }
    }
    if(p*f == -1) h[u] = u, t = 0, build_hld(u, -1, 0, 1);
}

void build(ll root){
    t = 0; 
    build_hld(root, -1, 1, 1);
    beats::build(t,val);
}

void update(ll u, ll v, ll x){
    if(pos[u] < pos[v]) swap(u, v);
    if(h[u] == h[v]) return (void)beats::updatemax(pos[v], pos[u], x);
    beats::updatemax(pos[h[u]], pos[u], x);
    update(dad[h[u]], v, x);
}

ll get_subtree(ll u){
    return beats::query(pos[u], pos[u]+sz[u]-1);
}

ll k_th(ll u, ll k){
    while(k){
        if(k > (hei[u]-hei[h[u]])){
            k -= (hei[u]-hei[h[u]]+1); 
            u = dad[h[u]];
        }else{
            u = volta[pos[u]-k]; 
            k = 0;
        }
    }
    return u;
}

void q0(ll u, ll k, ll w){
    ll v = k_th(u, k); 
    update(u, v, w);
}

ll q1(ll u){
    return get_subtree(u);
}

int main(){
    fastio();
    ll n, q; cin >> n >> q;
    for(ll i = 2, d; i <= n; i++){
        cin >> d;
        adj[i].emplace_back(d);
        adj[d].emplace_back(i);
    }
    for(ll i = 1, d; i <= n; i++) cin >> wei[i];
    build(1);
    while(q--){
        ll op; cin >> op;
        if(op&1){
            ll u; cin >> u;
            cout << q1(u) << "\n";
        }else{
            ll u, k, w; cin >> u >> k >> w;
            k--;
            k = max(k,0ll);
            q0(u, k, w);
        }
    }
    return 0;
}