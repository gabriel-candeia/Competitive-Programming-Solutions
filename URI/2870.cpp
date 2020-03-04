#include<bits/stdc++.h>
#define N int(1e5)+3
using namespace std;

vector<bool> visited; 
vector<int> dist; 
deque<int> q;

int bfs(vector<int> adj[N], int k, int n){
    int w, cont = 0;
    int qtd=0;

    q.push_back(k);
    visited[k] = true;
    while(q.size()){
        qtd++;
        w  = q.front();
        q.pop_front();
        cont += dist[w]%2;
        for(auto i:adj[w]){
            if(!visited[i]){
                q.push_back(i);
                visited[i] = true;
                dist[i] = dist[w]+1;
            }
        }
    }
    return (cont != qtd-cont);
}

string jogo(vector<int> adj[N], int n){
    visited.assign(n+1,false);
    dist.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i] && bfs(adj,i,n)){
            return "Junior";
        }
    }
    return "Thiago";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> adj[N];
    int n,m,x,y;
    cin >> n >> m;
    while(m--){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << jogo(adj,n) << '\n';

    return 0;
}
