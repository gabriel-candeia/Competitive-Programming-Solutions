#include<bits/stdc++.h>
#define ll long long
#define maxn 2
using namespace std;

const ll mod = 1e9+7;

struct Matrix{
    ll mat[maxn][maxn], n;

    Matrix(int n, bool id=false){
        this->n=n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mat[i][j] = (i==j)*id;
    }

    Matrix(int n, ll mat[maxn][maxn]){
        this->n=n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                this->mat[i][j] = mat[i][j];
    }

    ll* operator[](int i){
        return mat[i];
    }

    Matrix operator*(Matrix& b){
        Matrix c = Matrix(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    c.mat[i][j] = (c[i][j] + (mat[i][k]*b[k][j])%mod)%mod;
        return c;
    }   
};

ll fexp(ll n){
    if(n<=1)
        return n;
    ll mat[maxn][maxn] = {{1,1},{1,0}};
    Matrix result(2,true), x(2,mat);
    n-=1;
    while(n){
        if(n%2)
            result = result*x;
        x=x*x;
        n/=2;
    }
    return result[0][0];
}

int main(){
    
    ll n;

    cin >> n;
    cout << fexp(n) <<'\n';

    return 0;
}