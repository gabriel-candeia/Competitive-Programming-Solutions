#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll dfs2(vector<vector<ll>>& adj, ll v, vector<ll>& h, vector<ll>& cnt, vector<bool>& visited){
    visited[v]= true;
    for(auto w:adj[v]){
        if(!visited[w]){
            h[w] = h[v]+1;
            cnt[v] += dfs2(adj, w, h, cnt,visited)+1;
        }
    }
    return cnt[v];
}

int main(){
    ll n, k, u, v;
    vector<vector<ll>> adj;
    vector<ll> cnt, h;
    vector<bool> visited;
    ll answ=0;

    cin >> n >> k;
    adj.assign(n,vector<ll>());
    h.assign(n,0);
    cnt.assign(n,0);
    visited.assign(n,false);

    for(ll i=0;i<n-1;i++){
        cin >> u >> v;
        adj[v-1].push_back(u-1);
        adj[u-1].push_back(v-1);
    }

    dfs2(adj,0,h,cnt,visited);
    for(ll i=0;i<n;i++){
        h[i] -= cnt[i];
    }

    sort(h.rbegin(),h.rend());
    answ = 0;
    for(ll i=0;i<k;i++){
        answ += h[i];
    }

    cout << answ << '\n';

    return 0;
}