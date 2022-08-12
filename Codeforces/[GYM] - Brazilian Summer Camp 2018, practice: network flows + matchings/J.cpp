#include<bits/stdc++.h>
#define maxn int(100)
using namespace std;

typedef long long ll;

const ll inf =  1e18;

struct Dinic{
	struct edge{
		int v;
		ll c;

		edge(){}

		edge(int v, ll c){
			this->v = v;
			this->c = c;
		}
	};

	vector<edge> edges;
	vector<vector<int>> adj;
	vector<int> dist, ptr;

    Dinic(){}

    Dinic(int n){
        adj.assign(n+1,vector<int>());
        dist.assign(n+1,0);
        ptr.assign(n+1,0);
    }

	void addEdge(int u, int v, ll c){
		edges.push_back(edge(v, c));
		adj[u].push_back(edges.size()-1);
		edges.push_back(edge(u, 0));
		adj[v].push_back(edges.size()-1);
	}

	bool bfs(int s, int t){
		queue<int> q;
		dist.assign(dist.size(),-1);
		dist[s] = 0;
		q.push(s);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(auto e : adj[u]){
				if(dist[edges[e].v] == -1 && edges[e].c > 0){
					dist[edges[e].v] = 1+dist[u];
					q.push(edges[e].v);
				}
			}
		}
		return dist[t] != -1;
	}

	ll dfs(int s, int t, ll f){
		if(s == t)
			return f;
		for(int &i = ptr[s]; i < adj[s].size(); i++){
			int e = adj[s][i];
			if(dist[edges[e].v] == dist[s]+1 and edges[e].c > 0){
				if(ll x = dfs(edges[e].v, t, min(f, edges[e].c))){
					edges[e].c -= x;
					edges[e^1].c += x;
					return x;
				}
			}
		}
		return 0;
	}

	ll maxflow(int s, int t){
		ll answ = 0;
		while(bfs(s, t)){
			ptr.assign(ptr.size(),0);
			while(ll flow = dfs(s, t, inf))
				answ += flow;
		}
		return answ;
	}
};

int n, m;
char mat[maxn][maxn];

int entrada(int i, int j){
    return i*m+j;
}

int saida(int i, int j){
    return i*m+j + n*m;
}

int main(){

    cin >> n >> m;
    memset(mat,'-',sizeof(mat));
    int k, l;
    cin >> k >> l;
    for(int i=0;i<k;i++){
        int a, b;
        cin >> a >> b;
        mat[a-1][b-1] = '#';
    }

    for(int i=0;i<l;i++){
        int a, b;
        cin >> a >> b;
        mat[a-1][b-1] = '.';
    }

    int x, y;
    cin >> x >> y;
    mat[x-1][y-1] = 'A';
    cin >> x >> y;
    mat[x-1][y-1] = 'B';

    Dinic alg(2*n*m);

    int s, t;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='#') continue;
            if(mat[i][j]=='A') s = entrada(i,j);
            if(mat[i][j]=='B') t = saida(i,j);
            if(i!=n-1 && mat[i+1][j]!='#'){
                alg.addEdge(saida(i,j),entrada(i+1,j),inf);
                alg.addEdge(saida(i+1,j),entrada(i,j),inf);
            }
            if(j!=m-1 && mat[i][j+1]!='#'){
                alg.addEdge(saida(i,j),entrada(i,j+1),inf);
                alg.addEdge(saida(i,j+1),entrada(i,j),inf);
            }
            alg.addEdge(entrada(i,j),saida(i,j),((mat[i][j]=='.') ? 1 : inf));
        }
    }

    ll cut = alg.maxflow(s,t);

    if(cut==inf) cut = -1;

    cout << cut <<"\n";

    if(cut!=-1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='.' && alg.dist[entrada(i,j)]!=-1 && alg.dist[saida(i,j)]==-1){
                    cout << i+1 << " " << j+1 <<"\n";
                }   
            }
        }

    return 0;
    }
}