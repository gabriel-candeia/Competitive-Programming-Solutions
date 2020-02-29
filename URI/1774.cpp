#include<bits/stdc++.h>
using namespace std;
#define R 100

vector<tuple<int,int,int> > edges;
int r, c, x, y, z;

class DSU{
    private: vector<int> parent, rank;
    public:
    DSU(int n){
        rank.assign(n,0);
        parent.assign(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int x){
        return ((parent[x]==x) ? x : (parent[x] = find(parent[x])));
    }

    void _union(int x, int y){
        x = find(x);
        y = find(y);
        if(y!=x){
            if(rank[x]>rank[y]){
                parent[y] = x;
            }
            else{
                parent[x] = y;
                rank[y]+=(rank[x]==rank[y]);
            }
        }
    }
};

int kruskal(){
    bool flag[R];
    int cost = 0;
    DSU a(R+10);

    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++){
        if(a.find(get<1>(edges[i]))!=a.find(get<2>(edges[i]))){
            cost += get<0>(edges[i]);
            a._union(get<1>(edges[i]),get<2>(edges[i]));
        }
    }   
    return cost;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    for(int i=0;i<c;i++){
        cin >> y >> z >> x;
        edges.push_back(make_tuple(x,y-1,z-1));
    }
    cout << kruskal() << '\n';
    return 0;
}