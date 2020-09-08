#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

vector<vector<int>> adj;
vector<int> dist, parent;
int n, x, y;

int bfs(int u){
    dist.assign(n+1,0);
    parent.assign(n+1,-1);
    queue<int> q;
    q.push(u);
    dist[u] = 1;

    while(q.size()){
        u = q.front(); q.pop();

        for(auto v:adj[u]){
            if(!dist[v]){
                dist[v] = dist[u]+1;
                parent[v] = u;
                q.push(v);
            }
        }

    }

    return u;
}

vector<int> visited;
int diameter;
void dfs(int u, int x){
    visited[u] = diameter + ((x) ? 1 : 2);
    
    for(auto v:adj[u]){
        if(!visited[v]){
            dfs(v,x-1);
        }
    }
}



int main(){
    fastio();
    cin >> n;
    adj.assign(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int u = bfs(bfs(1));
    diameter = dist[u]-1;

    visited.assign(n+1,0);
    for(int v=u;v!=-1;v=parent[v]){
        visited[v] = true;
    }
    for(int v=u,i=0;v!=-1;v=parent[v],i++){
        dfs(v,min(i,diameter-i));
    }

    for(int i=1;i<=n;i++){
        cout << visited[i]-1 << '\n';
    }

    return 0;
}