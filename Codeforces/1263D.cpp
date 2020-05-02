#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
        vector<int> parent, rank, size;
    public:
        DSU(int n){
            parent.assign(n,0);
            rank.assign(n,0);
            size.assign(n,1);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            return ((x==parent[x]) ? x : (parent[x] = find(parent[x])));
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
                    rank[y]+=(rank[x]==rank[y]);
                }
            }
        }

        int count(){
            int acm=0;
            for(int i=0;i<parent.size();i++){
                acm += (parent[i]==i && size[i]>1);
            }
            return acm;
        }
};

int main(){
    int n;
    string s;
    

    cin >> n;
    
    DSU alg(n+30);
    for(int i=0;i<n;i++){
        cin >> s;
        for(auto c:s){
            alg._union(i+1+'z'-'a',c-'a');
        }
    }

    cout << alg.count() <<'\n';

    return 0;
}