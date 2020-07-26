#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, int u, vector<bool>& visited){
    visited[u] = true;
    for(auto v:adj[u]){
        if(!visited[v]){
            dfs(adj,v,visited);
        }
    }
}

int main(){
    int n, m, k, x, y, z, x0, y0, z0;
    vector<vector<int>> adj;
    tuple<int,int,int> vet[1010];

    cin >> n >> m >> k;
    adj.assign(k+4,vector<int>());
    for(int i=0;i<k;i++){
        cin >> x >> y >> z;
        vet[i+4] = {x,y,z};
    }

    for(int i=4;i<k+4;i++){
        tie(x, y, z) = vet[i];
        for(int j=i+1;j<k+4;j++){
            tie(x0, y0, z0) = vet[j];
            if((x-x0)*(x-x0) + (y-y0)*(y-y0) <= (z+z0)*(z+z0)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        if(y+z>=m){
            adj[i].push_back(0);
            adj[0].push_back(i);
        }
        if(x+z>=n){
            adj[i].push_back(1);
            adj[1].push_back(i);
        }
        if(y<=z){
            adj[i].push_back(2);
            adj[2].push_back(i);
        }
        if(x<=z){
            adj[i].push_back(3);
            adj[3].push_back(i);
        }
    }

    /*for(int i=0;i<k+4;i++){
        cout << i << ": ";
        for(auto v: adj[i]){
            cout << v << " ";
        }cout << '\n';
    }*/

    //ruim 0--1, 0--2, 1--3, 2--3
    vector<bool> visited(k+5,false);
    bool poss = true;
    dfs(adj,0,visited);
    poss = (poss && !(visited[1] || visited[2]));
    visited.assign(k+5,false);
    dfs(adj,3,visited);
    poss = (poss && !(visited[1] || visited[2]));
    cout << (poss ? "S" : "N") << '\n';
    return 0;
}