#include<bits/stdc++.h>
#define N 105
using namespace std;

const int mod = 10000;

class Matrix{
    public:
    int mat[N][N];
    int n;

    Matrix(int x, bool identity=false){
        n = x;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                mat[i][j] = (i==j)*identity;
            }
        }
    }

    Matrix operator *(Matrix const& m){
        Matrix answ(n);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                answ.mat[i][j] = 0;
                for(int k=0;k<=n;k++){
                    answ.mat[i][j] = (answ.mat[i][j]+mat[i][k]*m.mat[k][j])%mod;
                }       
            }   
        }
        return answ;
    }
};

int binpow(Matrix& adj, int l, int s, int t){
    Matrix result(adj.n,true);
    while(l){
        if(l%2)
            result = result*adj;
        adj = adj*adj;
        l/=2;
    }
    return result.mat[s][t];;
}

int main(){
    int n, l, s, t, a;

    while(cin >> n >> l){
        Matrix adj(n);
        cin >> s >> t;
        for(int i=1;i<=n;i++){
            for(int j=0;j<4;j++){
                cin >> a;
                adj.mat[i][a]++;
            }    
        }
        
        cout << binpow(adj,l,s,t) << '\n';
    }

    return 0;
}