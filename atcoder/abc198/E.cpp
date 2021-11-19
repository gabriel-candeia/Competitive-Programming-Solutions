#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

map<int,int> cnt;
int color[maxn], good[maxn];
vector<int> adj[maxn];

void dfs(int u, int p){
    cnt[color[u]]++;
    good[u] = (cnt[color[u]]==1);
    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);
    cnt[color[u]]--;
}

int main(){
    int n, x, y;

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> color[i];

    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);
    for(int i=1;i<=n;i++)
        if(good[i])
            cout << i << "\n";
    return 0;
}