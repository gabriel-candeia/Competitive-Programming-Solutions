#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

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

    if(answ==true){
        reverse(ord.begin(),ord.end());
        for(auto x:ord)
            cout << x << " ";
        cout << "\n";
    }
    else{
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}