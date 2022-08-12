#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

vector<int> adj[maxn];
int lo[maxn], cc[maxn], onstack[maxn], tempo = 0, comp = 0;
stack<int> st;

void dfs(int u){
    cc[u] = lo[u] = ++tempo;
    onstack[u] = 1;
    st.push(u);

    for(auto v:adj[u]){
        if(!lo[v]){
            dfs(v), lo[u] = min(lo[u],lo[v]);
        }
        else if(onstack[v]){
            lo[u] = min(lo[u],lo[v]);
        }
    }

    if(lo[u]==cc[u]){
        cc[u] = ++comp;
        while(st.top()!=u){
            onstack[st.top()] = false;
            cc[st.top()] = cc[u];
            st.pop();
        }
        onstack[u] = false;
        st.pop();
    }
}

int visited[maxn];
int busca(int u, int x){
    visited[u] = 1;
    if(cc[u]!=x){
        return u;
    }
    int mx = -1;
    for(auto v:adj[u]){
        if(!visited[v]){
            mx = max(mx,busca(v,x));
        }
    }
    return mx;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(!lo[i]){
            dfs(i);
        }
    }

    if(comp==1){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
        int u = busca(1,cc[1]);
        if(u!=-1){
            cout << u << " " << 1 <<"\n";
        }
        else{
            for(int i=1;i<=n;i++)
                if(cc[i]!=cc[1])
                    u = i;
            cout << 1 << " " << u <<"\n";
        }
    }

    return 0;
}