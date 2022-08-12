#include<bits/stdc++.h>
#define maxn int(5e3+5)
#define inf 0x3f3f3f3f
#define sz(x) x.size()
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;

namespace dinic{
	struct node{
		int v, c;

		node(){}

		node(int v, int c){
			this->v = v;
			this->c = c;
		}
	};

	vector <node> edges;
	vector <int> g[maxn];
	vector<int> dist, ptr;

	void add(int u, int v, int c){
		edges.push_back(node(v, c));
		g[u].push_back(sz(edges)-1);
		edges.push_back(node(u, 0));
		g[v].push_back(sz(edges)-1);  
	}

	//Escolhendo o caminho
	bool bfs(int s, int t){
		queue <int> q;
        dist.assign(maxn,inf);
		dist[s] = 0;
		q.push(s);
		while(!q.empty()){
			int u = q.front();
            
			q.pop();
			for(auto e : g[u]){
				if(dist[edges[e].v] == inf and edges[e].c> 0){
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
		for(int &i = ptr[s]; i < sz(g[s]); i++){
			int e = g[s][i];
			if(dist[edges[e].v] == dist[s]+1 && edges[e].c > 0){
				if(int x = dfs(edges[e].v, t, min(f, edges[e].c))){
					edges[e].c -= x; 
					edges[e^1].c += x;
					return x;
				}
			}
		}
		return 0;
	}

	ll Dinic(int s, int t){
		ll maxFlow = 0;
		while(bfs(s, t)){
            ptr.assign(maxn,0);
			while(ll flow = dfs(s, t, inf))
				maxFlow += flow;
		}
		return maxFlow;
	}
}

int main(){
    int n, m, s, t;

    cin >> n >> m >> s >> t;
    for(int i=1;i<=n;i++){
        dinic::add(i,i+n,1);
    }

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        dinic::add(a+n,b,inf);
        dinic::add(b+n,a,inf);
    }

    cout << dinic::Dinic(s+n,t) <<"\n";
    
    return 0;
}