#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
#define maxn int(505)
using namespace std;

const ll inf = 1e17;
int n;
int dp[maxn][maxn][2];
vector<pair<int,int>> adj[maxn];

int main(){
    fastio();
    int m, q;
    cin >> n >> m >> q;

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    for(int v=1;v<=n;v++)
        for(int u=1;u<=n;u++)
            dp[u][v][0] = ((u==v) ? 0 : -1);

    vector<tuple<ll,ll,ll>> queries;
    vector<ll> answ(q,inf);

    for(int i=0;i<q;i++){
        ll u, v, x;
        cin >> u >> v >> x;
        queries.push_back({u,v,x});
    }

    for(int w=1;w<=n;w++){
        int curr = w%2, last = 1-curr;
        for(int v=1;v<=n;v++){
            for(int u=1;u<=n;u++){
                dp[u][v][curr] = -1;
                for(auto e:adj[u]){
                    if(dp[e.first][v][last]!=-1 && (dp[e.first][v][last]+e.second < dp[u][v][curr] || dp[u][v][curr]==-1)){
                        dp[u][v][curr] = dp[e.first][v][last]+e.second;
                    }
                }
            }
        }   
        for(int i=0;i<q;i++){
            ll u, v, x;
            tie(u,v,x) = queries[i];
            if(dp[u][v][curr]!=-1)
                answ[i] = min(answ[i],dp[u][v][curr]+(w+1)*x);
            if(u==v) answ[i] = x;
        }
    }

    for(int i=0;i<q;i++){
        if(answ[i]==inf) answ[i] = -1;
        cout << answ[i] << "\n";
    }

    return 0;
}