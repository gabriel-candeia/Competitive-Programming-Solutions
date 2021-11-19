#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dist, wt;
vector<pair<int,int>> edges;

int main(){
    int t, caso=0;
    cin >> t;
    while(t--){
        int n, m;
        vector<vector<pair<int,int>>> arr(2,vector<pair<int,int>>());
        edges.clear();
        cin >> n >> m;
        adj.assign(n+1,vector<int>());
        wt.assign(n+1,0);
        for(int i=0, x;i<n-1;i++){
            cin >> x;
            arr[x>0].push_back({abs(x),i+2});
        }
        for(int i=0;i<2;i++)
            sort(arr[i].begin(),arr[i].end());

        for(int i=0, x, y;i<m;i++){
            cin >> x >> y;
            edges.push_back({x,y});
            adj[x].push_back(i);
            adj[y].push_back(i);
        }
        
        wt.assign(m,1e6);
        dist.assign(n+1,0);
        vector<int> aux, ordem; aux.push_back(0), ordem.push_back(1);
        for(int i=0, j=0;aux.size()<n;){
            int m = aux.size(), add = ((i<arr[1].size()) ? arr[1][i].first : aux.back()+1);
            while(j<arr[0].size() && arr[0][j].first==m){
                aux.push_back(add);
                ordem.push_back(arr[0][j].second);
                dist[arr[0][j].second] = add;
                j++;
            }
            while(i<arr[1].size() && (j==arr[0].size() || arr[0][j].first>aux.size())){
                aux.push_back(arr[1][i].first);
                ordem.push_back(arr[1][i].second);
                dist[arr[1][i].second] = arr[1][i].first;
                i++;
            }
        }

        vector<bool> visited(n+1,0);
        visited[1] = true;
        for(auto u:ordem){
            for(auto e:adj[u]){
                int v = (edges[e].first==u) ? edges[e].second : edges[e].first;
                if(!visited[v] && (dist[v]-dist[u])){
                    visited[v] = true;
                    wt[e] = dist[v]-dist[u];
                }
            }
        }
        cout << "Case #" << ++caso <<": ";
        for(int i=0;i<m;i++)
            cout << wt[i] << " ";
        cout<<'\n';
        
    }

    return 0;
}