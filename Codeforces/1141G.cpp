#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int r = 1;
vector<int> answ, visited, marked;
vector<pair<int,int>> adj[maxn];

void dfs(int u, int p, int color){
    visited[u] = 1;

    int ptr = ((marked[u]==0) ? 1 + (color==1) : color);
    if(ptr==-1) ptr = 1;
    for(auto e:adj[u]){    
        if(e.first != p){
            answ[e.second] = ptr;
            dfs(e.first,u,ptr);
            if(marked[u]==0)
                ptr = ptr + 1 + (color==(ptr+1));
        }
    }
    r = max(ptr-1,r);
}

int main(){
    int n, k, x, y;

    cin >> n >> k;
    answ.assign(n-1,0);
    visited.assign(n+1,0);
    marked.assign(n+1,0);
    vector<pair<int,int>> dg(n+1,{0,0});
    for(int i=1;i<=n;i++){
        dg[i] = {0,i};
    }
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
        dg[x].first++;
        dg[y].first++;
    }

    sort(dg.rbegin(),dg.rend());
    for(int i=0;i<k;i++)
        marked[dg[i].second] = 1;        
    
    dfs(1,-1,-1);
    cout << r << "\n";
    for(int i=0;i<n-1;i++)
        cout << answ[i] << " ";
    cout << '\n';

    return 0;
}