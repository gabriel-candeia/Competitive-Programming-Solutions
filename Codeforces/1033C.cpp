#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int u, int n, vector<int>& visited, stack<int>& st){
    visited[u] = true;

    for(auto v:adj[u]){
        if(!visited[v]){
            dfs(adj,v,n,visited,st);
        }
    }

    st.push(u);
}

int main(){
    int n, u;
    vector<int> arr, visited;
    vector<vector<int>> adj;
    stack<int> st;
    vector<bool> color;

    cin >> n;
    arr.assign(n,0);
    color.assign(n,0);
    visited.assign(n,0);
    adj.assign(n,vector<int>());
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i%arr[i];j<n;j+=arr[i]){
            if(arr[j]>arr[i]){
                adj[j].push_back(i);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,i,n,visited,st);
        }
    }

    while(st.size()){
        u = st.top(); st.pop();
        if(color[u]==0){
            for(auto v:adj[u]){
                color[v] = 1;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << ((color[i]==1) ? 'A' : 'B');
    }
    cout << '\n';

    return 0;
}
