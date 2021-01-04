#include<bits/stdc++.h>
#define maxn int(1e5)
#define ll long long
using namespace std;

ll n, m, k;
vector<ll> adj[maxn];

ll bfs(int t, int s){
    vector<int> visited(n+1,-1), modv(k,false);
    queue<int> q;
    int u;
    q.push(t); visited[t] = 0;
    while(q.size()){
        u = q.front(); q.pop();

        for(int v=u%k;modv[u%k]==false && v<=n;v+=k){
            if(visited[v]!=-1) continue;
            q.push(v);
            visited[v] = visited[u]+1;
        }
        modv[u%k] = true;

        for(auto v:adj[u]){
            if(visited[v]==-1){
                q.push(v);
                visited[v] = visited[u]+1;
            }
        }
    }

    return visited[s];
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int x, y;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
    }
    cin >> x >> y;
    cout << bfs(x,y) <<'\n';
    return 0;
}
