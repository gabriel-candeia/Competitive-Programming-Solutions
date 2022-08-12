//subtasks 1 and 2
#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int n;
ll answ[maxn], d[maxn], c[maxn], r[maxn], parent[maxn];
vector<pair<int,ll>> adj[maxn];

void precomp(int u, int p){
    parent[u] = p;
    for(auto e:adj[u]){
        int v = e.first;
        if(v!=p){
            d[v] = d[u] + e.second;
            precomp(v,u);
        }
    }
}

LineContainer st;
void solve(int u, int p){
    answ[u] = ((p==-1) ? 0 : -st.query(d[u]));
    st.add(-c[u],c[u]*d[u]-answ[u]-r[u]);

    for(auto e:adj[u]){
        int v = e.first;
        if(v!=p){
            solve(v,u);
        }
    }
}

void solveBurro(){
    queue<int> q;
    q.push(1); answ[1] = 0;
    for(int i=2;i<=n;i++)
        answ[i] = 1e17;
    while(q.size()){
        int i = q.front(); q.pop();
        for(auto v:adj[i])
            if(v.first!=parent[i])
                q.push(v.first);
        for(int j=parent[i];j!=-1;j=parent[j]){
            answ[i] = min(answ[i],answ[j]+c[j]*(d[i]-d[j])+r[j]);
        }
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n-1;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    for(int i=1;i<=n;i++){
        cin >> c[i] >> r[i];
    }

    precomp(1,-1);
    if(n>1000){
        solve(1,-1);
    }
    else{
        solveBurro();
    }
    
    for(int i=2;i<=n;i++){
        cout << answ[i] << " ";
    }cout<<"\n";

    return 0;
}