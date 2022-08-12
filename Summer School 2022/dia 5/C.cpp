#include <bits/stdc++.h>

using namespace std;

#define maxn int(2e5+10)
#define LOG 22
#define INF int(1e9)

typedef pair<int, int> ii;

int n;
int dist[maxn], lvl[maxn], dad[maxn][LOG], mmin[maxn][LOG], mmax[maxn][LOG];
vector<ii> adj[maxn];

void dfs(int u, int p, int h){
	lvl[u] = h;
	for(int i = 1; i < LOG; i++){
		if(dad[u][i-1] != -1){
			dad[u][i] = dad[dad[u][i-1]][i-1];
			mmin[u][i] = min(mmin[u][i-1], mmin[dad[u][i-1]][i-1]);
			mmax[u][i] = max(mmax[u][i-1], mmax[dad[u][i-1]][i-1]);
		}
	}
	for(auto [v, w]:adj[u]){
		if(v != p){
			mmin[v][0] = w;
			mmax[v][0] = w;
			dist[v] = dist[u]+w;
			dad[v][0] = u;
			dfs(v, u, h+1);
		}
	}
}

int LCA(int u, int v){
	if(lvl[v] < lvl[u]) swap(u, v);
	for(int i = LOG-1; i >= 0; i--){
		if(dad[v][i] != -1 && lvl[dad[v][i]] >= lvl[u])
			v = dad[v][i];
	}
	if(u == v) return u;
	for(int i = LOG-1; i >= 0; i--){
		if(dad[u][i] != dad[v][i]){
			u = dad[u][i];
			v = dad[v][i];
		}
	}
	return dad[u][0];

}

ii LCA2(int u, int v){
	if(lvl[v] < lvl[u]) swap(u, v);
	ii par = {INF, -1};
	for(int i = LOG-1; i >= 0; i--){
		if(dad[v][i] != -1 && lvl[dad[v][i]] >= lvl[u]){
			par.first = min(par.first, mmin[v][i]);
			par.second = max(par.second, mmax[v][i]);
			v = dad[v][i];
		}
	}
	if(u == v) return par;
	for(int i = LOG-1; i >= 0; i--){
		if(dad[u][i] != dad[v][i]){
			par.first = min({par.first, mmin[v][i], mmin[u][i]});
			par.second = max({par.second, mmax[v][i], mmax[u][i]});
			u = dad[u][i];
			v = dad[v][i];
		}
	}
	par.first = min({par.first, mmin[v][0], mmin[u][0]});
	par.second = max({par.second, mmax[v][0], mmax[u][0]});
	return par;
}

int subir(int u, int k){
	for(int i = 0; k; i++){
		if(k&1)
			u = dad[u][i];
		k >>= 1;
	}
	return u;
}

int distanciaW(int u, int v){
	return dist[u]+dist[v]-2*dist[LCA(u, v)];
}

int distancia(int u, int v){
	return lvl[u]+lvl[v]-2*lvl[LCA(u, v)];
}

int kth(int u, int v, int k){
	int lca = LCA(u, v);
	int d = distancia(u, lca);
	if(k <= d){
		u = subir(u, k);
		return u;
	}
	k -= d;
	d = distancia(v, lca);
	return subir(v, d-k);
}

ii mM(int u, int v){
	return LCA2(u, v);
}

int main(){
    int m;
    cin >> n >> m;

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, 1);
        adj[v].emplace_back(u, 1);
    }

    memset(dad,-1,sizeof(dad));
    dfs(1,-1,0);
    
    while(m--){
        int k;
        vector<pair<int,int>> arr;

        cin >> k;
        for(int i=0;i<k;i++){
            int x;
            cin >> x;
            arr.push_back({lvl[x],x});
        }

        sort(arr.begin(),arr.end());
        vector<int> lcas;   
        bool ok = true;
        for(int i=0,j=0;i<arr.size();i=j){
            int x = ((arr[i].second==1) ? 1 : dad[arr[i].second][0]);
            while(j<arr.size() && arr[i].first==arr[j].first) x = LCA(x,arr[j].second), j++;
            ok = (ok && (lvl[arr[i].second]-lvl[x]) <=1);
            lcas.push_back(x);
        }

        for(int i=0;i+1<lcas.size();i++){
            ok = (ok && (LCA(lcas[i],lcas[i+1])==lcas[i]));
        }
        cout << ((ok) ? "YES" : "NO") <<"\n";
  
    }
		
	return 0;
}

