#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#define maxn 5050
#define inf 0x3f3f3f3f

struct node{
  int v, f, c;
  node(){}
  node(int v, int f, int c){
    this->v = v;
    this->f = f;
    this->c = c;
  }
};

vector <node> edges;
vector <int> g[maxn];
int dist[maxn], ptr[maxn];

void addEdge(int u, int v, int c){
  edges.push_back(node(v, 0, c));
  g[u].push_back(sz(edges)-1);
  edges.push_back(node(u, 0, 0));
  g[v].push_back(sz(edges)-1);  
}

//Escolhendo o caminho
bool bfs(int s, int t){
  queue <int> q;
  memset(dist, inf, sizeof dist);
  dist[s] = 0;
  q.push(s);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(auto e : g[u]){
      if(dist[edges[e].v] == inf && edges[e].c-edges[e].f > 0){
        dist[edges[e].v] = 1+dist[u];
        q.push(edges[e].v);
      }
    }
  }
  return dist[t] != inf;
}

//Reaproveitando o caminho
ll dfs(int s, int t, int f){
  if(s == t)
    return f;
  for(int &i = ptr[s]; i < sz(g[s]); i++){
    int e = g[s][i];
    if(dist[edges[e].v] == dist[s]+1 && edges[e].c-edges[e].f > 0){
      if(int x = dfs(edges[e].v, t, min(f, edges[e].c-edges[e].f))){
        edges[e].f += x; 
        edges[e^1].f -= x;
        return x;
      }
    }
  }
  return 0;
}

ll Dinic(int s, int t){
  ll maxFlow = 0;
  while(bfs(s, t)){
    memset(ptr, 0, sizeof ptr);
    while(ll flow = dfs(s, t, inf))
      maxFlow += flow;
  }
  return maxFlow;
}

vector<int> adj[maxn], visited;
void dfs(int u, int color){
    visited[u] = color;
    for(auto v:adj[u]){
        if(!visited[v]){
            dfs(v,((color==1) ? 2 : 1));
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited.assign(n+1,0);
    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs(i,1);

    
    for(int i=1;i<=n;i++){
        if(visited[i]==1){
            addEdge(0,i,1);
            for(auto v:adj[i]){
                addEdge(i,v,1);
            }
        }
        else if(visited[i]==2){
            addEdge(i,n+1,1);
        }
    }
    
    cout << Dinic(0, n+1) << endl;
    return 0;
}