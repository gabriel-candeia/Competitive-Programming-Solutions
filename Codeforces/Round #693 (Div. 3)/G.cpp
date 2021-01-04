#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int n, m, d[maxn], dp[maxn][2];
vector<int> adj[maxn];

void bfs(int u){
    queue<int> q;
    q.push(u); d[u] = 1;

    while(q.size()){
        u = q.front(); q.pop();

        for(auto v:adj[u]){
            if(!d[v]){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }

    for(int i=1;i<=n;i++)
        d[i]--;
}

int solve(int u, int x){
    if(dp[u][x]!=-1)
        return dp[u][x];
    dp[u][x] = d[u];
    for(auto v:adj[u]){
        if(d[u]<d[v])
            dp[u][x] = min(dp[u][x],solve(v,x));
        if(d[u]>=d[v] && x==0)
            dp[u][x] = min(dp[u][x],solve(v,1));
    }
    return dp[u][x];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<=n;i++){
            adj[i].clear();
            d[i] = 0;
        }

        for(int i=0, x, y;i<m;i++){
            cin >> x >> y;
            adj[x].push_back(y);
        }
        bfs(1);

        memset(dp,-1,sizeof(dp));
        dp[1][0] = dp[1][1] = 0;

        for(int i=1;i<=n;i++)
            cout << solve(i,0) << " ";
        cout<<'\n';
    }

    return 0;
}