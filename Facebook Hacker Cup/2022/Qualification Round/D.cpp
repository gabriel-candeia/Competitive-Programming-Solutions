#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
using namespace std;

int main(){
    fastio();
    int t, caso = 0;
    cin >> t;
    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> dg(n+1,0);
        vector<unordered_map<int,ll>> adj(n+1,unordered_map<int,ll>());

        for(int i=0;i<m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a][b] += c;
            adj[b][a] += c;
            dg[a]++, dg[b]++;
        }
        cout << "Case #"  << ++caso << ": ";
        for(int i=0;i<q;i++){
            int u, v;
            cin >> u >> v;
            if(dg[u]>dg[v]) swap(u,v);

            ll answ = 0;
            if(adj[u].find(v)!=adj[u].end())
                answ  += 2*adj[u][v];
            for(auto [w,wt]:adj[u])
                if(adj[v].find(w)!=adj[v].end())
                    answ += min(wt,adj[v][w]);

            cout << answ <<" ";
        }
        cout<<"\n";
    }

    return 0;
}