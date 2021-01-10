#include <bits/stdc++.h>

using namespace std;

#define maxn 200100
#define LOG 20

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m, q;
vector<pair<int, ii>> edgeList;
int parent[maxn], _rank[maxn];
int lvl[maxn], dad[maxn][LOG], maxx[maxn][LOG];
int v[maxn];
vector<pair<int, int>> adj[maxn];
set<ii> tree;
map<ii, int> mapa;

void build(){
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
}

int findSet(int u){
    return ((parent[u] == u) ? u : parent[u] = findSet(parent[u]));
}

bool isDisjoint(int u, int v){
    return findSet(u) != findSet(v);
}

void unionSet(int u, int v){
    int paiU = findSet(u), paiV = findSet(v);
    if(isDisjoint(paiU, paiV)){
        if(_rank[paiU] < _rank[paiV]) swap(paiU, paiV);
        parent[paiV] = paiU;
        if(_rank[paiU] == _rank[paiV]){
            ++_rank[paiU];
        } 
    }
}

int kruskal(){
    sort(edgeList.begin(), edgeList.end());
    build();
    int u, v, w;
    int peso = 0;
    for(auto sla:edgeList){
        w = sla.first;
        u = sla.second.first;
        v = sla.second.second;
        if(isDisjoint(u, v)){
            peso += w;
            unionSet(u, v);
            adj[u].emplace_back(ii(v, w));
            adj[v].emplace_back(ii(u, w));
            tree.insert(ii(u, v));
            tree.insert(ii(v, u));
        }
    }
    return peso;
}

void dfs(int u, int p, int h){
    lvl[u] = h;
    dad[u][0] = p;
    for(int i = 1; i < LOG; i++){
        if(dad[u][i-1] != -1){
            dad[u][i] = dad[dad[u][i-1]][i-1];
            maxx[u][i] = max(maxx[u][i-1],maxx[dad[u][i-1]][i-1]);
        }
    }
    for(auto par:adj[u]){
        if(par.first != p){
            maxx[par.first][0] = par.second;
            dfs(par.first, u, h+1);
        }
    }
}

int LCA(int u, int v){
    int maior = 0;
    if(lvl[u] < lvl[v])
        swap(u, v);
    for(int i = LOG-1; i >= 0; i--){
        if(dad[u][i] != -1 && lvl[dad[u][i]] >= lvl[v]){
            maior = max(maior,maxx[u][i]);
            u = dad[u][i];
        }       
    }
    if(u == v) return maior;
    for(int i = LOG-1; i >= 0; i--){
        if(dad[u][i] != dad[v][i]){
            maior = max({maior,maxx[u][i],maxx[v][i]});
            u = dad[u][i];
            v = dad[v][i];
        }
    }
    return max({maior, maxx[u][0], maxx[v][0]});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int u, v, w;
    cin >> n >> m;
    while(m--){
        cin >> u >> v >> w;
        edgeList.emplace_back(iii(w, ii(u, v)));
        edgeList.emplace_back(iii(w, ii(v, u)));
        mapa[ii(u, v)] = w;
        mapa[ii(v, u)] = w;
    }
    int peso = kruskal();
    memset(dad, -1, sizeof(dad));
    memset(maxx, -1, sizeof(maxx));
    dfs(1, 0, 1);
    cin >> q;
    while(q--){
        cin >> u >> v;
        if(tree.count(ii(u, v))){
            cout << peso  << "\n";
        }else{
            cout << peso+mapa[ii(u,v)]-LCA(u, v)<<'\n'; 
        }
    }
    return 0;
}