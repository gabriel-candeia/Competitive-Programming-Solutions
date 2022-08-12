#include<bits/stdc++.h>
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

int main(){
    int n, m;
    cin >> n >> m;

    Dinic alg(n+m+1);
    for(int i=1;i<=n;i++){
        while(true){
            int b;
            cin >> b;
            if(b==0) break;
            alg.addEdge(i,b+n,1);
        }
    }

    int source = 0, target = n+m+1;
    for(int i=1;i<=n;i++){
        alg.addEdge(source,i,1);
    }

    for(int i=1;i<=m;i++){
        alg.addEdge(i+n,target,1);
    }

    cout << alg.maxflow(0,n+m+1) << "\n";

    for(int i=0;i<alg.edges.size();i+=2){
        if(alg.edges[i].c==0 && alg.edges[i].u!=source && alg.edges[i].v!=target){
            cout << alg.edges[i].u << " " << alg.edges[i].v-n <<"\n";
        }
    }

    return 0;
}