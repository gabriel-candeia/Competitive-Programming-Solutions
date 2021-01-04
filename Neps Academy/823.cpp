#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> branco, preto;
int answ = 0;

int dfs(int u, int p){
    int acm = 0;
    for(auto e:adj[u]){
        if(e.first!=p){
            dfs(e.first,u);
            if(e.second==0)
                preto[u] = max(preto[u],branco[e.first]+1);
            else
                branco[u] = max(branco[u],preto[e.first]+1);
        }
    }
    answ = max(answ,branco[u]+preto[u]+1);
    return acm;
}

int main(){
    fastio();
    int n, x, y, z;
    cin >> n;
    adj.assign(n+1,vector<pair<int,int>>());
    branco.assign(n+1,0);
    preto.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    dfs(1,-1);
    
    cout << answ <<'\n';

    return 0;
}