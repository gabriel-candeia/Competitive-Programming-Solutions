#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

vector<int> adj[maxn];
int lo[maxn], tempo, onStack[maxn], parent[maxn], tin[maxn];
stack<int> st;

const ll mod = 998244353;

bool solve(int u){
    st.push(u);
    onStack[u] = 1;
    tin[u] = lo[u] = ++tempo;
    bool ret = false;
    for(auto v:adj[u]){
        if(v==parent[u]) continue;
        if(lo[v]==0){
            parent[v] = u;
            ret = ret || solve(v);
            lo[u] = min(lo[u],lo[v]);
        }
        else if(v!=parent[u] && onStack[v]){
            lo[u] = min(lo[u],tin[v]);
        }
    }
    
    if(lo[u]==tin[u]){
        while(st.top()!=u){
            onStack[st.top()] = false;
            lo[st.top()] = tin[u], st.pop();
            ret = true;
        }
        onStack[st.top()] = false;
        st.pop();
    }
    return ret;
}

int main(){
    int n, m;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool poss = true;
    for(int i=1;i<=n;i++)
        if(lo[i]==0)
            poss = poss && solve(i);

    vector<int> visited(n+1,0), deg(n+1,0), ok(n+1,1);
    ll answ = 1;

    for(int i=1;i<=n;i++){
        int qtd = 0;
        deg[lo[i]]++;
        for(auto v:adj[i]){
            qtd+=(lo[v]==lo[i]);
        }
        ok[lo[i]] = (ok[lo[i]]&&(qtd==2));
    }

    /*for(int i=1;i<=n;i++)
        cout << deg[i] << " " << lo[i] <<"\n";*/

    for(int i=1;i<=n;i++){
        if(deg[i]>1){   
            if(ok[i]==false)
                answ = 0;
            answ = (answ*2)%mod;
        }
    }

    if(poss==false)
        answ = 0;
    cout << answ << "\n";

    return 0;
}