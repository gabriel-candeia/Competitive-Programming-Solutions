#include<bits/stdc++.h>
#define ld long double
#define ll long long
#define maxn 5
using namespace std;

class Matrix{
    public:
    int n;
    ld mat[maxn][maxn];

    Matrix(int n, bool id=false){
        this->n = n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mat[i][j] = (i==j)*id;
    }

    Matrix(int n, ld mat[maxn][maxn]){
        this->n = n;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                this->mat[i][j] = mat[i][j];
    }

    Matrix operator*(const Matrix& b){
        Matrix c = Matrix(n);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<2;k++)
                    c.mat[i][j] += (mat[i][k]*b.mat[k][j]);

        return c;
    }
};  

ll n; ld p;
ld fastexp(ll n){
    ld mat[maxn][maxn] = {{(1-p),p},{p,1-p}};
    Matrix result(2,true), m(2,mat);

    while(n){
        if(n%2)
            result = result*m;
        m = m*m;
        n/=2;
    }

    return result.mat[0][0];
}

int main(){
    cout.precision(10);  
    cin >> n >> p;
    cout << fixed << fastexp(n) << '\n';

    return 0;
}