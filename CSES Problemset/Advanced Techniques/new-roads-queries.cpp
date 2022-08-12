#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(2e5+5)
using namespace std;

struct DSU{
    vector<int> p, rnk;

    DSU(int n){
        p.assign(n+1,0), rnk.assign(n+1,0);
        for(int i=0;i<=n;i++) p[i] = i;
    }

    int find(int x){
        return ((x==p[x]) ? x : p[x] = find(p[x]));
    }

    bool same(int x, int y){
        return find(x)==find(y);
    }

    void _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            if(rnk[x]>rnk[y]) swap(x,y);
            p[x] = y;
            rnk[y] += rnk[x]==rnk[y];
        }
    }
};

int n, m, q;
vector<pair<int,int>> edges;

struct Query{
    int id, a, b, l, r;

    int getmid(){
        return l + (r-l)/2;
    }
};

vector<Query> queries[maxn];
vector<int> answ;

void solve(){
    const int LOG = 20;
    for(int iter=0;iter<LOG;iter++){
        DSU st(n+1);
        for(int i=0;i<edges.size();i++){
            st._union(edges[i].first,edges[i].second);
            while(queries[i].size()){
                auto query = queries[i].back(); queries[i].pop_back();
                if(st.same(query.a,query.b)){
                    answ[query.id] = i+1;
                    query.r = i-1;
                }
                else{
                    query.l = i+1;
                }
                if(query.l<=query.r)
                    queries[query.getmid()].push_back(query);
            }
        }
    }
}

int main(){
    fastio();
    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
    }

    answ.assign(q,-1);
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        Query query = {i,a,b,0,m-1};
        if(a==b)
            answ[query.id] = 0;
        else
            queries[query.getmid()].push_back(query);
    }
    
    solve();

    for(int i=0;i<q;i++){
        cout << answ[i] << "\n";
    }

    return 0;
}