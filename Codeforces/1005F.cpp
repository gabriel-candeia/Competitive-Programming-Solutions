#include<bits/stdc++.h>
using namespace std;

int qtd=0, n, m, k, x, y;
vector<vector<pair<int,int>>> adj;
vector<bool> answ;
vector<vector<int>> op, mod;

void imprime(){
    for(auto x:answ){
        cout << x;
    }cout << '\n';
}

void alg(int u){
    vector<int> dist(n,0);
    queue<int> q;
    op.assign(n,vector<int>());

    dist[u] = 1;
    q.push(u);

    while(q.size()){
        u = q.front(); q.pop();

        for(auto v:adj[u]){
            if(dist[v.first]==0){
                dist[v.first] = dist[u] +1;
                q.push(v.first);
                op[v.first].push_back(v.second);
            }
            else if(dist[v.first]==dist[u]+1){
                op[v.first].push_back(v.second); 
            }
        }
    }

    for(int i=1;i<n;i++){
        if(op[i].size()==1){
            answ[op[i][0]] = 1;
        }
        else if(op[i].size()>1){
            mod.push_back(op[i]);
        }
    }

    qtd = 1;
    for(auto v:mod){
        qtd = min(k,qtd*int(v.size()));
    }
}

void perm(int i){
    if(i==mod.size()){
        imprime();
        qtd--;
        return;
    }
    for(auto x:mod[i]){
        answ[x] = 1;
        perm(i+1);
        if(qtd==0) return;
        answ[x] = 0;
    }
}


int main(){
    cin >> n >> m >> k;
    adj.assign(n+1,vector<pair<int,int>>());
    answ.assign(m,0);
    n++; n++;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
    }

    alg(1);
    cout << qtd << '\n';
    perm(0);

    return 0;
}