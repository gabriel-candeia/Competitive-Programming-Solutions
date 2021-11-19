#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(2e6+5)
#define ll long long
using namespace std;

vector<int> adj[maxn];
ll valor[maxn], visited[maxn];

array<ll,3> solve(int u){
    ll answ = valor[u]*((int)adj[u].size()-1), arestas = adj[u].size(), tamanho = 1;
    visited[u] = 1;
    for(auto v:adj[u]){
        if(!visited[v]){
            auto p = solve(v);
            answ += p[0], arestas+= p[1], tamanho+=p[2];
        }
    }
    return array<ll,3>{answ,arestas,tamanho};
}

int main(){
    fastio();
    map<int,int> compress;
    vector<pair<int,int>> edges;

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
        compress[a], compress[b];
    }

    int cnt = 0;
    for(auto &p:compress){
        p.second = ++cnt;
        valor[p.second] = p.first;
    }

    for(auto e:edges){
        adj[compress[e.first]].push_back(compress[e.second]);
        adj[compress[e.second]].push_back(compress[e.first]);
    }

    ll answ = 0;
    for(int i=cnt;i>=1;i--){
        if(!visited[i]){
            auto p = solve(i);
            if(p[1]/2 == p[2]-1){
                p[0] += valor[i];
            }
            answ += p[0];
        }
    }

    cout << answ << "\n";

    return 0;
}