#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

#define maxn int(2e4+5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
const ll inf = 0x3f3f3f3f;

namespace dinic{
	struct node{
		int v, f, c;

		node(){}

		node(int v, int f, int c){
			this->v = v;
			this->f = f;
			this->c = c;
		}
	};

	vector <node> edges;
	vector <int> g[maxn];
	int dist[maxn], ptr[maxn];

	void addEdge(int u, int v, int c){
		edges.push_back(node(v, 0, c));
		g[u].push_back(edges.size()-1);
		edges.push_back(node(u, 0, 0));
		g[v].push_back(edges.size()-1);
	}

	//Escolhendo o caminho
	bool bfs(int s, int t){
		queue <int> q;
		memset(dist, inf, sizeof dist);
		dist[s] = 0;
		q.push(s);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(auto e : g[u]){
				if(dist[edges[e].v] == inf and edges[e].c-edges[e].f > 0){
					dist[edges[e].v] = 1+dist[u];
					q.push(edges[e].v);
				}
			}
		}
		return dist[t] != inf;
	}

	ll dfs(int s, int t, int f){
		if(s == t)
			return f;
		for(int &i = ptr[s]; i < g[s].size(); i++){
			int e = g[s][i];
			if(dist[edges[e].v] == dist[s]+1 and edges[e].c-edges[e].f > 0){
				if(int x = dfs(edges[e].v, t, min(f, edges[e].c-edges[e].f))){
					edges[e].f += x;
					edges[e^1].f -= x;
					return x;
				}
			}
		}
		return 0;
	}

	ll maxflow(int s, int t){
		ll maxFlow = 0;
		while(bfs(s, t)){
			memset(ptr, 0, sizeof ptr);
			while(ll flow = dfs(s, t, inf))
				maxFlow += flow;
		}
		return maxFlow;
	}
}

int main(){
    fastio();
    int n, m, k;

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        dinic::addEdge(0,i,1);
        int k, v;
        cin >> k;
        while(k--){
            cin >> v;
            dinic::addEdge(i,n+v,1);
        }
    }

    for(int i=1;i<=m;i++){
        dinic::addEdge(n+i,n+m+1,1);
    }

    int f = dinic::maxflow(0,n+m+1);

    cout << m-f <<"\n";

    return 0;
}