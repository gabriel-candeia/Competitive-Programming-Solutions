#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

int n;
vector<int> adj[maxn];
ll calc[maxn], sub[maxn], answ = 1e17;
vector<string> nomes;

void precomp(int u, int p){
    sub[u] = (adj[u].size()==1 && p!=-1);

    for(auto v:adj[u]){
        if(v!=p){
            precomp(v,u);
            calc[u]+=calc[v]+sub[v]*(nomes[v].size());
            sub[u]+=sub[v];
        }
    }
}

void trocaRaiz(int u, int v, bool flag){
    calc[u]-=sub[v]*(nomes[v].size());
    sub[u]-=sub[v];
    calc[u]-=calc[v];

    calc[v]+=calc[u]+sub[u]*(nomes[u].size());
    sub[v]+=sub[u];
}

void solve(int u, int p){
    answ = min(answ,calc[u]);

    for(auto v:adj[u]){
        if(v!=p){
            string old = nomes[u];
            nomes[u] = "../";
            trocaRaiz(u,v,1);
            solve(v,u);
            trocaRaiz(v,u,0);
            nomes[u] = old;
        }
    }

}

int main(){
    ifstream in("dirtraverse.in");
    ofstream out("dirtraverse.out");
    in >> n;
    nomes.assign(n+1,"");

    for(int i=1;i<=n;i++){
        int m;
        in >> nomes[i] >> m;
        if(m!=0)
            nomes[i]+="/";
        for(int j=0;j<m;j++){
            int b;
            in >> b;
            adj[i].push_back(b);
            adj[b].push_back(i);
        }
    }

    precomp(1,-1);
    //cout << calc[1] <<"\n";
    solve(1,-1);

    out << answ <<"\n";

    return 0;
}