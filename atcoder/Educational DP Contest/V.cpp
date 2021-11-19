#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e5+5)
using namespace std;

ll n, mod;
vector<ll> adj[maxn], aux[maxn];
ll calc[maxn], answ[maxn];

void precomp(int u, int p){
    calc[u] = 1;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(v==p && i!=adj[u].size()-1){
            swap(adj[u][i],adj[u][adj[u].size()-1]);
            v = adj[u][i];
        }
        if(v!=p){
            precomp(v,u), calc[u] = (calc[u]*(calc[v]+1))%mod;
        }
    }
    if(p!=-1)
        adj[u].pop_back();
}

void solve(int u, int p){
    answ[u] = calc[u];

    ll acm = (p!=-1) ? ((calc[p]+1)%mod) : 1;

    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(v!=p){
            ll old = calc[v];
            calc[u] = (acm*aux[u][i+1])%mod;
            calc[v] = (calc[v]*(calc[u]+1))%mod;
            solve(v,u);
            calc[v] = old;
            acm = (acm*(calc[v]+1))%mod;
        }
    }
}

int main(){
    cin >> n >> mod;
    
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    precomp(1,-1);
    for(int i=1;i<=n;i++){
        for(auto v:adj[i])
            aux[i].push_back((calc[v]+1)%mod);
        aux[i].push_back(1);
        for(int j=aux[i].size()-2;j>=0;j--)
            aux[i][j] = (aux[i][j]*aux[i][j+1])%mod;
    }

    solve(1,-1);
    
    for(int i=1;i<=n;i++)
        cout << answ[i] << "\n";
    return 0;
}