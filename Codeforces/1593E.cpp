#include<bits/stdc++.h>
#define maxn int(4e5+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n, k;
vector<int> adj[maxn];

int descasca(int k){
    int cnt = 0, answ = n;    
    vector<int> dg(n+1,0);
    vector<int> atual, proxima;


    for(int i=1;i<=n;i++){
        dg[i] = adj[i].size();
        if(adj[i].size()<=1)
            atual.push_back(i), dg[i] = -1;
    }

    for(int i=0;i<k;i++){
        answ = (answ-(int)atual.size());
        for(auto u:atual) for(auto v:adj[u]) if(dg[v]!=-1){dg[v]--; if(dg[v]==1) dg[v] = -1, proxima.push_back(v);}
        atual.clear();
        swap(atual,proxima);
        if(atual.size()==0) break;
    }

    return answ;
}

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=0;i<n-1;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout << descasca(k) << "\n";
        for(int i=1;i<=n;i++){
            adj[i].clear(); 
        }
    }

    return 0;
}