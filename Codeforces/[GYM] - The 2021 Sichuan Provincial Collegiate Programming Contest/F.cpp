#include <bits/stdc++.h>

using namespace std;

#define pair <int, int> ii

#define MAXN 1100
#define inf 0x3f3f3f3f
struct node{
	int v, f, c, val;
	node(){}
	node(int _v, int _f, int _c, int _val){
		v = _v, f = _f, c = _c, val = _val;
	}
};

int v;
vector<node> edges;
vector<int> graph[MAXN];
int dist[MAXN], ptr[MAXN], pai[MAXN];

void add(int u, int v, int c, int val){
	edges.pb(node(v, 0, c, val));
	graph[u].pb(edges.size()-1);
	edges.pb(node(u, 0, 0, -val));
	graph[v].pb(edges.size()-1);
}

ii operator+(ii a, ii b){
	a.fst += b.fst;
	a.snd += b.snd;
	return a;
}

bool dijkstra(int s, int t){
	for(int i = 0; i < v; i++){
		dist[i] = inf;
		pai[i] = -1;
	}
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> q;
	q.push(ii(0, s));
	
	while(!q.empty()){
		int d = q.top().fst, u = q.top().snd;
		q.pop();
		
		if(d > dist[u])
			continue;
		
		for(auto e : graph[u]){
			if(dist[u] + edges[e].val < dist[edges[e].v] && edges[e].c-edges[e].f > 0){
				dist[edges[e].v] = dist[u] + edges[e].val;
				pai[edges[e].v] = u;
				q.push({dist[edges[e].v], edges[e].v});
			}
		}
	}
	
	return dist[t] != inf;
}

ii dfs(int s, int t, int f){
	if(s == t)
		return ii(0, f);
	
	for(int &i = ptr[s]; i < graph[s].size(); i++){
		int e = graph[s][i];
		if(pai[edges[e].v] == s && dist[edges[e].v] == dist[s] + edges[e].val && edges[e].c-edges[e].f > 0){
			ii x = ii(edges[e].val, 0) + dfs(edges[e].v, t, min(f, edges[e].c-edges[e].f));
			if(x.snd){
				edges[e].f += x.snd;
				edges[e^1].f -= x.snd;
				return x;
			}
		}
	}
	
	return ii(0, 0);
}

ii get(int s, int t){
	ii ans(0, 0);
	while(dijkstra(s, t)){
		memset(ptr, 0, sizeof ptr);
		ii x;
		while((x = dfs(s, t, inf)).snd)
			ans = ans + x;
	}
	return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

    }
    return 0;
}