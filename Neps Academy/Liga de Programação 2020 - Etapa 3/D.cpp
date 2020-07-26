#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
int n, x, y;

void dfs(int u, int t){
    visited[u] = (t%2+1);
    for(auto v:adj[u]){
        if(!visited[v]){
            dfs(v,t+1);
        }
    }
}

int main(){

    cin >> n;
    adj.assign(n+1,vector<int>());
    visited.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(visited[i]==1){
            cnt++;
        }
    }

    if(2*cnt==n){
        cout << "Y\n";
    }
    else{
        cout << "N\n";
    }

    return 0;
}