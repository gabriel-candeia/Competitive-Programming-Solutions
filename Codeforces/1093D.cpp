#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
ll x=0, y=0;

ll binpow(ll a, ll b, ll mod){
    if(b==0){
        return 1;
    }
    ll temp = (binpow(a,b/2,mod))%mod;
    temp = (temp*temp)%mod;
    if(b%2){
        return (temp*a)%mod;
    }
    return temp;
}

bool dfs(vector<vector<int>>& adj, int u, vector<int>& visited, int cnt){
    visited[u] = cnt;

    if(visited[u]==1){
        x++;
    }
    else{
        y++;
    }

    bool poss = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            poss = (dfs(adj,v,visited,((cnt==1) ? 2 : 1)) && poss);
        }
        else if(visited[v]==visited[u]){
            poss = false;
        }
    }

    return poss;
}

int main(){
    int n, m, t;
    int a, b;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int>> adj(n+1,vector<int>());
        for(int i=0;i<m;i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> visited(n+1,0);
        bool poss = true;
        ll answ = 1;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                x = 0, y=0;
                poss = (dfs(adj,i,visited,1) && poss);
                answ = (answ*((binpow(2ll,x,mod) + binpow(2ll,y,mod)%mod)))%mod;
            }
        }

        if(poss){
            cout << answ << '\n';
        }
        else{
            cout << 0 << '\n';
        }
        
    }

    return 0;
}