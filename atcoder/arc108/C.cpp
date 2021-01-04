#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int n, m, color[maxn], visited[maxn];
vector<pair<int,int>> adj[maxn];

void solve(int u){
    for(auto e:adj[u]){
        if(!color[e.first]){
            color[e.first] = ((color[u]!=e.second) ? e.second : (e.second+1)-n*(e.second==n));
            solve(e.first);
        }
    }
}

void check(int u){
    visited[u] = true;

    for(auto e:adj[u]){
        if(!visited[e.first] && !(e.second==color[u] && e.second==color[e.first]) && !(e.second!=color[u] && e.second!=color[e.first])){
            check(e.first);
        }
    }
}

int main(){
    int u, v, c;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    color[1] = 1;
    solve(1);
    check(1);

    int acm = 0;
    for(int i=1;i<=n;i++){
        acm+=visited[i];
    }

    if(acm==n){
        for(int i=1;i<=n;i++){
            cout << color[i] << '\n';
        }
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}