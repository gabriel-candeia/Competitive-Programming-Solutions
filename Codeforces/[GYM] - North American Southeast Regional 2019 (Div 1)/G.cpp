#include<bits/stdc++.h>
#define maxn int(4e6+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
using namespace std;

const ll mod = 11092019;
pair<int,ll> st[maxn];

pair<int,ll> combine(const pair<int,ll> p1, const pair<int,ll> p2){
    if(p1.first>p2.first)
        return p1;
    if(p1.first<p2.first)
        return p2;
    if(p1.first==0)
        return {0,1};
    return {p1.first,(p1.second+p2.second)%mod};
}

pair<int,ll> build(int p, int l, int r){
    if(l==r){
        return st[p] = {0,1};
    }
    int med = (l+r)/2;
    return st[p] = combine(build(2*p,l,med),build(2*p+1,med+1,r));
}

pair<int,ll> update(int p, int l, int r, int i, pair<int,ll> v){
    if(l==r){
        return st[p] = v;
    }
    int med = (l+r)/2;
    if(i<=med)
        return st[p] = combine(update(2*p,l,med,i,v),st[2*p+1]);
    return st[p] = combine(st[2*p],update(2*p+1,med+1,r,i,v));
}

pair<int,ll> get(int p, int l, int r, int j){
    if(l>j)
        return {0,1};
    if(r<=j)
        return st[p];
    int med = (l+r)/2;
    return combine(get(2*p,l,med,j),get(2*p+1,med+1,r,j));
}

pair<int,ll> getPoint(int p, int l, int r, int i){
    if(l==r){
        return st[p];
    }
    int med = (l+r)/2;
    if(i<=med)
        return getPoint(2*p,l,med,i);
    return getPoint(2*p+1,med+1,r,i);
}

vector<int> adj[maxn], val;
pair<int,ll> answ[maxn];
const int mx = 1e6;

pair<int,ll> solve(int u){
    pair<int,ll> old = getPoint(1,0,mx,val[u]);
    auto p = get(1,0,mx,val[u]); p.first++;
    auto p1 = update(1,0,mx,val[u],p);
    
    answ[u] = ((adj[u].size()==0) ? p1 : pair<int,ll>{0,1});
    for(auto v:adj[u])
        answ[u] = combine(answ[u],solve(v));
    if(adj[u].size()!=0 && answ[u].first==p1.first){
        for(auto v:adj[u])
            if(answ[v].first==answ[u].first)
                answ[u].second = ((answ[u].second - p1.second)%mod+mod)%mod;
            answ[u].second = (answ[u].second + p1.second)%mod;
    }
    update(1,0,mx,val[u],old);
    return answ[u];
}


int main(){
    fastio();

    int n;

    cin >> n;
    val.assign(n,0);
    for(auto &x:val)
        cin >> x;
    for(int i=1;i<n;i++){
        int x;
        cin >> x;
        adj[x-1].push_back(i);
    }

    build(1,0,mx);
    solve(0);

    cout << answ[0].first << " " << answ[0].second <<"\n";
    
    return 0;
}