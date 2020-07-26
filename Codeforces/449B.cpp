#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

const ll inf = 1e16+5;
ll answ=0;
ll n, m, k, x, y, w;
vector<vector<pair<int,int>>> adj;
vector<ll> train;

void alg(){
    vector<bool> visited(n+1,false), last(n+1,0);
    vector<ll> dist(n+1,inf);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> h;
    pair<ll,int> p;
    int u, v, w;

    dist[1] = 0;
    h.push({0,1});
    for(int i=1;i<=n;i++){
        if(train[i]!=inf){
            last[i] = 1;
            dist[i] = train[i];
            h.push({dist[i],i});
        }
    }

    while(h.size()){
        p = h.top(); h.pop();
        u  = p.second;
        if(!visited[u]){
            visited[u] = true;
            for(auto e:adj[u]){
                v = e.first; w = e.second;
                if(dist[u]+w<=dist[v]){
                    dist[v] = dist[u]+w;
                    last[v] = 0;
                    h.push({dist[v],v});
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        answ += (last[i]==0 && train[i]!=inf);
    }

}


int main(){
    fastio();

    cin >> n >> m >> k;

    train.assign(n+1,inf);
    adj.assign(n+1,vector<pair<int,int>>());

    for(int i=0;i<m;i++){
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});        
    }

    for(int i=0;i<k;i++){
        cin >> x >> w;
        if(train[x]!=inf){
            answ++;
        }
        train[x] = min(train[x],w);
    }

    alg();

    cout << answ << '\n';

    return 0;
}