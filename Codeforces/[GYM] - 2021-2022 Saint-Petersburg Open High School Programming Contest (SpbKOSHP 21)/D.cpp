#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

vector<int> adj[maxn];
int att[maxn];

int main(){
    int n, m, x;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> x;
    for(int i=1;i<=n;i++)
        cin >> att[i];

    vector<int> dist(n+1,0);
    dist[1] = x;
    priority_queue<tuple<int,int>> pq;
    pq.push({dist[1],1});
    int u, d;

    while(pq.size()){
        tie(d,u) = pq.top(); pq.pop();

        if(d<dist[u]) continue;
        if(d<=att[u]) d/=2;
        for(auto v:adj[u]){
            if(dist[v]<d){
                dist[v] = d;
                pq.push({dist[v],v});
            }
        }
    }
    
    if(dist[n]<=att[n]) dist[n]/=2;
    cout << dist[n] <<"\n";

    return 0;
}