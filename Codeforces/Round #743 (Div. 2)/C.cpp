#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> ord, visited;

bool dfs(int u){
    visited[u] = 2;
    bool ret = true;

    for(auto v:adj[u]){
        if(visited[v]==2)
            ret = false;
        else if(visited[v]==0)
            ret = ret && dfs(v);
    }
    visited[u] = 1;

    ord.push_back(u);
    return ret;
}

int main(){
    int t;

    cin >> t;
    while(t--){
        cin >> n;
        adj.assign(n+1,vector<int>());

        for(int i=1;i<=n;i++){
            int k;
            cin >> k;
            for(int j=0;j<k;j++){
                int a;
                cin >> a;
                adj[a].push_back(i);
            }
        }

        ord.clear();
        visited.assign(n+1,false);

        bool answ = true;
        for(int i=1;i<=n;i++){
            if(!visited[i])
                answ = answ && dfs(i);
        }

        if(answ){
            vector<int> dp(n+1,0);
            reverse(ord.begin(),ord.end());
            for(auto u:ord){
                for(auto v:adj[u]){
                    if(u<v)
                        dp[v] = max(dp[v],dp[u]);
                    else
                        dp[v] = max(dp[v],dp[u]+1);
                }
            }

            int answ = 0;
            for(int i=1;i<=n;i++)
                answ = max(answ,dp[i]);
            cout << answ+1 <<"\n";

        }
        else{
            cout << -1 <<"\n";
        }
    }

    return 0;
}