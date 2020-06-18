#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
        vector<int> parent, rank, size, zero;
    public:
        DSU(int n, int m, int mat[100][100]){
            parent.assign(n*m,false);
            rank.assign(n*m,false);
            size.assign(n*m,1);
            zero.assign(n*m,false);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    parent[m*i+j] = m*i+j;
                    zero[m*i+j] = mat[i][j];
                }
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
                    zero[x]+=zero[y];
                }
                else{
                    parent[x] = y;
                    rank[y] += (rank[x]+rank[y]);
                    size[y]+=size[x];
                    zero[y]+=zero[x];
                }
            }
        }

        int cnt(int x){
            x = find(x);
            int ret = zero[x];
            zero[x] = 0;
            return min(ret,size[x]-ret);
        }
};


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, mat[100][100], dist[100][100];
        cin >> n >> m;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j];
                dist[i][j] = min(i+j,n-1-i+m-1-j);
            }
        }

        DSU alg(n,m,mat);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int i1=i;i1<n;i1++){
                   for(int j1=j;j1<m;j1++){
                       if(dist[i1][j1]==dist[i][j]){
                           alg._union(m*i+j,m*i1+j1);
                       }
                    }
                }        
            }
        }
        
        int changes=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                changes+=alg.cnt(m*i+j);
            }
        }
        cout << changes << '\n';
    }

    return 0;
}