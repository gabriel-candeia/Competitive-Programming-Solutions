#include<bits/stdc++.h>
#define maxn 100
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

int mat[maxn][maxn], n, p;

int conv(int i, int j){
    return i*n + j;
}

int main(){    
    cin >> n >> p;

    Dinic alg(n*n+2);
    for(int i=0;i<p;i++){
        int a, b;
        cin >> a >> b; a--, b--;
        mat[a][b] = 1;
    }

    int source = n*n+1, target = n*n+2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1) continue;
            if(i!=n-1 && mat[i+1][j]!=1){
                int a = conv(i,j), b = conv(i+1,j);
                if((i^j)&1) swap(a,b);
                alg.addEdge(a,b,1);
            }
            if(j!=n-1 && mat[i][j+1]!=1){
                int a = conv(i,j), b = conv(i,j+1);
                if((i^j)&1) swap(a,b);
                alg.addEdge(a,b,1);
            }
            if((i^j)&1) alg.addEdge(conv(i,j),target,1);
            else alg.addEdge(source,conv(i,j),1);
        }
    }

    int answ = alg.maxflow(source,target);
    
    if(2*answ==n*n-p){
        cout << "Yes" <<"\n";
        vector<int> vertical, horizontal;
        for(int i=0;i<alg.edges.size();i+=2){
            if(alg.edges[i].c==0 && alg.edges[i].u!=source && alg.edges[i].v!=target){
                if(abs(alg.edges[i].u-alg.edges[i].v)==1){
                    horizontal.push_back(min(alg.edges[i].u,alg.edges[i].v));
                }
                else{
                    vertical.push_back(min(alg.edges[i].u,alg.edges[i].v));
                }
                
            }
        }

        cout << vertical.size() << "\n";
        for(auto x:vertical){
            cout << x/n+1 << " " << x%n+1<<"\n";
        }

        cout << horizontal.size() << "\n";
        for(auto x:horizontal){
            cout << x/n+1 << " " << x%n+1<<"\n";
        }
    }
    else{
        cout << "No" <<"\n";
    }

    return 0;
}