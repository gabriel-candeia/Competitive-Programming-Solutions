#include<bits/stdc++.h>
#define maxn int(100)
using namespace std;

typedef long long ll;

const ll inf =  0x3f3f3f3f3f3f3f3f;

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

	bool ok(int source, int target){
	    bool answ = 1;
	    for(auto e:edges){
            if(e.u==source){
                answ = answ && (e.c==0);
                /*if(e.c!=0){
                    cout << e.v << " " << e.c << "\n";
                }*/
            }
            if(e.v==target){
                answ = answ && (e.c==0);
                /*if(e.c!=0){
                    cout << e.u << " " << e.c << "\n";
                }*/
            }
	    }
	    return answ;
	}
};

int n, m;
char mat[maxn][maxn];

int get(int i, int j){
    return ((mat[i][j]=='H') ? 1 : (mat[i][j]=='O') ? 2 : (mat[i][j]=='N') ? 3 : 4);
}

int conv(int i, int j){
    return i*m+j;
}

int main(){
    int qtd = 0;
    cin >> n >> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j], (qtd += mat[i][j]!='.');

    Dinic alg(n*m+1);
    int source = n*m, target = n*m+1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='.') continue;
            if(i!=n-1 && mat[i+1][j]!='.'){
                int a = conv(i,j), b = conv(i+1,j);
                if((i^j)&1) swap(a,b);
                alg.addEdge(a,b,1);

            }
            if(j!=m-1 && mat[i][j+1]!='.'){
                int a = conv(i,j), b = conv(i,j+1);
                if((i^j)&1) swap(a,b);
                alg.addEdge(a,b,1);
            }
            if((i^j)&1)  alg.addEdge(conv(i,j),target,get(i,j));
            else  alg.addEdge(source,conv(i,j),get(i,j));
        }
    }


    alg.maxflow(source,target);
    cout << ((alg.ok(source,target) && qtd!=0) ? "Valid" : "Invalid") <<"\n";
    return 0;
}