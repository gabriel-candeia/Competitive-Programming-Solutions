#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

vector<int> adj[maxn];
int main(){
    fastio();
    int n, m;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dg(n+1,0), visited(n+1,0);
    priority_queue<pair<int,int>> pq;
    visited[1] = 1;
    pq.push({-1,0});
    
    int u, ptr;
    while(pq.size()){
        tie(u, ptr) = pq.top(), pq.pop(), u = -u;
        
        if(ptr!=adj[u].size()){
            int v = adj[u][ptr];
            if(!visited[v]){
                visited[v] = 1;
                pq.push({-v,0}); 
                dg[v]++, dg[u]++;
            }
            pq.push({-u,ptr+1});
        }
    }

    cout << (*max_element(dg.begin(),dg.end())) << "\n";
    return 0;
}