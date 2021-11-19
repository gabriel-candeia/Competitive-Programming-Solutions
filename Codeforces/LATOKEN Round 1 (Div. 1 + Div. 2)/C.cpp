#include<bits/stdc++.h>
#define ll long long
using namespace std;


const ll mod = 1e9+7;
int n;
vector<int> adj;
vector<int> ord, visited;

void dfs(int u, bool insere=true){
    visited[u] = 1;
    if(!visited[adj[u]])
        dfs(adj[u],insere);
    if(insere)
        ord.push_back(u);
}

ll binpow(ll x, ll y){
    ll result = 1;
    for(;y;y/=2){
        if(y&1)
            result = (result*x)%mod;
        x = (x*x)%mod;
    }
    return result;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        adj.assign(n+1,0);

        vector<int> temp(n+1,0);
        for(int i=0;i<n;i++) cin >> temp[i];
        for(int i=0, a;i<n;i++) cin >> a, adj[a] = temp[i];
        
        visited.assign(n+1,0);
        ord.clear();
        for(int i=1;i<=n;i++)
            if(!visited[i])
                dfs(i);
        
        visited.assign(n+1,0);
        int cc = 0;
        for(int i=0;i<ord.size();i++){
            int x = ord[i];
            
            if(!visited[x])
                cc++, dfs(x,false);
        }
        
        cout << binpow(2,cc) <<"\n";
        

    }

    return 0;
}