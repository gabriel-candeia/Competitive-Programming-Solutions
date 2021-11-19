#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

const ll inf = 1e18;
vector<pair<ll,ll>> adj[maxn];
ll n, m, k;

vector<ll> solve(ll s, ll t){
    vector<vector<ll>> dist(n+1,vector<ll>(k,inf));
    vector<ll> ptr(n+1,0);
    priority_queue<tuple<ll,ll>> pq;
    ll d, u;

    dist[s][0] = 0;
    pq.push({-dist[s][0],s});
    while(pq.size()){
        tie(d,u) = pq.top(), pq.pop(); d = -d;

        if(ptr[u]==k) continue;
        for(auto e:adj[u]){
            if(ptr[e.first]<k)
                pq.push({-d-e.second,e.first});
        }
        dist[u][ptr[u]++] = d;
    }

    return dist[t];
}


int main(){
    ll a, b, c;

    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    auto answ = solve(1,n);
    for(auto x:answ)
        cout << x << " ";
    cout<<'\n';
    return 0;   
}