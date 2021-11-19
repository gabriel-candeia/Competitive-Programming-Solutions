#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

const ll inf = 1e9;
int n, m;
vector<int> adj[maxn], visited, ord;

bool dfs(int u){
    bool ret = true;
    visited[u] = 1;
    for(auto v:adj[u]){
        if(!visited[v])
            ret = ret && dfs(v);
        else if(visited[v]==1)
            ret = false;
    }
    ord.push_back(u);
    visited[u] = 2;
    return ret;
}

int main(){
    int a, b;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    bool answ = true;
    visited.assign(n+1,0);
    for(int i=1;i<=n;i++)
        if(!visited[i])
            answ = answ && dfs(i);

    vector<int> dist(n+1,-inf), parent(n+1,-1);
    int pos = 0;
    for(pos=0;pos<n && ord[pos]!=n;pos++);
    dist[ord[pos]] = 0;
    for(pos++;pos<n;pos++){
        int u = ord[pos];
        for(auto v:adj[u])
            if(dist[u]<dist[v]+1)
                dist[u] = dist[v]+1, parent[u] = v;
    }

    int mx = 1;
    if(dist[mx]+1<0){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << dist[mx]+1 << "\n";
        for(;mx!=-1;mx = parent[mx])
            cout << mx << " ";
        cout << "\n";
    }
    return 0;

}