#include<bits/stdc++.h>
#define maxn int(5e4+5)
#define maxm 12
#define LOG 20
#define ll long long
using namespace std;

ll n, t, k, answ=0, ht[maxn], cost[maxm], up[maxn][LOG], qtd[maxn];
vector<ll> adj[maxn];

void dfs(int u, int p){
    up[u][0] = p;
    for(int k=1;k<LOG;k++)
        if(up[u][k-1]!=-1)
            up[u][k] = up[up[u][k-1]][k-1];
    if(p!=-1) ht[u] = ht[p]+1;

    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);
}

ll lift(int u, int x){
    for(int k=LOG-1;k>=0;k--){
        if(up[u][k]!=-1 && (1<<k) <= x){
            u = up[u][k];
            x-=(1<<k);
        }
    }
    return u;
}

int lca(int u, int v){
    if(ht[u]>ht[v])
        swap(u,v);
    v = lift(v,ht[v]-ht[u]);
    if(u==v)
        return v;
    for(int k=LOG-1;k>=0;k--){
        if(up[u][k]!=-1 && up[v][k]!=-1 && up[u][k]!=up[v][k]){
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}



int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int x, y;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1);

    cin >> t;
    while(t--){
        cin >> k;
        set<pair<int,int>> st;
        for(int i=1;i<=k;i++){
            cin >> x;
            st.insert({-ht[x],x});
            qtd[x]++;
        }
        if(qtd[1]==0)
            st.insert({-ht[1],1});

        for(int i=1;i<=k;i++){
            cin >> cost[i];
            for(int j=1;j<i;j++)
                cost[i] = min(cost[i],cost[j]+cost[i-j]);
        }

        ht[0] = -1; answ = 0;
        while(st.size()!=1){
            int s = (*st.begin()).second, t = 0, u;
            st.erase(st.begin());        
            for(auto p:st){
                u = lca(s,p.second);
                if(ht[u]>ht[t])
                    t = u;
            }
            

            if(qtd[t]==0 && t!=1)
                st.insert({-ht[t],t});

            qtd[t]+=qtd[s];
            answ += (ht[s]-ht[t])*cost[qtd[s]];
            qtd[s] = 0;
        }
        qtd[1] = 0;
        cout << answ <<'\n';
    }
    return 0;
}