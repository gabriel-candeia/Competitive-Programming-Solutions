#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e4+5)
using namespace std;

vector<int> adj[maxn];
int lo[maxn], cc[maxn], size[maxn], visited[maxn], isonstack[maxn];
vector<int> st, ord;
int n, m, x, y, cnt;

void dfs(int u){
    st.push_back(u);
    lo[u] = cc[u] = ++cnt;
    isonstack[u] = 1;
    visited[u] = 1;

    for(auto v:adj[u]){
        if(!visited[v])
            dfs(v);
        if(isonstack[v])
            lo[u] = min(lo[u],lo[v]);
    }

    if(lo[u]==cc[u]){
        while(isonstack[u]){
            int v = st.back(); st.pop_back(); 
            isonstack[v] = 0; 
            cc[v] = cc[u]; 
            size[cc[u]]++;
        }
        ord.push_back(u);
    }
}

void dfs2(int u){
    size[cc[u]] = 0;
    visited[u] = 1;
    for(auto v:adj[u])
        if(!visited[v])
            dfs2(v);
}


int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
    }
    
    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs(i);

    
    memset(visited,0,sizeof(visited));
    int answ = 0;
    while(ord.size()){
        if(size[cc[ord.back()]]<=3)
            answ += size[cc[ord.back()]];
        else
            dfs2(ord.back());
        ord.pop_back();
    }
    cout << answ <<'\n';
    return 0;
}