#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
        int n;
        vector<int> parent, rank, size;

        DSU(int x){
            n = x;
            parent.assign(n+1,0);
            rank.assign(n+1,0);
            size.assign(n+1,1);
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
                if(rank[x]>rank[y]){
                    parent[y] = x;
                    size[x]+=size[y];
                }
                else{
                    parent[x] = y;
                    size[y]+=size[x];
                    rank[y] += (rank[x]==rank[y]);
                }
            }
    }

    int mx(){
        int answ=0;
        for(auto p:size){
            answ = max(answ,p);
        }
        return answ;
    }
};

int main(){
    int n, m, a, b;

    cin >> n >> m;
    DSU alg(n);
    for(int i=0;i<m;i++){
        cin >> a >> b;
        alg._union(a,b);
    }

    cout << alg.mx() << '\n';

    return 0;
}
