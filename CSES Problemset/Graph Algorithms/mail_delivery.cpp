#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

multiset<int> adj[maxn];
vector<int> answ;
int visited[maxn];

int connected(int u){
    int qtd = 1;
    visited[u] = 1;
    for(auto v:adj[u]){
        if(!visited[v]){
            qtd+=connected(v);
        }
    }
    return qtd;
}

void solve(int u){
    while(adj[u].size()){
        int v = (*adj[u].begin());
        adj[u].erase(adj[u].begin());
        adj[v].erase(adj[v].find(u));
        solve(v);
    }
    answ.push_back(u);
}

int main(){
    int n, m, cnt=0;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    int u = 1;
    for(int i=1;i<=n;i++){
        cnt += (adj[i].size()!=0);
    }
    
    bool ok = (connected(u)==cnt);
    for(int i=1;i<=n;i++){
        ok = (ok && (adj[i].size()%2==0));
    }

    if(ok){
        solve(u);
        for(auto x:answ)
            cout << x << " ";
        cout<<"\n";
    }
    else{
        cout <<"IMPOSSIBLE" <<"\n";
    }

    return 0;
}