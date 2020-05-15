#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, int u, vector<int>& visited, int turno){
    visited[u] = turno;
    bool poss = true;

    for(auto v:adj[u]){
        if(!visited[v]){
            poss = (dfs(adj,v,visited,(turno==1) ? 2 : 1) && poss);
        }
        else if(visited[u]==visited[v]){
            poss = false;
        }
    }

    return poss;
}

int main(){
    int n, m, a, b;
    vector<pair<int,int>> edges;
    vector<vector<int>> adj;
    vector<int> visited;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    visited.assign(n+1,0);
    adj.assign(n+1,vector<int>());
    for(int i=0;i<m;i++){
        cin >> a >> b;
        edges.push_back({a,b});

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bool poss = true;
    for(int i=1; i<=n && poss; i++){
        if(!visited[i]){
            poss = (dfs(adj,i,visited,1) && poss);
        }
    }

    if(poss){
        cout << "YES\n";
        for(auto p:edges){
            if(visited[p.first]-visited[p.second]<0){
                cout << '1';
            }
            else{
                cout << '0';
            }
        }
        cout << '\n';
    }
    else{
        cout << "NO\n";
    }

    return 0;
}