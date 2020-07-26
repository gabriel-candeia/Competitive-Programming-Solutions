#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
        vector<int> parent, rank;
    public:
        DSU(int n){
            parent.assign(n+1,0);
            rank.assign(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            return ((parent[x]==x) ? x : (parent[x] = find(parent[x])));
        }

        void _union(int x, int y){
            x = find(x);
            y = find(y);
            if(x!=y){
                if(rank[x] > rank[y]){
                    parent[y] = x;
                }
                else{
                    parent[x] = y;
                    rank[y] += (rank[x]==rank[y]);
                }
            }
        }
};

int main(){
    int t, n, m, k, x, y, w, cnt=0;
    cin >> t;
    while(t--){
        cnt++;
        cin >> n >> m >> k;
        DSU alg(n); x = 0;
        vector<tuple<int,int,int>> edges;
        for(int i=0;i<k;i++){
            cin >> y;
            alg._union(x,y);
            x = y;
        }

        for(int i=0;i<m;i++){
            cin >> x >> y >> w;
            edges.push_back({w,x,y});
        }
        sort(edges.begin(),edges.end());
        int answ=0;
        for(auto p:edges){
            tie(w,x,y) = p;
            if(alg.find(x)!=alg.find(y)){
                alg._union(x,y);
                answ+=w;
            }
        }

        cout << "Case #" << cnt << ": " << answ << '\n';
    }


    return 0;
}
