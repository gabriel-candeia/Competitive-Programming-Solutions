#include<bits/stdc++.h>
using namespace std;

vector<int> answ, pred;
vector<bool> visited, mp, bad;

int main(){
    int n, k, d, u, v;
    vector<vector<pair<int,int>>> adj;

    cin >> n >> k >> d;
    mp.assign(n+1,0);
    visited.assign(n+1,0);
    pred.assign(n+1,0);
    adj.assign(n+1,vector<pair<int,int>>());
    bad.assign(n+1,false);
    for(int i=0;i<k;i++){
        cin >> u;
        mp[u] = true;
    }

    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].push_back({v,i+1});
        adj[v].push_back({u,i+1});
    }
    
    queue<int> q;
    k = 0;
    for(int i=1;i<=n;i++){
        if(mp[i]){
            q.push(i);
            visited[i] = true;
            k++;
        }
    }

    while(q.size()){
        int u = q.front(); q.pop();
        for(auto p:adj[u]){
            int v = p.first;
            if(visited[v] && pred[u]!=v){
                bad[p.second] = true;
            }
            if(!visited[v]){
                visited[v] = true;
                pred[v] = u;
                q.push(v);
            }
        }
    }

    cout << k-1 << '\n';
    for(int i=1;i<n;i++){
        if(bad[i]){
            cout << i << " ";
        }
    }cout << '\n';

    return 0;
}