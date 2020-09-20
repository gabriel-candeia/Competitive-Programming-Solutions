#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int n, x, y, q;
vector<int> ord, start, qtd;
vector<vector<int>> adj;

int dfs(int u){
    ord.push_back(u);
    start[u] = (ord.size()-1);

    for(auto v:adj[u])
        qtd[u] += dfs(v);

    return qtd[u];
}

int main(){
    fastio();
    cin >> n >> q;

    adj.assign(n+1,vector<int>()); qtd.assign(n+1,1); start.assign(n+1,0);
    for(int i=2;i<=n;i++){
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1);
    
    while(q--){
        cin >> x >> y;
        if(qtd[x]>=y)
            cout << ord[start[x]+y-1] << '\n';
        else
            cout << -1 <<'\n';
    }

    return 0;
}