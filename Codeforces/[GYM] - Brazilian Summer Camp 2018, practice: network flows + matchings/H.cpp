#include<bits/stdc++.h>
#define maxn int(100)
using namespace std;

typedef long long ll;

const ll inf =  0x3f3f3f3f3f3f3f3f;

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
    vector<pair<int,int>> edges;

    cin >> n >> m;

    Dinic alg(n);
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        alg.addEdge(a,b,c);
        alg.addEdge(b,a,c);
        edges.push_back({a,b});
    }

    ll cut = alg.maxflow(1,n);


    vector<int> answ;
    for(int i=0;i<edges.size();i++){
        int u, v;
        tie(u,v) = edges[i];
        if((alg.dist[u]!=-1 && alg.dist[v]==-1) || (alg.dist[u]==-1 && alg.dist[v]!=-1)){
            answ.push_back(i);
        }
    }

    cout << answ.size() << " " << cut <<"\n";
    for(auto x:answ)
        cout << x+1 << " ";
    cout<<"\n";

    return 0;
}
 