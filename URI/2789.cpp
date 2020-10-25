#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
using namespace std;

ll n, q, d, m;
vector<ll> valor, agua, att;
vector<vector<ll>> adj;
vector<vector<pair<ll,ll>>> queries;

ll dfs(ll u, ll p){
    for(auto v:adj[u])
        if(v!=p)
            att[u]+=dfs(v,u);

    agua[u] += att[u];
    return att[u];
}

ll dp[maxn];

int main(){
    ll x, y, z;
    cin >> n >> d;

    adj.assign(n+1,vector<ll>());
    queries.assign(n+1,vector<pair<ll,ll>>());
    valor.assign(n+1,0);
    agua.assign(n+1,0);
    att.assign(n+1,0);

    for(ll i=1;i<n;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cin >> m;
    for(ll i=1;i<=m;i++){
        cin >> x >> y;
        valor[x] = y;
    }

    cin >> q;
    for(ll i=1;i<=q;i++){
        cin >> x >> y >> z;
        queries[min(x,y)].push_back({max(x,y),z});
    }

    for(ll i=1;i<=n;i++){
        att.assign(n+1,0);
        for(auto p:queries[i])
            att[p.first]+=p.second;
        dfs(i,-1);
    }

    for(ll i=1;i<=n;i++)
        if(valor[i]==0)
            agua[i] = 0;

    for(ll i=1;i<=n;i++)
        for(ll j=d;j>=0 && j>=valor[i];j--)
            dp[j] = max(dp[j],dp[j-valor[i]]+agua[i]);
    
    cout << dp[d] <<'\n';
    return 0;
}