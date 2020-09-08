#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define maxn int(3e5+5)
#define maxm 20
using namespace std;

vector<vector<int>> adj;
int n, up[maxn][maxm], h[maxn];
int q, a, b, c;

void dfs(int u, int p, int ht){
    h[u] = ht; up[u][0] = p;
    for(int k=1;k<maxm;k++)
        if(up[u][k-1]!=-1)
            up[u][k] = up[up[u][k-1]][k-1];

    for(auto v:adj[u]){
        if(v!=p){
            dfs(v,u,ht+1);
        }
    }
}

int lift(int u, int c){
    for(int k=20;k>=0;k--){
        if((1<<k)<=c && up[u][k]!=-1){
            u = up[u][k];
            c -= 1<<k;
        }
    }
    return u;
}

int lca(int u, int v){
    if(h[v]<h[u])
        swap(u,v);
    v = lift(v,h[v]-h[u]);
    if(u==v)
        return v;
    for(int k=maxm-1;k>=0;k--){
        if(up[u][k]!=up[v][k]){
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}

int answerQuery(int a, int b, int c){
    int w = lca(a,b), dist = h[a]+h[b]-2*h[w];
    if(c>=dist){
        return b;
    }
    else if(c>=h[a]-h[w]){
        return lift(b,dist-c);
    }
    return lift(a,c);
}

int main(){
    fastio();
    int x, y;
    cin >> n;
    adj.assign(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(up,-1,sizeof up);
    memset(h,-1,sizeof h);
    dfs(1,-1,0);
    cin >> q;
    
    while(q--){
        cin >> a >> b >> c;
        cout << answerQuery(a,b,c) << '\n';
    }

    return 0;
}