#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

vector<int> adj[maxn], freebeads[maxn], beads;
vector<pair<int,int>> edges;
int visited[maxn];
int n, m, cnt;

void dfs(int i, int p){
    visited[i] = 1;
    for(auto v:adj[i]){
        if(visited[v]==0 || visited[v]==2){
            if(freebeads[i].size()==0){
                freebeads[i].push_back(++cnt);
                beads.push_back(i);
            }
            if(freebeads[v].size()==0){
                freebeads[v].push_back(++cnt);
                beads.push_back(v);
            }
            edges.push_back({freebeads[i].back(),freebeads[v].back()});
            freebeads[i].pop_back();
        }
        if(!visited[v])
            dfs(v,i);
    }
    visited[i] = 2;
}

int main(){
    int x, y;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1);

    cout << beads.size() << "\n";
    for(auto x:beads)
        cout << x << " ";
    cout<<'\n';
    for(auto x:edges)
        cout << x.first <<" " << x.second <<"\n";

    return 0;
}