#include<bits/stdc++.h>
#define maxn int(101)
#define ll long long
using namespace std;

const ll mod = 1e9+7;
struct matrix{
    vector<vector<ll>> mat;

    matrix(bool id=false){
        mat.assign(maxn,vector<ll>(maxn,0));
        for(int i=0;i<maxn;i++)
            mat[i][i] = id;
    }

    matrix operator*(const matrix &o){
        matrix c;

        for(int i=0;i<maxn;i++){
            for(int j=0;j<maxn;j++){
                for(int k=0;k<maxn;k++){
                    c.mat[i][j] = (c.mat[i][j] + mat[i][k]*o.mat[k][j])%mod;
                }
            }
        }

        return c;
    }
};

ll fexp(matrix x, int k){
    matrix result(true);
    for(;k;k/=2){
        if(k&1)
            result = result*x;
        x = x*x;
    }
    ll answ = 0;
    for(int j=0;j<maxn;j++)
        answ = (answ + result.mat[1][j])%mod;
    return answ;
}

int main(){
    int n, m, k;
    matrix adj;

    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj.mat[a][b]=1;
        adj.mat[b][a]=1;
    }

    cout << fexp(adj,k) <<"\n";

    return 0;
}