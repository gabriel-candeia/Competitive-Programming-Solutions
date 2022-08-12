#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int n;
vector<int> adj[maxn];
vector<pair<int,int>> t1, t2;
vector<int> visited;

void dfs(int u){
    visited[u] = 1;
    for(auto v:adj[u]){
        if(!visited[v]){
            t1.push_back({u,v});
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    visited[u] = 1;
    q.push(u);

    while(q.size()){
        u = q.front(), q.pop();
        for(auto v:adj[u]){
            if(!visited[v]){
                t2.push_back({u,v});
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}


int main(){
    int m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited.assign(n+1,0);
    dfs(1);

    visited.assign(n+1,0);
    bfs(1);

    for(auto p:t1)
        cout << p.first << " " << p.second <<"\n";
    for(auto p:t2)
        cout << p.first << " " << p.second <<"\n";

    return 0;
}