#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define LOG 25
using namespace std;

int ft[maxn];
int lsone(int x){
    return (x&(-x));
}

void update(int r, int v){
    if(r==0) return;
    for(;r<maxn;r+=lsone(r))
        ft[r]+=v;
}

int get(int r){
    int sum = 0;
    for(;r;r-=lsone(r))
        sum+=ft[r];
    return sum;
}

int up[maxn][LOG], ht[maxn], att[maxn];
vector<int> adj[maxn], partys[maxn];
void dfs(int u, int p){
    up[u][0] = p;
    for(int k=1;k<LOG;k++)
        if(up[u][k-1]!=-1)
            up[u][k] = up[up[u][k-1]][k-1];

    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);
}

int lift(int u, int hmax){
    for(int k=LOG-1;k>=0;k--){
        if(up[u][k]!=-1 && ht[up[u][k]]<=hmax){
            u = up[u][k];
        }
    }
    return u;
}

void solve(int u, int p){
    for(auto j:partys[u])
        update(j,1);

    att[u] = get(ht[u]);
    for(auto v:adj[u])
        if(v!=p)
            solve(v,u);

    for(auto j:partys[u])
        update(j,-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, y, o, l, r;
    cin >> n >> m;
    memset(up,-1,sizeof(up));
    for(int i=1;i<=n;i++){
        cin >> ht[i] >> y;
        adj[i].push_back(y);
        adj[y].push_back(i);
    }
    dfs(1,-1);

    for(int i=1;i<=m;i++){
        cin >> o >> l >> r;
        partys[lift(o,r)].push_back(l);
    }
    solve(1,1);
    
    for(int i=1;i<=n;i++){
        cout << att[i] << " ";
    }cout<<'\n';
    return 0;
}