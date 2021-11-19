#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int n, m;
vector<int> adj[maxn];

vector<int> bfs(int u, int s){
    vector<int> dist(n+1,-1), parent(n+1,-1);
    queue<int> q; 
    q.push(u), dist[u] = 0, parent[u] = 0;

    while(q.size()){
        int v = q.front(); q.pop();
        for(auto w:adj[v])
            if(dist[w]==-1)
                q.push(w), dist[w] = dist[v]+1, parent[w] = v;
    }

    vector<int> answ;
    while(parent[s]!=-1)
        answ.push_back(s), s = parent[s];
    return vector<int>(answ.rbegin(),answ.rend());
}


int main(){
    cin >> n >> m;
    for(int i=0,x,y;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    auto answ = bfs(1,n);
    if(answ.size()==0){
        cout << "IMPOSSIBLE" << "\n";
    } 
    else{
        cout << answ.size() << "\n";
        for(auto x:answ)
            cout << x << " ";
        cout<<'\n';
    }

    return 0;
}