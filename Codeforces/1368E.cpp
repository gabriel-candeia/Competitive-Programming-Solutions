#include<bits/stdc++.h>
using namespace std;

stack<int> ord;
vector<bool> visited;
void dfs(vector<vector<int>>& adj, int u){
    visited[u] = true;
    for(auto v: adj[u]){
        if(!visited[v]){
            dfs(adj,v);
        }
    }
    ord.push(u);
}


int main(){
    int t, n, m, x, y;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        vector<vector<int>> adj(n+1,vector<int>());
        visited.assign(n+1,false);

        for(int i=0;i<m;i++){
            cin >> x >> y;
            adj[x].push_back(y);
        }

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(adj,i);
            }
        }

        vector<int> dist(n+1,0);
        int u, cnt=0;
        while(ord.size()){
            u = ord.top(); ord.pop();
            if(dist[u]!=2){
                for(auto v:adj[u]){
                    dist[v] = max(dist[u]+1,dist[v]);
                }
            }
            else{
                cnt++;
            }
        }
        cout << cnt << '\n';
        for(int i=1;i<=n;i++){
            if(dist[i]==2){
                cout << i << ' ';
            }
        }
        cout << '\n';

    }

    return 0;
}