#include <bits/stdc++.h>
using namespace std;

#define maxn 1005

struct edge{
  int v, c, f;
  
  edge(){}
  
  edge(int v, int c){
    this->v = v;
    this->c = c;
    f = 0;
  }
};

const int inf = 0x3f3f3f3f;
int t, n, m;
vector<int> adj[maxn];
vector<edge> edges;
vector<int> dist, ptr;
char grid[maxn][maxn];

void add(int u, int v, int w){
  edges.push_back(edge(v,w));
  adj[u].push_back(edges.size()-1);
  edges.push_back(edge(u,w));
  adj[v].push_back(edges.size()-1);
}

int dfs(int s, int t, int f){
  if(s==t)
    return f;
  for(int &i = ptr[s]; i < adj[s].size(); i++){
    int e = adj[s][i];
    if(dist[edges[e].v] == dist[s]+1 && (edges[e].c - edges[e].f > 0)){
      if(int x = dfs(edges[e].v,t,min(f,edges[e].c-edges[e].f))){
          edges[e].f += x;
          edges[e^1].f -= x;
          return x;
      }
    }
  }
  return 0;
}

bool bfs(int s, int t){
    queue <int> q;
    dist.assign(maxn,inf);
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        s = q.front(), q.pop();
        for(auto e : adj[s]){ 
            if(dist[edges[e].v] == inf && (edges[e].c - edges[e].f > 0)){
                dist[edges[e].v] = 1+dist[s];
                q.push(edges[e].v);
            }
        }
    }
    return dist[t] < inf;
}

int Dinic(int s, int t){
    for(int i=0;i<edges.size();i++)
      edges[i].f = 0;
    int maxflow = 0;
    while(bfs(s, t)){
        ptr.assign(maxn,0);
        while(int f = dfs(s, t, inf)){
            maxflow += f;
        }
    }
    return maxflow;
}

bool ok(int x, int y){
    return (x>=0 && y>=0 && x<n && y<m && grid[x][y]!='#');
}

int main(){
  cin >> n >> m;
  int mp[2] = {0,0}, dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin >> grid[i][j];
        if(grid[i][j]=='1')
            mp['1'-'1'] = i*m+j;
        if(grid[i][j]=='2')
            mp['2'-'1'] = i*m+j;
    }
  }


  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int atual = i*m+j;
        if(grid[i][j]=='1')
            atual = mp[0];
        else if(grid[i][j]=='2')
            atual = mp[1];
        for(int k=0;k<4;k++){
            int nx = i+dx[k], ny = j+dy[k];
            if(ok(nx,ny) && (grid[nx][ny]!=grid[i][j] || (grid[i][j]!='1'&&grid[i][j]!='2'))){
                add(atual,nx*m+ny,1);
                //add(nx*m+ny,atual,1);
            }
        }
    }
  }

  cout << Dinic(mp[0],mp[1]) << '\n';
  for(int u=1;u<=n*m;u++){
    if(grid[u/m][u%m] == '1' || grid[u/m][u%m] == '2') continue;
    bool corta = false;
    for(auto v:adj[u]){
        corta = (dist[u]!=inf && dist[v]==inf);
        if(corta)
            break;
    }
    if(corta){
        grid[u/m][u%m] = '%';
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout << grid[i][j];
    }
    cout<<'\n';
  }

  return 0;
}