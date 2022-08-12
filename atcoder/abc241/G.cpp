#include<bits/stdc++.h>
#define maxn 5050
using namespace std;

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

	vector<node> edges;
	vector<int> g[maxn];
	ll dist[maxn], ptr[maxn];

    void clear(){
        for(auto e:edges){
            g[e.v].clear();
        }
        edges.clear();
    }

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
    int n, m, maximo;
    vector<int> maxwins, winners;
    vector<vector<int>> games;
    
    cin >> n >> m;
    maximo = (n*(n-1))/2;
    games.assign(n+1,vector<int>(n+1,0));
    maxwins.assign(n+1,n);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        maxwins[b]--;
        games[a][b] = a;
        games[b][a] = a;
    }
    int answ = 0;
    for(int u=1;u<=n;u++){
        int mx = maxwins[u];
        dinic::clear();

        int cnt = n+1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                dinic::addEdge(0,cnt,1);
                if(games[i][j]==0){
                    dinic::addEdge(cnt,i,1);
                    dinic::addEdge(cnt,j,1);
                }
                else{
                    dinic::addEdge(cnt,games[i][j],1);
                }
                cnt++;
            }
        }

        for(int i=1;i<=n;i++){
            dinic::addEdge(i,cnt,(mx-1-(i!=u)));
        }
        int x = dinic::maxflow(0,cnt);
        //cout << x << " "<< u << " " << mx <<"\n";
        if((x==maximo)){
            winners.push_back(u);
        }
    }

    for(auto x:winners)
        cout << x << " ";
    cout<<"\n";
    
    return 0;
}