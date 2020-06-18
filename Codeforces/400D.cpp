#include<bits/stdc++.h>
#define N 1000
#define INF 1e8
using namespace std;

class DSU{
    private:
        vector<int> parent, rank;
    public:
        DSU(int n){
            parent.assign(n,0);
            rank.assign(n,0);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            return ((parent[x]==x) ? x : parent[x] = find(parent[x]));
        }

        void _union(int x,int y){
            x = find(x);
            y = find(y);
            if(x!=y){
                if(rank[x] > rank[y]){
                    parent[y] = x;
                }
                else{
                    parent[x] = y;
                    rank[y] += (rank[x]==rank[y]);
                }
            }
        }

        bool isSameSet(int x, int y){
            return find(x)==find(y);
        }
};

void dijkstra(int mat[N][N], int i, int n){
    vector<int> dist(n,INF);
    pair<int,int> p;
    int u, d;
    priority_queue<pair<int,int>> h;
    h.push({0,i});
    while(h.size()){
        p = h.top(); h.pop();
        
        d = p.first;
        u = p.second;

         for(int v=0;v<n;v++){
             if(d+mat[u][v] < dist[v]){
                 h.push({d+mat[u][v],v});
                 dist[v] = d+mat[u][v];
             }
         }
    }
    for(int j=0;j<n;j++){
        mat[i][j] = dist[j];
    }
}

int main(){
    int n, m, k;
    int u=0, v=0, w=0;
    vector<int> c, color;
    int mat[N][N];  
    
    cin >> n >> m >> k;
    DSU alg(n+2);
    c.assign(k+2,0);
    color.assign(n+2,0);

    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            mat[i][j] = INF*(i!=j);
            mat[j][i] = INF*(i!=j);
        }
    }

    for(int i=1;i<=k;i++){
        cin >> c[i];
        c[i] += u;
        u = c[i];
    }

    int ptr = 1;
    for(int i=1;i<=n;i++){
        if(i>c[ptr]){
            ptr++;
            color[i] = color[i-1]+1;
        }
        color[i] = color[c[ptr-1]+1];
    }


    for(int i=0;i<m;i++){
        cin >> u >> v >> w;
        if(w==0){
            alg._union(u,v);
        }
        u = color[u];
        v = color[v];
        mat[u][v] = min(mat[u][v],w);
        mat[v][u] = min(mat[v][u],w);
    }
    
    bool poss = true;
    ptr = 1;
    for(int i=1;i<=n;i++){
        if(i>c[ptr]){
            ptr++;
        }
        if(alg.isSameSet(i,c[ptr-1]+1)==false){
            poss = false;
        }
    }

    if(!poss){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for(int i=0;i<k;i++){
        dijkstra(mat,i, k);
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(mat[i][j]>=INF){
                mat[i][j] = -1;
            }
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}