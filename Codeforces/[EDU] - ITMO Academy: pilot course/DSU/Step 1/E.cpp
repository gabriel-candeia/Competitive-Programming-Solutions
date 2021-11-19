#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

struct DSU{
    vector<int> parent, rnk;

    DSU(int n){
        parent.assign(n+1,0);
        for(int i=1;i<=n;i++)
            parent[i] = i;
        rnk.assign(n,0);
    }

    int find(int x){
        return (x==parent[x]) ? x : parent[x] = find(parent[x]);
    }

    void _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            if(rnk[x]<rnk[y]){
                parent[x] = y;
            }
            else{
                parent[y] = x;
                rnk[x] += (rnk[y]==rnk[x]);
            }
        }
    }
};

vector<int> adj[maxn];
int edges[maxn][2], flag[maxn][2], answ[maxn];

void mata(int u, int t){
    answ[u] = t;
    for(auto v:adj[u]){
        if(answ[v]==0){
            mata(v,t);
        }
    }
}

int main(){
    int n, m;

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<pair<int,int>> queries(m,{0,0});
    for(int i=0;i<m;i++){
        cin >> queries[i].first >> queries[i].second;
        queries[i].second--;
        flag[queries[i].first][queries[i].second] = 1;
    }
    
    DSU st(n);
    
    for(int i=1;i<=n;i++){
        for(int k=0;k<2;k++){
            if(edges[i][k]!=-1 && flag[i][k]==0){
                adj[i].push_back(edges[i][k]);
                adj[edges[i][k]].push_back(i);
                st._union(i,edges[i][k]);
            }
        }
    }
    
    answ[1] = -1;
    for(int i=m-1;i>=0;i--){
        int u = queries[i].first, v = edges[queries[i].first][queries[i].second];
        if(st.find(u)!=st.find(v)){
            if(st.find(u)==st.find(1)){
                mata(v,i+1);
            }
            else if(st.find(v)==st.find(1)){
                mata(u,i+1);
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
            st._union(u,v);
        }
    }

    for(int i=1;i<=n;i++){
        cout << ((answ[i]==-1) ? -1 : answ[i]-1 )<< "\n";
    }

    return 0;
}