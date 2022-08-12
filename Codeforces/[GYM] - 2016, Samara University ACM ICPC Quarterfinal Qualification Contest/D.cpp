#include<bits/stdc++.h>
#define maxn 5050
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
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

int n, m, r, c, sft;
int mat[100][100];

int cvt(int i, int j){
    return i*m+j;
}

int main(){
    
    cin >> n >> m >> r >> c;
    r--,c--;

    sft = n*m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    
    int target = n*m-1 + sft + 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i+1<n){
                dinic::addEdge(cvt(i,j)+sft,cvt(i+1,j),inf);
                dinic::addEdge(cvt(i+1,j)+sft,cvt(i,j),inf);
            }
            if(j+1<m){
                dinic::addEdge(cvt(i,j)+sft,cvt(i,j+1),inf);
                dinic::addEdge(cvt(i,j+1)+sft,cvt(i,j),inf);
            }
            dinic::addEdge(cvt(i,j),cvt(i,j)+sft,mat[i][j]);
        }
    }
    dinic::addEdge(cvt(r,c),cvt(r,c)+sft,mat[r][c]);


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                dinic::addEdge(cvt(i,j)+sft,target,inf);
            }
        }
    }
    
    cout << dinic::maxflow(cvt(r,c)+sft,target) << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dinic::dist[cvt(i,j)]!=inf && dinic::dist[cvt(i,j)+sft]==inf ){
                cout << "X";
            }
            else{
                cout << ".";
            }
        }
        cout <<"\n";
    }


    return 0;
}