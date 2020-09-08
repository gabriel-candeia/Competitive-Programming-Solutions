#include<bits/stdc++.h>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
using namespace std;

const ll inf = 1e16;

int main(){
    fastIO();
    ll n, m, k;
    ll u, v, w, id, dist, ide;
    vector<vector<tuple<ll,ll,ll>>> adj;
    vector<bool> selected, visited;

    cin >> n >> m >> k;
    int resp = k;
    selected.assign(m+1,false);
    visited.assign(n+1,false);
    adj.assign(n+1,vector<tuple<ll,ll,ll>>());
    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        adj[u].push_back({v,w,i});
        adj[v].push_back({u,w,i});
    }

    vector<ll> d(n+1,inf);
    priority_queue<tuple<ll,ll,ll>> pq;
    d[1] = 0;
    pq.push({-d[1],1,0});

    k++;
    while(pq.size() && k){
        tie(dist, u, id) = pq.top(); pq.pop();
        dist *=-1;
        if(!visited[u]){
            k--;
            visited[u] = true;
            selected[id] = true;
            for(auto e:adj[u]){
                tie(v,w,ide) = e;
                if(d[u]+w<d[v]){
                    d[v] = d[u]+w;
                    pq.push({-d[v],v,ide});
                }
            }
        }
    }

    selected[0] = false;
    cout << resp << '\n';
    for(int i=1;i<=m;i++){
        if(k && !selected[i]){
            selected[i] = true;
            k--;
        }
        if(selected[i]){
            cout << i << ' ';
        }
    }cout << '\n';      

    return 0;   
}