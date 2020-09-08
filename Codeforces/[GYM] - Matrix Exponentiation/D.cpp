#include<bits/stdc++.h>
#define maxn 105
#define ll long long
using namespace std;

const ll mod = 1000000007;

struct Matrix{
    ll mat[maxn][maxn], n;

    Matrix(){

    }

    Matrix(int n, bool id = false){
        this->n = n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mat[i][j] = (i==j)*id;
    }

    Matrix operator*(const Matrix& b){
        Matrix c = Matrix(n);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    c.mat[i][j] = (c.mat[i][j] + (mat[i][k]*b.mat[k][j])%mod)%mod;
        
        return c;
    }

    ll sum(){
        ll acm=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                acm = (acm+mat[i][j])%mod;
        return acm;
    }
};

ll n, m, k;
Matrix mat;
ll fexp(ll k){
    Matrix result(n,true);

    while(k){
        if(k%2)
            result = result*mat;
        mat = mat*mat;
        k/=2;
    }

    return result.sum();
}

int main(){
    cin >> n >> m >> k;

    int x, y;
    mat = Matrix(n);
    while(m--){
        cin >> x >> y;
        mat.mat[x-1][y-1]++;
    }

    cout << fexp(k) << '\n';

    return 0;
}
