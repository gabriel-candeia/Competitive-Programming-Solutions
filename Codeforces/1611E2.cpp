#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define ll long long
using namespace std;

vector<int> adj[maxn], cor, parent;
void dfs(int u, int p){
    parent[u] = p;
    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);
}

ll dfs2(int u, int p){
    if(cor[u]==1) 
        return 1;
    if(u!=1 && adj[u].size()==1)
        return -maxn;
    parent[u] = p;
    ll answ = 0;
    for(auto v:adj[u])
        if(v!=p)
            answ += dfs2(v,u);
    return answ;
}

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, k;
        vector<int> up, down;
        cin >> n >> k;

        cor.assign(n+1,0), parent.assign(n+1,0);
        for(int i=0;i<k;i++){
            int x;
            cin >> x;
            cor[x] = 1;
            up.push_back(x);
        }

        for(int i=0;i<n-1;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(1,-1);
        down.push_back(1), cor[1] = 2;

        int u;
        while(true){
            vector<int> nextup, nextdown;
            for(auto u:up){
                if(cor[parent[u]]==0){
                    cor[parent[u]] = 1, nextup.push_back(parent[u]);
                }
            }

            for(auto u:down){
                for(auto v:adj[u]){
                    if(cor[v]==0){
                        cor[v] = 2, nextdown.push_back(v);
                    }
                }
            }

            up = nextup;
            down = nextdown;

            if(up.size()==0)
                break;
        }

        ll x = dfs2(1,-1);
        if(x<0) x = -1;
        cout << x <<"\n";

        for(int i=0;i<=n;i++) adj[i].clear();
    }

    return 0;
}