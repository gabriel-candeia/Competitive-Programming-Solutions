#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
        vector<int> parent, rank;
        int cc;
    public:
        DSU(int n){
            parent.assign(n+1,0);
            rank.assign(n+1,0);
            cc = n;
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            return (parent[x]==x) ? x : parent[x] = find(parent[x]);
        }

        void _union(int x, int y){
            x = find(x);
            y = find(y);
            if(x!=y){
                cc--;
                if(rank[x]>rank[y]){
                    parent[y] = x;
                }
                else{
                    parent[x] = y;
                    rank[y] += (rank[x]==rank[y]);
                }
            }
        }

        int comp(){
            return cc;
        }

};

int main(){
    int n, m, q, x, y;
    vector<pair<int,int>> edges;
    vector<pair<int,int>> queries;
    cin >> n >> m;
    DSU alg(n);
    edges.push_back({0,0});
    for(int i=0;i<m;i++){
        cin >> x >> y;
        edges.push_back({x,y});
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> x;
        queries.push_back({edges[x].first,edges[x].second});
        edges[x] = {0,0};
    }
    
    for(int i=0;i<=m;i++){
        alg._union(edges[i].first,edges[i].second);
    }

    vector<int> answ(q,0);
    for(int i=q-1;i>=0;i--){
        answ[i]=alg.comp();
        alg._union(queries[i].first,queries[i].second);
    }

    for(int i=0;i<q-1;i++){
        cout << answ[i] << ' ';
    }cout << answ[q-1] << '\n';

    return 0;
}

