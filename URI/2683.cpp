#include<bits/stdc++.h>
using namespace std;

class DSU{
    private: vector<int> parent, rank;
    public:
        DSU(int n){
            rank.assign(n+1,0);
            parent.assign(n+1,0);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            return ((x==parent[x]) ? x : (parent[x] = find(parent[x])));
        }

        int _union(int x, int y){
            x = find(x); y = find(y);
            if(x!=y){
                if(rank[x]>rank[y]){
                    parent[y] = x;
                }
                else{
                    parent[x] = y;
                    rank[y] += (rank[x]==rank[y]);
                }
            }
        }
};

int kruskal(vector<pair<int,pair<int,int>>> edges, int n, bool rev){
    int cost = 0;
    DSU dsu(1001);
    for(auto i:edges){
        if(dsu.find(i.second.first)!=dsu.find(i.second.second)){
            dsu._union(i.second.first,i.second.second);
            cost+=i.first;
        }
    }
    return cost;
}

int kruskal1(vector<pair<int,pair<int,int>>> edges, int n, bool rev){
    int cost = 0;
    DSU dsu(1001);
    for(int i = edges.size()-1;i>=0;i--){ 
        if(dsu.find(edges[i].second.first)!=dsu.find(edges[i].second.second)){
            dsu._union(edges[i].second.first,edges[i].second.second);
            cost+=edges[i].first;
        }
    }
    return cost;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, u, v, w;
    vector<pair<int,pair<int,int>>> edges;

    cin >> n;
    while(n--){
        cin >> u >> v >> w;
        edges.push_back(make_pair(w,make_pair(v,u)));
    }
    sort(edges.begin(),edges.end());
    cout << kruskal1(edges,n,true) << "\n";
    cout << kruskal(edges,n,true) << "\n";

    return 0;
}
