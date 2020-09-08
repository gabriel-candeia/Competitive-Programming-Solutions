#include<bits/stdc++.h>
#define ll long long
#define N int(1e5+5)
using namespace std;    

const ll mod = 1e9+7;

ll n, t, m, x, y;
vector<vector<ll>> adj;
vector<ll> p, qtd, w;
map<pair<ll,ll>,ll> mp;

void dfs(int u, int parent){
    for(auto v: adj[u]){
        if(v!=parent){
            dfs(v,u);
            qtd[u] += qtd[v];
            mp[{u,v}] = (qtd[v]*(n-qtd[v]));
        }
    }
    qtd[u]++;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        mp.clear();
        w.clear();
        adj.assign(n+1,vector<ll>());
        qtd.assign(n+1,0);
        for(int i=0;i<n-1;i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        cin >> m;
        p.assign(m,0);
        for(int i=0;i<m;i++){
            cin >> p[i];
        }

        dfs(1,0);
        for(auto x:mp){
            w.push_back(x.second);
        }

        sort(p.rbegin(),p.rend());
        sort(w.rbegin(),w.rend());
        
        
        while(p.size()<n-1){
            p.push_back(1);
            m++;
        }
        int qtd = m-(n-1);
        for(int i=1;i<=qtd;i++){
            p[0] = (p[0]*p[i])%mod;
        }
        for(int i=qtd+1;i<m;i++){
            p[i-qtd] = p[i];
        }
        m = n-1;
        ll answ = 0;
        for(int i=0;i<n-1;i++){
            w[i]%=mod;
            answ = (answ + (p[i]*w[i])%mod)%mod;
        }
        cout << answ%mod <<'\n';
    }

    return 0;
}