#include<bits/stdc++.h>
#define N 1000

using namespace std;
int tempo(vector<pair<int,int>> adj[N], int n, int u, int v){
    vector<int> dist; dist.assign(n+1,INT_MAX);
    pair<int,int> st[N], wp; 
    int top=0, w, d;
    vector<bool> visited; visited.assign(n+1,false);

    dist[u] = 0;
    visited[u] = true;
    st[top++] = make_pair(u,dist[u]);
    while(top){
        wp = st[--top];
        w = wp.first; d = wp.second;
        random_shuffle(adj[w].begin(),adj[w].end());
        for(auto i: adj[w]){
            if(((d)%3==0)==i.second && d<dist[v] && (visited[i.first]!=true || (d+1-dist[i.first])%3)){
                dist[i.first] = d+1;
                st[top++] = make_pair(i.first,dist[i.first]);
                visited[i.first] = true;
            }
        }
    }

    return ((visited[v]) ? dist[v] : -1);
}

int main(){
    int n, u, v, m;
    int x, y, z;
    vector<pair<int,int>> adj[N];

    cin >> n >> u >> v >> m;
    while(m--){
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y,z));
    }
    x = tempo(adj,n, u, v);
    if(x==-1){
        cout << "*\n" ;
    }
    else{
        cout << x << '\n';    
    }
    
    return 0;
}

