#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int n, m;
vector<int> adj[maxn], visited, ciclo;

void solve(int u){
    visited[u] = 1;
    for(auto v:adj[u]){
        if(visited[v]==2){
            ciclo[u] = ciclo[u] || ciclo[v];
        }
        else if(visited[v]==1){
            ciclo[u] = 1;
        }
        else{
            solve(v);
            ciclo[u] = ciclo[u] || ciclo[v];
        }
    }
    visited[u] = 2;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    visited.assign(n+1,0);
    ciclo.assign(n+1,0);

    int answ = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            solve(i);
        }
        answ+=ciclo[i];
    }

    cout << answ <<"\n";

    return 0;
}