#include<bits/stdc++.h>
#define N int(1e4)+3
using namespace std;

vector<bool> visited;
int tax[N];
int n, c, x, y, z;

int dfs(vector<pair<int,int>> adj[N], int v, int l){
    int acm = 0;
    for(auto i:adj[v]){
        if(!visited[i.first]){
            visited[i.first] = true;
            acm += dfs(adj,i.first,i.second);
            tax[v]+=tax[i.first];
        }
    }
    return acm+(2*ceil(tax[v]/(1.0*c)))*l;
}

int main(){
    vector<pair<int,int>> adj[N];

    cin >> n >> c;
    for(int i=0;i<n;i++){
        cin >> tax[i];
    }
    visited.assign(n+1,false);
    for(int i=0;i<n-1;i++){
        cin >> x >> y >> z;
        x--; y--;
        adj[x].push_back(make_pair(y,z));
        adj[y].push_back(make_pair(x,z));
    }   
    visited[0] = true;
    cout << dfs(adj,0,0) << '\n';
    return 0;
}