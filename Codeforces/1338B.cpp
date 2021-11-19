#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int odd[maxn], even[maxn];
bool ok  = false;
vector<int> adj[maxn];

void dfs(int u, int p){
    if(p!=-1 && adj[u].size()==1) even[u] = 1, odd[u] = 0;
    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u), even[u] |= odd[v], odd[u] |= even[v];
    if(odd[u] && even[u] || adj[u].size()==1 && odd[u]) ok = true;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,-1);
    int mn = (ok) ? 3 : 1, mx = n-1;
    for(int u=1;u<=n;u++){
        int cnt = 0;
        for(auto v:adj[u]){
            if(adj[v].size()==1){
                cnt++;
            }
        }
        
        if(cnt>0)
            mx-=cnt-1;
    }

    cout << mn << " " << mx <<'\n';

    return 0;
}