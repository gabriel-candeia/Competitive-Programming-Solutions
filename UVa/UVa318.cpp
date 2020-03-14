#include<bits/stdc++.h>
using namespace std;

void alg(vector<vector<pair<int,int>>>& adj,int u,int n){
    vector<bool> visited; visited.assign(n+3, false);
    vector<double> dist; dist.assign(n+3, INT_MAX);
    pair<double,pair<int,int>> le = make_pair(-1,make_pair(-1,-1));
    priority_queue<pair<int,int>> h; h.push(make_pair(0,1));
    pair<int,int> wp;
    int w, d;
    double l;
    dist[1] = 0;
    while(h.size()){
        wp = h.top();
        h.pop();
        w = wp.second; d = -wp.first;
        visited[w] = true;
        for(auto v:adj[w]){
            if(!visited[v.second] && d+v.first < dist[v.second]){
                dist[v.second] = d+v.first;
                h.push(make_pair(-dist[v.second],v.second));
            }
            else{
                l = (v.first+dist[w]+dist[v.second])/2.0;
                if((dist[v.second]+v.first>dist[w]) && l > le.first){
                    le.first = l;
                    le.second.first = min(v.second,w);
                    le.second.second = max(v.second,w);
                }
            }
        }
    }  
    int mx = 1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[mx]){
            mx = i;
        }
    }

    if(dist[mx] >= le.first){
        printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n",dist[mx],mx);
    }
    else{
        printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",le.first,le.second.first,le.second.second);
    }
}

int main(){
    int n, m, cont=0;
    int x, y, w;
    vector<vector<pair<int,int>>> adj;

    while(cin >> n >> m){
        if(!n&&!m){ break;}
        adj.assign(n+3,vector<pair<int,int>>());
        for(int i=0;i<m;i++){
            cin >> x >> y >> w;
            adj[x].push_back(make_pair(w,y));
            adj[y].push_back(make_pair(w,x));
        }
        printf("System #%d\n",++cont);
        alg(adj,1,n);
    }

    return 0;
}
