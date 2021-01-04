#include<bits/stdc++.h>
#define LOG 20
#define ll long long
#define maxn int(5e5+5)
using namespace std;

ll n, cntA[maxn], cntB[maxn], a, b, answ;
vector<int> adj[maxn], path;

void dfs(int u, int p){
    cntA[u] = cntB[u] = 1;
    path.push_back(u);

    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);
    
    int qtd = path.size();
    if(qtd-1-a>=0) cntA[path[qtd-1-a]] += cntA[u];
    if(qtd-1-b>=0) cntB[path[qtd-1-b]] += cntB[u];
    answ += (cntA[u]*cntB[u]) + (cntA[u]*(n - cntB[u])) + (cntB[u]*(n - cntA[u]));
    path.pop_back();
}

int main(){
    int t, x, caso=0;
    cin >> t;   
    while(t--){
        answ = 0;
        cin >> n >> a >> b;
        for(int i=2;i<=n;i++){
            cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        
        dfs(1,-1);
        cout << "Case #" << ++caso << ": " << fixed << setprecision(10) << answ*(1.0)/(n*n) << "\n";

        for(int i=0;i<=n;i++) adj[i].clear();
    }
    return 0;
}