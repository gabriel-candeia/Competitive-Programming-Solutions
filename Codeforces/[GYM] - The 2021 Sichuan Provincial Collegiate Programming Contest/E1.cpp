#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end() 
#define maxn 101010
 
vector <int> g[maxn];
int vez, ans;
 
void dfs(int u, int n){
    if(u == n+1)
        return;
    for(auto v : g[u]){
        if(v >= vez){
            while(v >= vez){
                if(v == vez){
                    vez++;
                    dfs(v, n);
                }
                else{
                    ans++;
                    vez++;
                    dfs(vez-1, n);
                }
            }
        }
    }
}
 
int main(){
	ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
		cin >> n >> m;
		g[1].push_back(n+1);
		g[n+1].push_back(1);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
		for(int i = 1; i <= n; i++)
			sort(all(g[i]));
        ans = 0;
        vez = 2;
        dfs(1, n);
        cout << ans << endl;
        for(int i = 1; i <= n; i++)
            g[i].clear();
    }
    return 0;
}