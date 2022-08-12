#include <bits/stdc++.h>
#define maxn 30005
#define maxm 101
#define ll long long
using namespace std;

struct edge{
  ll u, v, c, f;
  
  edge(){}
  
  edge(ll u, ll v, ll c){
    this->u = u;
    this->v = v;
    this->c = c;
    f = 0;
  }
};

ll cnt = 0;
ll in[maxm][maxm], out[maxm][maxm];
const int inf = 0x3f3f3f3f;
ll t, n, m;
vector<ll> adj[maxn];
vector<edge> edges;
vector<ll> dist, ptr;
char grid[maxm][maxm];

void add(ll u, ll v, ll w){
  edges.push_back(edge(u,v,w));
  adj[u].push_back(edges.size()-1);
  edges.push_back(edge(v,u,0));
  adj[v].push_back(edges.size()-1);
}

ll dfs(ll s, ll t, ll f){
  if(s==t)
    return f;
  for(ll &i = ptr[s]; i < adj[s].size(); i++){
    ll e = adj[s][i];
    if(dist[edges[e].v] == dist[s]+1 && edges[e].c  > 0){
      if(ll x = dfs(edges[e].v,t,min(f,edges[e].c))){
          edges[e].c -= x;
          edges[e^1].c += x;
          return x;
      }
    }
  }
  return 0;
}

bool bfs(ll s, ll t){
    queue <ll> q;
    dist.assign(maxn,inf);
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        s = q.front(), q.pop();
        for(auto e : adj[s]){ 
            if(dist[edges[e].v] == inf && edges[e].c > 0){
                dist[edges[e].v] = 1+dist[s];
                q.push(edges[e].v);
            }
        }
    }
    return dist[t] < inf;
}

ll Dinic(ll s, ll t){
    for(ll i=0;i<edges.size();i++)
      edges[i].f = 0;
    ll maxflow = 0;
    while(bfs(s, t)){
        ptr.assign(maxn,0);
        while(ll f = dfs(s, t, inf)){
            maxflow += f;
        }
    }
    return maxflow;
}

bool ok(ll x, ll y){
    return (x>=0 && y>=0 && x<n && y<m && grid[x][y]!='#');
}


int main(){
  cin >> n >> m;
  ll dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

  cnt = 2;
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
        cin >> grid[i][j];
        if(grid[i][j]=='#') continue;
        if(grid[i][j]=='1')
          in[i][j] = out[i][j] = ++cnt;
        else if(grid[i][j]=='2')
          in[i][j] = out[i][j] = ++cnt;
        else{
          in[i][j] = ++cnt; out[i][j] = ++cnt;
        }
    }
  }

  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
        if(grid[i][j]=='#') continue;
        if(grid[i][j]=='1'){
          add(1,in[i][j],inf);
        }
        if(grid[i][j]=='2'){
          add(out[i][j],2,inf);
        }
        ll l = in[i][j], r = out[i][j];
        if(l!=r){
          add(l,r,1);
        }
        for(ll k=0;k<4;k++){
            ll nx = i+dx[k], ny = j+dy[k];
            if(ok(nx,ny) && !((grid[i][j]=='1' && grid[nx][ny]=='2') || (grid[i][j]=='2' && grid[nx][ny]=='1')) && (nx>=i && ny>=j)){
                if(r!=2 && in[nx][ny]!=1){
                  add(r,in[nx][ny],inf);
                }
                add(out[nx][ny],l,inf);
                //if(l!=1 && out[nx][ny]!=2)
                  //
            }
        }
    }
  }
  
  cout << Dinic(1,2) <<"\n";
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      if(grid[i][j]!='.') continue;
      ll u = in[i][j];
      if(dist[in[i][j]]!=inf && dist[out[i][j]]==inf){  
        grid[i][j] = '%';
      }
    }
  }

  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
        cout << grid[i][j];
    }
    cout<<'\n';
  }

  return 0;
}
 