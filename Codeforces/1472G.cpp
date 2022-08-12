#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int n, m;
vector<int> adj[maxn], adjr[maxn], dist, answ[2];

void bfs(int u){
    dist.assign(n+1,-1);
    queue<int> q;
    q.push(u), dist[u] = 0;
    while(q.size()){
        u = q.front(), q.pop();
        for(auto v:adj[u]){
            if(dist[v]==-1){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
}

int solve(int u, bool flag){
    if(u==1)
        return answ[flag][u] = 0;
    if(answ[flag][u]!=-1)   
        return answ[flag][u];
    answ[flag][u] = dist[u];
    for(auto v:adj[u]){
        if(dist[v]>dist[u]){
            answ[flag][u] = min(answ[flag][u],solve(v,flag));
        }
        if(flag && dist[v]<dist[u]){
            answ[flag][u] = min(answ[flag][u],dist[v]);
        }
    }
    return answ[flag][u];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        bfs(1);
        answ[0].assign(n+1,-1);
        answ[1].assign(n+1,-1);
        for(int i=1;i<=n;i++){
            solve(i,0);
            solve(i,1);
        }

        for(int i=1;i<=n;i++)
            cout << min(answ[0][i],answ[1][i])<<" ";
        cout <<"\n";

        for(int i=0;i<=n;i++)
            adj[i].clear();
    }

    return 0;
}