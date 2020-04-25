#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<pair<int,int>,ll> freq;

bool bfs(vector<vector<int>>& adj, vector<int>& visited, int u, int target, int n){
    queue<int> q;
    vector<int> parent(n+1,-1);
    int v;

    visited[u] = true;
    q.push(u);
    
    while(q.size()){
        v = q.front(); q.pop();

        if(v==target){
            break;
        }

        for(auto w:adj[v]){
            if(!visited[w]){
                parent[w] = v;
                visited[w] = true;
                q.push(w);
            }
        }
    }

    v = target;
    while(parent[v]!=-1){
        freq[make_pair(min(parent[v],v),max(parent[v],v))]++;
        v = parent[v];
    }

}

int main(){
    vector<vector<int>> adj;
    vector<ll> p;
    vector<int> visited;
    int t, n, m, a, b, c;
    int x, y;

    cin >> t;
    while(t--){
        cin >> n >> m >> a >> b >> c;

        adj.assign(n+1,vector<int>());
        p.assign(m,0);
        freq.clear();

        for(int i=0;i<m;i++){
            cin >> p[i];
        }

        for(int i=0;i<m;i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        //bfs from a to b
        visited.assign(n+1,false);
        bfs(adj,visited,a,b,n);

        //bfs from b to c
        visited.assign(n+1,false);  
        bfs(adj,visited,b,c,n);

        //alg
        vector<ll> ord;
        for(auto p:freq){
            ord.push_back(p.second);
        }
        sort(ord.rbegin(),ord.rend());
        sort(p.begin(),p.end());
        ll answ=0;

        for(int i=0;i<ord.size();i++){
            answ += ord[i]*p[i];
        }

        cout << answ << '\n';
    }

    return 0;
}