#include<bits/stdc++.h>
#define maxn int(2e3+5)
#define ll long long
using namespace std;

vector<int> adj[maxn], visited;
int dfs(int u){
    visited[u] = true;
    int acm = 1;
    for(auto v:adj[u])
        if(!visited[v])
            acm += dfs(v);
    return acm;
}

int main(){
    int n, m;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    ll answ = 0, x =0;
    for(int i=1;i<=n;i++){
        visited.assign(n+1,0);
        answ += dfs(i);
    }

    cout << answ <<'\n';

    return 0;
}