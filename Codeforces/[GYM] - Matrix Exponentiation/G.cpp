#include<bits/stdc++.h>
#define ll long long
#define maxn 15
using namespace std;

const ll mod = 1e9+7;

struct Matrix{
    ll mat[maxn][maxn];
    ll n;

    Matrix(){

    }

    Matrix(int n, bool id=false){
        this->n = n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mat[i][j] = (i==j)*id;
    }

    Matrix operator*(const Matrix& b){
        Matrix c(n);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    c.mat[i][j] = (c.mat[i][j] + (mat[i][k]*b.mat[k][j])%mod)%mod;
        
        return c;
    }
};

ll n, k, p, q, r, c[maxn], a[maxn];
Matrix mat;


ll fexp(ll k){
    if(k<n)
        return a[n-k-1];
    k-=(n-1);   
    Matrix result(n+3,true);
    while(k){
        if(k%2)
            result = result*mat;
        mat = mat*mat;
        k/=2;
    }

    ll answ=0;
    for(int i=0;i<n+3;i++){
        answ = (answ + (result.mat[0][i]*a[i])%mod)%mod;
    }

    return answ;
}

int main(){

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[n-i-1];
    a[n] = 1; a[n+1] = n; a[n+2] = n*n;

    for(int i=0;i<n+3;i++)
        cin >> c[i];

    mat = Matrix(n+3);

    for(int i=0;i<n+3;i++)
        mat.mat[0][i] = c[i];
    
    for(int i=1;i<n;i++)
        mat.mat[i][i-1] = 1;

    mat.mat[n][n] = 1;
    mat.mat[n+1][n] = 1; mat.mat[n+1][n+1] = 1;
    mat.mat[n+2][n] = 1; mat.mat[n+2][n+1] = 2; mat.mat[n+2][n+2] = 1;

    /*for(int i=0;i<n+3;i++){
        for(int j=0;j<n+3;j++)
            cout <<mat.mat[i][j];
        cout <<'\n';
    }*/

    cout << fexp(k) <<'\n';

    return 0;
}