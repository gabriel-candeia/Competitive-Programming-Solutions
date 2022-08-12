#include <bits/stdc++.h>
using namespace std;
#define maxn int(3e5+10)
#define ll long long
#define LOG 23

int parent[maxn][LOG], ht[maxn], topo[maxn];

int lift(int u, int x){
    for(int k=LOG-1;k>=0;k--){
        if((1<<k)<=x && parent[u][k]){
            u = parent[u][k];
            x -= (1<<k);
        }
    }
    return u;
}

int lca(int u, int v){
    if(ht[v]>ht[u]) swap(u,v);
    u = lift(u,ht[u]-ht[v]);
    if(u==v) return u;
    for(int k=LOG-1;k>=0;k--){
        if(parent[u][k]!=parent[v][k]){
            u = parent[u][k];
            v = parent[v][k];
        }
    }
    return parent[u][0];
}

int main(){
    vector<int> mapa(maxn,0);
    int q, iter = 0;
    cin >> q;
    
    memset(parent,-1,sizeof(parent));
    int cnt = 0;
    while(q--){
        iter++;
        char op;
        cin >> op;
        if(op=='a'){
            int p;
            cin >> p;
            mapa[iter] = ++cnt;

            int u = mapa[iter];
            p = mapa[p];
            topo[u] = iter;

            parent[u][0] = p;
            ht[u] = ht[parent[u][0]]+1;
            for(int k=1;k<LOG;k++)
                if(parent[u][k-1]!=-1)
                    parent[u][k] = parent[parent[u][k-1]][k-1];
        }
        else if(op=='b'){
            int p;
            cin >> p;
            mapa[iter] = parent[mapa[p]][0];
            cout << topo[mapa[p]] <<"\n";
        }
        else{
            int v, w;
            cin >> v >> w;

            mapa[iter] = mapa[v];
            v = mapa[v], w = mapa[w];
                        
            cout << ht[lca(v,w)] <<"\n";
        }   
    }

	return 0;
}
