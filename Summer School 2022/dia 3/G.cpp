#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5+10)

int n, m, mmax, vmax;
int dad[maxn];

void dfs(vector<vector<int>> &adj, int u, int lvl){
	if(lvl > mmax){
		mmax = lvl;
		vmax = u;
	}
	for(int v:adj[u]){
		if(v != dad[u]){
			dad[v] = u;		
			dfs(adj, v, lvl+1);
		}
	}
}


int main(){
	cin >> n;
	vector<vector<int>> t1(n+1);
	for(int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		t1[u].emplace_back(v);
		t1[v].emplace_back(u);
	}
	cin >> m;
	vector<vector<int>> t2(m+1);
	for(int i = 1, u, v; i < m; i++){
		cin >> u >> v;
		t2[u].emplace_back(v);
		t2[v].emplace_back(u);
	}
	mmax = 0; dad[1] = 0;
	dfs(t1, 1, 0);
	mmax = 0; dad[vmax] = 0;
	dfs(t1, vmax, 0);
	int dmaxb = mmax;

	mmax = 0; dad[1] = 0;
	dfs(t2, 1, 0); 
	mmax = 0; dad[vmax] = 0;
	int root = vmax;
	dfs(t2, vmax, 0);
	
	vector<int> path;
	while(dad[vmax] != root){
		path.emplace_back(vmax);
		vmax = dad[vmax];
	}
	path.emplace_back(root);
	
	mmax = 0; dad[path[path.size()/2]] = 0;
	dfs(t2, path[path.size()/2], 0);

	if(dmaxb > mmax)
		cout << "GGEZ\n";
	else
		cout << "FF\n";

	
	return 0;
}