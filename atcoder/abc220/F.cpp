#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

vector<int> adj[maxn];
ll dist[maxn], answ[maxn], filhos[maxn];

void base(int u, int p){
    filhos[u] = 1;
    for(auto v:adj[u]){
        if(v!=p){
            base(v,u);
            dist[u] += dist[v]+filhos[v];
            filhos[u]+=filhos[v];
        }
    }
}

void solve(int u, int p){
    answ[u] = dist[u];

    for(auto v:adj[u]){
        if(v!=p){
            dist[u]-= (dist[v]+filhos[v]);
            filhos[u] -= filhos[v];
            dist[v] += dist[u]+filhos[u];
            filhos[v]+=filhos[u];
            solve(v,u);
            swap(u,v);
            dist[u]-= (dist[v]+filhos[v]);
            filhos[u] -= filhos[v];
            dist[v] += dist[u]+filhos[u];
            filhos[v]+=filhos[u];
            swap(u,v);
        }
    }
}


int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    base(1,-1);
    solve(1,-1);
    for(int i=1;i<=n;i++){
        cout <<answ[i] <<"\n";
    }

    return 0;
}