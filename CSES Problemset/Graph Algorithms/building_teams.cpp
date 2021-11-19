#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int n, m, color[maxn];
vector<int> adj[maxn];

bool dfs(int u, int c){
    bool ret = true;
    color[u] = c;

    for(auto v:adj[u]){
        if(color[v]==-1)
            ret = (ret && dfs(v,1-c));
        else
            ret = (ret && color[v]!=color[u]);
    }

    return ret;
}

int main(){
    cin >> n >> m;
    for(int i=0,x,y;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(color,-1,sizeof(color));
    bool answ = true;
    for(int i=1;i<=n;i++)
        if(color[i]==-1)
            answ = answ && dfs(i,0);

    if(answ){
        for(int i=1;i<=n;i++)
            cout << color[i]+1 << " ";
        cout << "\n";
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}