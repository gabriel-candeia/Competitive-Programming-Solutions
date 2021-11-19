#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> visited;


bool dfs(int i, int h){
    bool ret = true;
    visited[i] = h;
    for(auto v:adj[i]){
        if(!visited[v])
            ret = ret&&dfs(v,(h==2) ? 1 : 2);
        else if(visited[v]==visited[i])
            ret = false;
    }
    return ret;
}

int main(){
    cin >> n >> m;
    adj.assign(n+1,vector<int>());
    for(int i=0, a, b;i<m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll answ = 0;
    for(int i=0;i<(1<<n);i++){
        visited.assign(n+1,0);
        for(int j=i, u=1;u<=n;j/=2,u++)
            visited[u] = ((j&1) ? -1 : 0);
        bool bip=true;
        ll acm = 0;
        for(int u=1;u<=n;u++){
            if(!visited[u]){
                bip = bip&&dfs(u,1);
                acm++;
            }
        }
        for(int u=1;u<=n;u++)
            for(auto v:adj[u])
                if(visited[u]==-1 && visited[v]==-1)
                    bip = false;
        if(bip) answ += (1ll<<acm);
    }
    cout << answ <<"\n";
    return 0;
}
