#include<bits/stdc++.h>
#define maxn int(4e5+5)
using namespace std;

int tempo = 0, cccont=0, dgin[maxn], answ=0;
int n, m, cc[maxn], fst[maxn], lo[maxn], onstack[maxn];
vector<int> adj[maxn];
stack<int> st;

int solve(int u){
    lo[u] = fst[u] = ++tempo;
    onstack[u] = 1;
    st.push(u);

    for(auto v:adj[u]){
        if(fst[v]==0){
            solve(v);
            lo[u] = min(lo[u],lo[v]);
        }   
        else if(onstack[v]){
            lo[u] = min(lo[u],lo[v]);
        }
    }

    if(lo[u]==fst[u]){
        cc[u] = ++cccont;
        int compsize=1;
        while(st.top()!=u){
            int v = st.top(); st.pop();
            cc[v] = cc[u];
            onstack[v] = false;
            compsize++;
        }
        onstack[u] = false;
        st.pop();
        answ += 2*compsize-1;
    }

}

int main(){ 
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        dgin[b]++;
    }
    
    for(int i=1;i<=n;i++){
        if(fst[i]==0){
            solve(i);
        }
        answ -= (dgin[i]==0 && adj[i].size()==0);
    }

    cout << answ <<"\n";

    return 0;
}