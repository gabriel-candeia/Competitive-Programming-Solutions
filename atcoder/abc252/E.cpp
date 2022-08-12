#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define ll long long
using namespace std;


int n, m;
vector<tuple<ll,ll,ll>> adj[maxn];
const ll inf = 1e18;

vector<ll> solve(int s){
    vector<ll> dist(n+1,inf), parent(n+1,0),answ;
    priority_queue<tuple<ll,ll>> pq;
    dist[s] = 0;
    pq.push({-dist[s],s});

    ll u, d,id;
    while(pq.size()){
        tie(d,u) = pq.top(), pq.pop(), d = -d;
        
        if(d>dist[u]) continue;
        for(auto e:adj[u]){
            ll v, wt, id;
            tie(v,wt,id) = e;
            if(dist[v]>d+wt){
                dist[v] = d+wt;
                pq.push({-dist[v],v});
                parent[v] = id;
            }
        }

    }

    for(int i=2;i<=n;i++)
        answ.push_back(parent[i]);
    return answ;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c,i+1});
        adj[b].push_back({a,c,i+1});
    }

    auto edges = solve(1);
    for(auto &x:edges){
        cout << x <<" ";
    }cout<<"\n";

    return 0;
}