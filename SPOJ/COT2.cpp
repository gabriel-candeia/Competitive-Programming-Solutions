#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define block 300
#define LOG 20
using namespace std;

struct query{
    int l, r, id, k;

    query(int l, int r, int id, int k){
        this->l = l, this->r = r, this->id = id, this->k = k;
    }

    bool operator<(query x){
        return pair<int,int>{l/block,r} < pair<int,int>{x.l/block,x.r};
    }
};

int n, m;
int parent[maxn][20], ht[maxn];
vector<int> wt, fst, lst, arr, adj[maxn],answ;

void dfs(int u, int p){
    fst[u] = arr.size();
    arr.push_back(u);

     ht[u] = ((p!=-1) ? ht[p]+1 : 0);
    parent[u][0] = p;
    for(int k=1;k<LOG && parent[u][k-1]!=-1;k++)
        parent[u][k] = parent[parent[u][k-1]][k-1];

    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);

    lst[u] = arr.size();
    arr.push_back(u);
}

int lift(int u, int h){
    for(int k=LOG-1;k>=0;k--)
        if(h>=(1<<k))
            u = parent[u][k], h-=(1<<k);
    return u;
}

int lca(int u, int v){
    if(ht[u]<ht[v])
        swap(u,v);
    u = lift(u,ht[u]-ht[v]);
    if(u==v) 
        return u;
    for(int k=LOG-1;k>=0;k--)
        if(parent[u][k]!=parent[v][k])
            u = parent[u][k], v = parent[v][k];
    return parent[u][0];
}

int main(){
    while(cin >> n >> m){
        int compress_aux=0;
        map<int,int> compress;

        wt.assign(n+1,0), fst.assign(n+1,0), lst.assign(n+1,0), arr.clear();
        for(int i=1;i<=n;i++){
            cin >> wt[i];
            compress[wt[i]];
        }

        memset(parent,-1,sizeof(parent));

        for(auto &p:compress)
            p.second = compress_aux++;

        for(int i=1;i<=n;i++)
            wt[i] = compress[wt[i]];

        for(int i=1, x, y;i<=n-1;i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1,-1);
        vector<query> queries;
        for(int i=0,u,v;i<m;i++){
            cin >> u >> v;
            if(fst[u]>fst[v])
                swap(u,v);
            if(lst[v]<lst[u])
                queries.push_back(query(fst[u],fst[v],i,0));
            else
                queries.push_back(query(lst[u],fst[v],i,1));
        }

        sort(queries.begin(),queries.end());
        vector<int> aux(n+1,0), cnt(n+1,0), answ(m,0);
        int l = 0, r = -1, acm=0, inc = 0;
        for(auto q:queries){
             while(l<q.l){
                if(aux[arr[l]]==1) cnt[wt[arr[l]]]--, acm-=(cnt[wt[arr[l]]]==0);
                else cnt[wt[arr[l]]]++, acm+=(cnt[wt[arr[l]]]==1);
                aux[arr[l]]^=1;
                l++;
            }
            while(r<q.r){
                r++;
                if(aux[arr[r]]==1) cnt[wt[arr[r]]]--, acm-=(cnt[wt[arr[r]]]==0);
                else cnt[wt[arr[r]]]++, acm+=(cnt[wt[arr[r]]]==1);
                aux[arr[r]]^=1;
            }
            while(q.l<l){
                l--;
                if(aux[arr[l]]==1) cnt[wt[arr[l]]]--, acm-=(cnt[wt[arr[l]]]==0);
                else cnt[wt[arr[l]]]++, acm+=(cnt[wt[arr[l]]]==1);
                aux[arr[l]]^=1;
            }
            while(q.r<r){
                if(aux[arr[r]]==1) cnt[wt[arr[r]]]--, acm-=(cnt[wt[arr[r]]]==0);
                else cnt[wt[arr[r]]]++, acm+=(cnt[wt[arr[r]]]==1);
                aux[arr[r]]^=1;
                r--;
            }
            
            answ[q.id] = acm + (cnt[wt[lca(arr[q.l],arr[q.r])]]==0);
        }

        for(auto x:answ)
            cout << x << "\n";

        for(int i=1;i<=n;i++)
            adj[i].clear();
    }
    return 0;
}


