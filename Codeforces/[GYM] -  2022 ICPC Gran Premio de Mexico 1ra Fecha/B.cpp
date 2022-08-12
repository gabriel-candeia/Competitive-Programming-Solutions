    #include <bits/stdc++.h>

    using namespace std;

    #define maxn int(1e5+10)

    int n, k;
    set<int> a, b;
    int visited[maxn][105];
    vector<int> adj[maxn];

    void dfs(int u, int p, int h){
        if(h > k) return;
        visited[u][h] = 1;
        if(!b.count(u)) a.insert(u);
        for(int v:adj[u]){
            if(v != p && !visited[v][h+1]){
                dfs(v, u, h+1);
            }
        }
    }

    int main(){
        ios_base::sync_with_stdio(0); cin.tie(0);
        cin >> n >> k;
        for(int i = 1, u, v; i < n; i++){
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        a.insert(1);
        for(int i = 1; i <= n; i++){
            int mmin = *(a.begin());
            a.erase(a.begin());
            b.insert(mmin);
            dfs(mmin, -1, 0);
            cout << mmin << " ";
        }
        cout << "\n";
        return 0;
    }