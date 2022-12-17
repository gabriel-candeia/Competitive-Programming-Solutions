#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define LOG 22
using namespace std;

struct edge {
    int id, u, v, wt;

    int to(int x){
        return x^u^v;
    }
};

int n, m, cnt = 0;
vector<edge> edges;
vector<vector<int>> adj;
vector<int> lo, fst;
vector<int> alive;

vector<int> pcomp, ht, in;
stack<int> st;

void precomp(int u, int p){
    fst[u] = ++cnt;
    lo[u] = fst[u];
    st.push(u);
    
    for(auto eId : adj[u]){
        int v = edges[eId].to(u);   
        if(fst[v]==0){
            precomp(v,u);
            lo[u] = min(lo[v],lo[u]);
        }
        else if(v!=p){
            lo[u] = min(lo[v],lo[u]);
        }
    }

    if(lo[u]==fst[u]){
        while(st.size() && st.top()!=u){
            lo[st.top()] = u;
            st.pop();
        }
        lo[st.top()] = u;
        st.pop();
    }
}

void precompLift(int u, int pai, int pid){
    in[u] = pid;
    pcomp[u] = pai;    
    ht[u] = ((pai!=-1) ? ht[pai]+1 : 0);
    
    for(auto eId:adj[u]){
        int v = edges[eId].to(u);
        if(v!=u && v!=pai)
            precompLift(v,u,eId);
    }
}


int lca(int u, int v){
    if(u==v)
        return u;
    if(ht[v]>ht[u])
        swap(u,v);
    return lca(pcomp[u],v);
}

int mata(int u, int z){
    if(u==-1 || ht[u]<=ht[z])
        return u;
    alive[in[u]] = false;
    int next = pcomp[u];
    assert(pcomp[u]!=u);
    return pcomp[u] = mata(next,z);
}

int main(){ 
    fastio();
    cin >> n >> m;

    adj.assign(n+1,vector<int>());

    for(int i=0;i<m;i++){
        int a, b, wt;
        cin >> a >> b >> wt;
        edges.push_back({i,a,b,wt});
        adj[a].push_back(i);
        adj[b].push_back(i);
    }

    cnt = 0;
    lo.assign(n+1,0);
    fst.assign(n+1,0);
    alive.assign(m+1,0);
    precomp(1,-1);

    priority_queue<pair<int,int>> pq;
    for(int i=0;i<edges.size();i++){
        auto &e = edges[i];
        e.u = lo[e.u];
        e.v = lo[e.v];
        alive[e.id] = (e.u != e.v);
        if(e.u!=e.v){
            adj[e.u].push_back(i);
            adj[e.v].push_back(i);
            pq.push({-e.wt,e.id});
        }
    }
    
    pcomp.assign(n+1,-1);
    ht.assign(n+1,0);
    in.assign(n+1,-1);
    precompLift(lo[1],-1,-1);
    
    int q;
    cin >> q;
    while(q--){
        int u, v, w;
        cin >> u >> v >> w;
        u = lo[u], v = lo[v];
        int z = lca(u,v);
        
        
        mata(u,z);
        mata(v,z);
        //cout << "=>" << pcomp[2] <<"\n";
        
        while(pq.size() && alive[pq.top().second]==false){
            pq.pop();
        }
        if(pq.size()==0){
            cout << -1 << "\n";
        }
        else{
            cout << -pq.top().first << "\n";
        }
    }
    exit(0);
    return 0;
}