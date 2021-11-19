#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int n, m, visited[maxn], parent[maxn], a, b;
vector<int> adj[maxn];

bool dfs(int u, int c){
    bool ret = false;
    visited[u] = 1, parent[u] = c;
    for(auto v:adj[u]){
        if(visited[v]==0)
            ret = (ret || dfs(v,u));
        else if(visited[v]==1)
            ret = true, a = v, b = u;
    }
    visited[u] = 2;

    return ret;
}

int main(){
    cin >> n >> m;
    for(int i=0,x,y;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
    }

    memset(parent,-1,sizeof(parent));
    bool answ = false;
    for(int i=1;i<=n;i++)
        if(parent[i]==-1)
            answ = answ || dfs(i,0);

    if(answ){
        vector<int> cycle; 
        cycle.push_back(a);
        while(b!=parent[a])
            cycle.push_back(b), b = parent[b];
        
        reverse(cycle.begin(),cycle.end());
        cout << cycle.size() << "\n";
        for(auto x:cycle)
            cout << x << " ";
        cout<<'\n';
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}