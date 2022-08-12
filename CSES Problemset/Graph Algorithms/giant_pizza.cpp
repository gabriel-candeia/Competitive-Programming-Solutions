#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

vector<int> adj[maxn], sets[maxn];
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
            sets[cc[u]].push_back(st.top());
            st.pop();
        }
        sets[cc[u]].push_back(u);
        onstack[u] = false;
        st.pop();
    }
}

int visited[maxn], answ[maxn];
vector<int> ord;
void toposort(int u){
    visited[u] = 1;
    for(auto e:sets[u]){
        for(auto v:adj[e]){
            if(!visited[cc[v]]){
                toposort(cc[v]);
            }
        }
    }
    ord.push_back(u);
}

int main(){
    int n, m;
    cin >> m >> n;
    for(int i=0;i<m;i++){
        int u, v;
        char a, b;
    
        cin >> a >> u >> b >> v;
        adj[u+((a=='+') ? n : 0)].push_back(v+(b=='-')*n);
        adj[v+((b=='+') ? n : 0)].push_back(u+(a=='-')*n);
    }

    for(int i=1;i<=2*n;i++){
        if(!lo[i]){
            dfs(i);
        }
    }

    bool ok = true;
    for(int i=1;i<=n;i++){
        ok = (ok && (cc[i]!=cc[i+n]));
    }

    if(!ok){
        cout << "IMPOSSIBLE" <<"\n";
    }
    else{
        for(int i=1;i<=comp;i++){
            if(!visited[i]){
                toposort(i);
            }
        }

        for(auto x:ord){
            for(auto u:sets[x]){
                int v = u - n*(u>n);
                if(!answ[v]){
                    answ[v] = ((u>n) ? -1 : 1);
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout << ((answ[i]==-1) ? '-' : '+') << " ";
        }
        cout<<"\n";
    }

    return 0;
}