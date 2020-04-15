#include<bits/stdc++.h>
#define ll long long
using namespace std;

class DSU{
    private:
        vector<ll> rank, parent;
    public:
        DSU(int n){
            rank.assign(n,0);
            parent.assign(n,0);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            return ((parent[x]==x) ? x : (parent[x] = find(parent[x])));
        }

        void _union(int x, int y){
            x = find(x);
            y = find(y);
            if(x!=y){
                if(rank[x]>rank[y]){
                    parent[y] = x;
                }
                else{
                    parent[x] = y;
                    rank[y] += (rank[x]==rank[y]);
                }
            }
        }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d, x, y;
    int v;
    cin >> n >> m >> d;
    queue<int> bfs;

    vector<vector<ll>> adj(n);
    vector<bool> visited(n,false);
    DSU aux(n);
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
        if(x!=1 && y!=1){
            aux._union(x-1,y-1);
        }
    }

    for(auto u : adj[0]){
        if(aux.find(u)!=aux.find(0)){
            aux._union(u,0);
            bfs.push(u);
            visited[u] = true;
        }
    }

    for(auto u : adj[0]){
        if(bfs.size()<d && !visited[u]){
            bfs.push(u);
        }
        visited[u] = false;
    }

    if(bfs.size()!=d){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    while(!visited[bfs.front()]){
        v = bfs.front(); bfs.pop();
        cout << 1 << " " <<  v+1 << '\n';
        visited[v] = true;
        bfs.push(v);
    }

    visited[0] = true;
    while(bfs.size()){
        v = bfs.front(); bfs.pop();
        for(auto w : adj[v]){
            if(!visited[w]){
                visited[w] = true;
                bfs.push(w);
                cout << v+1 << " " << w+1 << '\n';
            }
        }
    }

    return 0;
}

