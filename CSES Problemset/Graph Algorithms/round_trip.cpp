#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int n, m, parent[maxn], ht[maxn], a, b;
vector<int> adj[maxn];

bool dfs(int u, int c){
    bool ret = false;
    parent[u] = c, ht[u] = ht[c] +1;
    for(auto v:adj[u]){
        if(parent[v]==-1)
            ret = (ret || dfs(v,u));
        else if(v!=parent[u]) 
            ret = true, a = u, b = v;
    }

    return ret;
}

int main(){
    cin >> n >> m;
    for(int i=0,x,y;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(parent,-1,sizeof(parent));
    bool answ = false;
    for(int i=1;i<=n;i++)
        if(parent[i]==-1)
            answ = answ || dfs(i,0);

    if(answ){
        vector<int> cycle; 
        if(ht[a]>ht[b]) swap(a,b);
        cycle.push_back(a);
        while(b!=parent[a]){
            cycle.push_back(b), b = parent[b];
        }
        
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