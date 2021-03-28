#include <bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int n, rem[maxn], siz[maxn], num[maxn], id[maxn];
stack<int> st[maxn];
vector<int> adj[maxn];
vector<pair<int,int>> answ;

void dfs(int u){
    if(id[u]==1)
        answ.push_back({u,st[rem[u]].top()});
    else
        st[siz[u]].push(num[u]);

    for(auto v:adj[u])
        dfs(v);
    
    if(id[u]==0)
        st[siz[u]].pop();
}

int main(){
    cin >> n;

    char op;    
    for(int i = 1, x, y; i <= n; i++){
        cin >> op;
        if(op == 'E'){
            cin >> x >> y;
            num[i] = y;
            adj[x].push_back(i);
            siz[i] = siz[x] + 1;
            rem[i] = rem[x];
        }else{
            cin >> x;
            id[i] = 1;
            adj[x].push_back(i);
            siz[i] = siz[x];
            rem[i] = rem[x]+1;
        }
    }    

    dfs(0);
    sort(answ.begin(),answ.end());

    for(auto p:answ)
        cout << p.second << "\n";

    return 0;
}