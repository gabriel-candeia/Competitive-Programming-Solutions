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
            return (parent[x] == x) ? x : parent[x] = find(parent[x]);
        }

        void _union(int x, int y){
            x = find(x); y = find(y);
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
    int n, x, m, z;
    vector<int> ord;

    cin >> n;
    ord.assign(n+1,0);
    DSU alg(n);
    for(int i=1;i<=n;i++){
        cin >> ord[i];
    }
    cin >> m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> z;
            alg._union(j,z);
        }
    }
    cin >> x;
    bool answ = false;
    for(int i=1;i<=n;i++){
        if(x==ord[i]){
            answ = (alg.find(i) == alg.find(1));
        }
    }

    cout << ((answ) ? "YES" : "NO") << '\n';

    return 0;   
}