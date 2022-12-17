#include<bits/stdc++.h>
#define maxn int(1e4+5)
using namespace std;

int n, m;
vector<pair<int,int>> adj[maxn];
int vis[maxn], fst[maxn], cnt = 0, acm[maxn];

void dfs(int u, int p){
    fst[u] = ++cnt;
    vis[u] = fst[u];

    for(auto [v,wt]:adj[u]){
        if(!vis[v]){
            dfs(v,u);
            vis[u] = min(vis[u],vis[v]);
        }
        else if(v!=p){
            vis[u] = min(vis[u],vis[v]);
        }
    }
}

int solve(int s, int siz){
    const int inf = 1e8;
    vector<int> dist(n+1,inf);
    priority_queue<pair<int,int>> pq;

    dist[s] = 0;
    pq.push({-dist[s],s});
    int best = inf;
    int d, u;
    while(pq.size()){
        tie(d,u) = pq.top(), pq.pop(), d = -d;
        
        if(acm[vis[u]]>=siz)
            best = min(best,2*d + acm[vis[u]]); 
        if(d>dist[u]) continue;
        for(auto [v,wt]:adj[u]){
            if(d+wt<dist[v]){
                dist[v] = d+wt, pq.push({-dist[v],v});
            }
        }
    }

    if(best==inf) best = -1;

    return best;
}

int main(){

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    dfs(1,-1);
    for(int i=1;i<=n;i++){
        for(auto [v,wt]:adj[i]){
            if(vis[i]==vis[v]){
                acm[vis[v]] += wt;
            }
        }
        //cout << vis[i] << " ";
    }//cout<<"\n";

    for(int v=1;v<=n;v++){
        if(fst[v]==vis[v]){
            acm[vis[v]] /= 2;
            //cout << v << " " << acm[vis[v]] <<"\n";
        }
    }

    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int s, m;
        cin >> s >> m;
        cout << solve(s,m) <<"\n";
    }

    return 0;
}