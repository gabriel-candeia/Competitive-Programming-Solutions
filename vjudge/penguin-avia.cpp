#include<bits/stdc++.h>
#define ll long long
using namespace std;

class DSU{
    public:
        vector<int> parent, rank;

        DSU(int n){
            parent.assign(n+1,0);
            rank.assign(n+1,0);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            return (parent[x] == x) ? x : parent[x] = find(parent[x]);
        }

        void _union(int x, int y){
            x = find(x);
            y = find(y);
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

int main(){
    ll n, d, a, cost=0;
    char mat[120][120];
    
    cin >> n >> d >> a;
    DSU alg(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
        }   
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]=='1' && alg.find(i)==alg.find(j)){
                mat[i][j] = 'd';
                mat[j][i] = 'd';
                cost+=d;
            }
            else if(mat[i][j]=='1'){
                alg._union(i,j);
                mat[i][j] = '0';
                mat[j][i] = '0';
            }
        }    
    }

    for(int i=0;i<n;i++){
        if(alg.find(i)!=alg.find(0)){
            alg._union(i,0);
            cost+=a;
            mat[i][0] = 'a';
            mat[0][i] = 'a';
        }
    }

    cout << cost << '\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << mat[i][j];
        }   
        cout << '\n';
    }

    return 0;
}
