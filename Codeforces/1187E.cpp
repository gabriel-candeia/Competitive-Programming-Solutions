#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;


vector<int> adj[maxn];
ll sub[maxn], calc[maxn], answ[maxn];

void precomp(int u, int p){
    sub[u] = 1;
    for(auto v:adj[u])
        if(v!=p)
            precomp(v,u), sub[u] += sub[v], calc[u] += calc[v];
    calc[u]+=sub[u];
}

void trocaRaiz(int u, int v){
    calc[u] -= sub[u];
    sub[u] -= sub[v];
    calc[u] += sub[u];

    calc[u] -= calc[v];

    calc[v]-=sub[v];
    sub[v]+=sub[u];
    calc[v]+=sub[v];

    calc[v]+=calc[u];
}

void solve(int u, int p){
    answ[u] = calc[u];

    for(auto v:adj[u]){
        if(v!=p){
            trocaRaiz(u,v);
            solve(v,u);
            trocaRaiz(v,u);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    precomp(1,-1);
    solve(1,-1);

    ll resp = 0;
    for(int i=1;i<=n;i++){
        resp = max(resp,answ[i]);
        //cout << answ[i] << " ";
    }

    cout << resp <<"\n";

    return 0;
}