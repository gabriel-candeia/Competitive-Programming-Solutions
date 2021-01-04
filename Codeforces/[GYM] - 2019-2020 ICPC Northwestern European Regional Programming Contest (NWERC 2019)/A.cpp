#include <bits/stdc++.h>
#define ll long long 
using namespace std;

typedef long double ld;

#define maxn 300300

ll n, w;
ll v[maxn], bit[maxn], ans[maxn], ultimo[maxn], rnk[maxn];
vector<set<int>> adj;

void update(ll pos, ll val){
    if(pos == 0) return;
    for(; pos < maxn; pos += (pos&(-pos))){
        bit[pos] += val;
    }
}

ll sum(ll pos){
    ll ans = 0;
    for(; pos > 0; pos -= (pos&(-pos))){
        ans += bit[pos];
    }
    return ans;
}

ll query(ll l, ll r){
    return sum(r) - sum(l-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k, cara;
    cin >> n >> w;

    for(ll i = 0; i < w; i++){
        cin >> k;
        while(k--){
            cin >> cara;
            update(v[cara], -1);
            adj[rnk[cara]].erase(cara);
            v[cara]++;
            
            update(v[cara], 1);
            adj[rnk[cara]].erase(cara+1);
            rnk[cara]++;
        }
        for(ll i = 1; i <= n; i++){
            ans[i] += query(v[i]+1, w)+1;
        }
    }
    for(ll i = 1; i <= n; i++){
        cout << fixed << setprecision(9) << (ld(ans[i])/ld(w)) << "\n";
    }
    return 0;
}