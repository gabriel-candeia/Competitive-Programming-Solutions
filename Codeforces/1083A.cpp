#include<bits/stdc++.h>
#define N int(3e5+5)
#define ll long long
using namespace std;

vector<pair<ll,ll>> adj[N];
ll w[N], n, mx[N], answ=0;

void dfs(int u, int p){
    mx[u] = w[u]; answ = max(answ,mx[u]);
    ll v, wt;
    for(auto e:adj[u]){
        v = e.first, wt = e.second;
        if(v!=p){
            dfs(v,u);
            answ = max(answ,mx[u]+mx[v]-wt);
            mx[u] = max(mx[u],w[u]+mx[v]-wt);
        }
    }
}

int main(){
    int x, y, wt;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> w[i];
    }

    for(int i=1;i<n;i++){
        cin >> x >> y >> wt;
        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});
    }
    dfs(1,-1);
    cout << answ <<'\n';
    return 0;
}