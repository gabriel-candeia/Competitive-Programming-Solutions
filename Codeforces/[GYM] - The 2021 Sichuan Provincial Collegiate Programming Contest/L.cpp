#include <bits/stdc++.h>

using namespace std;
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'

typedef pair <int, int> ii;
typedef long long ll;

#define maxn 101010

vector <int> g[maxn], spicy;
int dist[maxn][101];

void bfs(int s, vector <int> go){
	queue <int> q;
	for(auto i : go){
		dist[i][s] = 0;
		q.push(i);
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : g[u])
			if(dist[v][s] == 0x3f3f3f3f)
				dist[v][s] = 1+dist[u][s], q.push(v);
	}
}

int main(){
    fastio();
    int n, m, q;
    cin >> n >> m >> q;
    spicy.resize(n);
    for(auto &i : spicy)
        cin >> i;
    int lim = *max_element(all(spicy));
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dist, 0x3f3f3f3f, sizeof dist);
    for(int i = 1; i <= lim; i++){
        vector <int> go;
        for(int j = 0; j < sz(spicy); j++)
            if(spicy[j] == i)
                go.push_back(j+1);
        bfs(i, go);
    }
   	for(int i = 1; i <= n; i++)
			for(int j = 1; j <= lim; j++)
				dist[i][j] = min(dist[i][j], dist[i][j-1]);
    while(q--){
        int u, l;
        cin >> u >> l;
        int ans = dist[u][l] >= 0x3f3f3f3f ? -1 : dist[u][l];
        cout << ans << endl;
    }
    return 0;
}