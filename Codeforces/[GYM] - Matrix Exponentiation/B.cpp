#include<bits/stdc++.h>
#define maxn 2
#define ll long long
using namespace std;

const ll mod = 1e9+7;

class Matrix{
    public:
    ll n;
    ll mat[maxn][maxn];

    Matrix(int n, bool id=false){
        this->n = n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mat[i][j] = (i==j)*id;
    }           

    Matrix(int n, ll mat[maxn][maxn]){
        this->n = n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                this->mat[i][j] = mat[i][j];
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

ll fastexp(ll n){
    ll mat[2][2] = {{19,6},{7,20}};
    Matrix result(2,true), x(2,mat);

    while(n){
        if(n%2)
            result = result*x;
        x=x*x;
        n/=2;
    }

    return result.mat[0][0];
}

int main(){
    ll n;

    cin >> n;
    cout << fastexp(n) <<'\n';
    return 0;
}