#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

const ll mod = 1e9+7;
const ll inf = 1e18;
int n, m;
vector<pair<ll,ll>> adj[maxn];

vector<ll> dijkstra(int s, int t){
    vector<ll> dist(n+1,inf), cnt(n+1,inf), mn(n+1,inf), mx(n+1,0);
    priority_queue<tuple<ll,ll>> pq;
    ll d, u;
    dist[s] = 0, pq.push({-dist[s],s}), cnt[1] = 1, mn[1] = 0;
    while(pq.size()){
        tie(d,u) = pq.top(), pq.pop(); d *= -1;
        if(d>dist[u]) continue;
        for(auto e:adj[u]){
            if(d+e.second==dist[e.first]){
                cnt[e.first] = (cnt[e.first]+cnt[u])%mod, mn[e.first] = min(mn[e.first],mn[u]+1), mx[e.first] = max(mx[e.first], mx[u]+1);
            }
            if(d+e.second<dist[e.first]){
                dist[e.first] = d+e.second, pq.push({-dist[e.first],e.first}); 
                cnt[e.first]=cnt[u], mn[e.first] = mn[u]+1, mx[e.first]=mx[u]+1;
            }
        }
    }

    return {dist[t], cnt[t], mn[t], mx[t]};
}

int main(){
    ll a, b, c;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    auto answ = dijkstra(1,n);
    for(auto x:answ)
        cout << x << " ";
    cout << '\n';

    return 0;
}