#include<bits/stdc++.h>
using namespace std;

stack<int> st;
bool poss = true;
vector<pair<int,int>> edges;
vector<int> direction;    
    
void dfs(vector<vector<int>>& adj, int u, vector<int>& visited){
    visited[u] = 1;
    for(auto v:adj[u]){
        if(visited[v]==1){
            poss = false;
        }
        else if(!visited[v]){
            dfs(adj,v,visited);
        }
    }
    visited[u] = 2;
    st.push(u);
}

int main(){
    int n, m, x, y, t, cases;    
    vector<int> visited;
    vector<vector<int>> adj, adjR, adjU;

    cin >> cases;
    while(cases--){
        cin >> n >> m;

        poss = true;
        adj.assign(n+1,vector<int>()); adjR.assign(n+1,vector<int>()); adjU.assign(n+1,vector<int>());
        edges.clear(); direction.clear();
        for(int i=0;i<m;i++){
            cin >> t >> x >> y;
            edges.push_back({x,y});
            if(t==0){
                direction.push_back(0);
                adjU[x].push_back(edges.size()-1);
                adjU[y].push_back(edges.size()-1);
            }
            else{
                direction.push_back(1);
                adj[x].push_back(y);
                adjR[y].push_back(x);
            }
            
        }

        visited.assign(n+1,0);
        for(int u=1;u<=n;u++){
            if(!visited[u]){
                dfs(adjR,u,visited);
            }
        }
        
        if(poss){
            cout << "YES\n";
            while(st.size()){
                int u = st.top(); st.pop();
                if(adj[u].size() || adjR[u].size()){
                    for(auto i:adjU[u]){
                        if(direction[i]==0){
                            direction[i] = 1;
                            if(edges[i].first==u){
                                edges[i].first = edges[i].second;
                                edges[i].second = u;
                            }
                        }
                    }
                }
            }

            for(int i=0;i<edges.size();i++){
                if(direction[i]==0){
                    cout << min(edges[i].first,edges[i].second) << " " << max(edges[i].second,edges[i].first) <<'\n';
                }
                else{
                    cout << edges[i].first << " " << edges[i].second << '\n';
                }
            }
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}