#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e5+5)
using namespace std;

vector<int> adj[maxn], sets[maxn];
int lo[maxn], cc[maxn], onstack[maxn], tempo = 0, comp = 0;
ll att[maxn], coins[maxn];
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
        coins[cc[u]]+=att[u];
        while(st.top()!=u){
            onstack[st.top()] = false;
            cc[st.top()] = cc[u];
            sets[cc[u]].push_back(st.top());
            coins[cc[u]]+=att[st.top()];
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
    cin >> n >> m;

    for(int i=1;i<=n;i++)
        cin >> att[i];

    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        if(!lo[i]){
            dfs(i);
        }
    }

    for(int i=1;i<=comp;i++){
        if(!visited[i]){
            toposort(i);
        }
    }

    ll answ = 0;
    vector<ll> best(n+1,0);
    reverse(ord.begin(),ord.end());
    for(auto x:ord){
        best[x] += coins[x];
        for(auto u:sets[x]){
            for(auto v:adj[u]){
                if(cc[v]!=x){
                    best[cc[v]] = max(best[cc[v]],best[x]);
                }
            }
        }
        answ = max(answ,best[x]);
    }

    cout << answ <<"\n";

    return 0;
}