#include<bits/stdc++.h>
#define maxn 105
using namespace std;
typedef long long ll;

const ll inf =  1e18;

struct Dinic{
	struct edge{
		int u, v;
		ll c;

		edge(){}

		edge(int u, int v, ll c){
            this->u = u;
			this->v = v;
			this->c = c;
		}
	};

	vector<edge> edges;
	vector<vector<int>> adj;
	vector<int> dist, ptr;
    int source, target;

    Dinic(){}

    Dinic(int n){
        adj.assign(n+1,vector<int>());
        dist.assign(n+1,0);
        ptr.assign(n+1,0);
    }

	void addEdge(int u, int v, ll c){
		edges.push_back(edge(u, v, c));
		adj[u].push_back(edges.size()-1);
		edges.push_back(edge(v, u, 0));
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

	ll maxflow(){
		ll answ = 0;
		while(bfs(source, target)){
			ptr.assign(ptr.size(),0);
			while(ll flow = dfs(source, target, inf))
				answ += flow;
		}
		return answ;
	}

    vector<pair<int,int>> bipartiteMatching(){
        vector<pair<int,int>> answ;
        for(int i=0;i<edges.size();i+=2){
            auto e = edges[i];
            if(e.c==0 && e.u!=source && e.v!=target){
                answ.push_back({e.u,e.v});
            }
        }
        return answ;
    }
};

vector<int> adj[maxn], dg;

int main(){
    int n, m;
    
    cin >> n >> m;

    Dinic alg(2*n+1);
    alg.source = 0, alg.target = 2*n+1;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        alg.addEdge(a,b+n,1);
    }

    for(int i=1;i<=n;i++){
        alg.addEdge(alg.source,i,1);
        alg.addEdge(i+n,alg.target,1);
    }

    int sz = alg.maxflow();
    vector<pair<int,int>> matchedEdges = alg.bipartiteMatching();

    dg.assign(n+1,0);
    for(auto [u,v]:matchedEdges){
        adj[u].push_back(v-n);
        dg[v-n]++;
    }

    cout << n-sz <<"\n";
    for(int i=1;i<=n;i++){
        if(dg[i]==0){
            int curr = i;
            while(adj[curr].size()){
                cout << curr << " ";
                curr = adj[curr][0];
            }
            cout << curr <<"\n";
        }
    }

    return 0;
}