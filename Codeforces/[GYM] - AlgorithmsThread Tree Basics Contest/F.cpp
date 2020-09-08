#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define maxn int(1e5+5)
using namespace std;

int n, d[maxn], f[maxn], h[maxn];
vector<vector<int>> adj;
vector<ll> arr, st;

void dfs(int u, int p, int ht){
    arr.push_back(0);
    h[u] = ht;
    d[u] = arr.size()-1;

    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u,ht+1);

    f[u] = arr.size()-1;
}

ll build(ll p,ll l, ll r){
    if(l==r)
        return st[p] = arr[l];
    int med = l+(r-l)/2;
    return st[p] = build(2*p,l,med)+build(2*p+1,med+1,r);
}

ll update(ll p,ll l,ll r,ll i,ll v){
    if(l==r)
        return st[p]+=v;
    int med = l + (r-l)/2;
    if(i<=med)
        return st[p] = update(2*p,l,med,i,v) + st[2*p+1];
    return st[p] = st[2*p] + update(2*p+1,med+1,r,i,v);
}

ll get(ll p,ll l,ll r,ll i, ll j){
    if(r<i || j<l)
        return 0;
    else if(i<=l && r<=j)
        return st[p];
    int med = l + (r-l)/2;
    return get(2*p,l,med,i,j)+get(2*p+1,med+1,r,i,j);
}

int main(){
    int t, q, x, y, z;;
    fastio();
    cin >>t;   
    while(t--){
        cin >> n >> q;
        adj.assign(n+1,vector<int>());
        for(int i=0;i<n-1;i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        arr.clear();
        dfs(1,-1,0);
        st.assign(4*n+4,0);
        build(1,0,n-1);

        while(q--){
            cin >> x >> y >> z;
            if(z){
                update(1,0,n-1,d[x],z);
                update(1,0,n-1,d[y],-z);
            }
            else{
                if(h[x]<h[y])
                    swap(x,y);
                cout << abs(get(1,0,n-1,d[x],f[x])) <<'\n';
            }
        }
    }

    return 0;
}