#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int>& adj, int u, vector<int>& visited){
    int ret = -1;
    visited[u] = 1;
    

    if(visited[adj[u]]==0){
        ret = dfs(adj, adj[u], visited);
    }
    else if(visited[adj[u]]==1){
        ret = u;
    }
    visited[u] = 2;
    return ret;
}

int find_best(vector<int>& adj, int u, vector<int>& c){
    int curr = adj[u], best = c[u];
    while(curr!=u){
        best = min(best,c[curr]);
        curr = adj[curr];
    }

    return best;
}

int main(){
    int n, start, soma=0;
    vector<int> c, adj;
    vector<int> visited;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    c.assign(n+1,0);
    adj.assign(n+1,0);
    visited.assign(n+1,0);

    for(int i=1;i<=n;i++){
        cin >> c[i];
    }

    for(int i=1;i<=n;i++){
        cin >> adj[i];
    }

    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            start = dfs(adj,i,visited);
            if(start!=-1){
                soma += find_best(adj,start,c);
            }
        }
    }

    cout << soma << '\n';

    return 0;
}