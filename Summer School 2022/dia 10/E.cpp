#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define LOG 25
using namespace std;

int p[maxn][LOG], ht[maxn], age[maxn], answ[maxn];
vector<int> adj[maxn], queries[maxn];
int ft[maxn];

int lsone(int x){
    return x&(-x);
}

void update(int r, int v){
    for(;r<maxn;r+=lsone(r)){
        ft[r] += v;
    }
}

int get(int r){
    int answ = 0;
    for(;r;r-=lsone(r)){
        answ += ft[r];
    }
    return answ;
}

void dfs(int u, int pai){
    ht[u] = ((pai!=-1) ? ht[pai]+1 : 0);
    p[u][0] = pai;
    for(int k=1;k<LOG;k++)
        if(p[u][k-1]!=-1)
            p[u][k] = p[p[u][k-1]][k-1];
    for(auto v:adj[u]){
        if(v!=pai){
            dfs(v,u);
        }
    }
}

int bb(int u, int x){
    for(int k=LOG-1;k>=0;k--){
        if(p[u][k]!=-1 && age[p[u][k]]<=x){
            u = p[u][k];
        }
    }
    return u;
}

void solve(int v, int p){
    for(auto l:queries[v]){
        update(l,1);
    }
    answ[v] = get(age[v]);
    for(auto u:adj[v]){
        if(u!=p){
            solve(u,v);
        }
    }
    for(auto l:queries[v])
        update(l,-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(p,-1,sizeof(p));

    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        age[i] = a;
        adj[b].push_back(i);
    }

    dfs(1,1);
    
    for(int i=0;i<m;i++){
        int o, l, r;
        cin >> o >> l >> r;
        queries[bb(o,r)].push_back(l);
        int u = bb(o,r);
    }

    solve(1,1);
    for(int i=1;i<=n;i++){
        cout << answ[i] << " ";
    }cout<<"\n";

    return 0;
}