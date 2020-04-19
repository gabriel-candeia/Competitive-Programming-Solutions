#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj,int u, int start, vector<bool>& visited){
    visited[u] = true;
    bool print = true;
    for(auto v: adj[u]){
        if(u==start){
            cout << u << ' ';
        }
        if(!visited[v]){
            print = false;
            dfs(adj,v,start,visited);
        }
        if(u==start){
            cout << '\n';
        }
    }
    if(print){
        cout << u << ' ';
    }
}

int main(){
    int n, a, b;
    vector<vector<int>>adj;

    cin >> n;
    adj.assign(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cnt=0, start=1;
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(adj[i].size()>=3){
            cnt++;
            start = i;
        }
    }

    if(cnt>=2){
        cout << "No\n";
        return 0;
    }
    
    cout << "Yes\n";
    cout << adj[start].size() << '\n';
    dfs(adj,start,start,visited);

    return 0;
}