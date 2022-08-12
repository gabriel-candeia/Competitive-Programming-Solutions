#include<bits/stdc++.h>
#define maxn int(1e4+5)
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

int grid[501][501], mp[501][501], cnt = 2;

int main(){
    int t;
    cin >> t;
    while(t--){
        cnt = 2;
        int n, m;
        cin >> n;
        m = n;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> grid[i][j];
                mp[i][j] = ++cnt;
            }
        }

        auto isok = [n, m](int x, int y){
            return x>=0 && y>=0 && x<n && y<m;
        };

        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

        bool ok = true;
        vector<int> marca(100,0);
        for(int k=10;k>1;k--){
            int expected = 0;    
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==k-1){
                        dinic::add(mp[i][j],2,1);
                    }
                    if(grid[i][j]==k){
                        expected++;
                        dinic::add(1,mp[i][j],1);
                        if(grid[i][j]==1)
                            dinic::add(mp[i][j],2,1);
                        for(int k=0;k<4;k++){
                            int ni = i + dx[k], nj = j + dy[k];
                            if(isok(ni,nj) && grid[ni][nj]+1==grid[i][j])
                                dinic::add(mp[i][j],mp[ni][nj],1);
                        }
                    }
                }
            }
            
            int f = dinic::Dinic(1,2);
            if(f!=expected){
                ok = false;
                break;
            }
            for(int i=0;i<=cnt;i++)
                dinic::g[i].clear();    
            dinic::edges.clear();
        }
        
        cout << ((ok) ? "YES" : "NO") <<"\n";
    }

    return 0;
}