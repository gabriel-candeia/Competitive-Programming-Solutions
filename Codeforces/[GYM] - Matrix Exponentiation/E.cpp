#include<bits/stdc++.h>
#define ll long long
#define maxn 105
using namespace std;

const ll mod = 1ll<<32;

struct Matrix{
    ll mat[maxn][maxn], n;

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
                    c.mat[i][j] = (c.mat[i][j] + ((mat[i][k])*(b.mat[k][j]))%mod)%mod;
        
        return c;
    }       

    ll sum(){
        ll acm=0;
        for(int i=0;i<n;i++)
                acm = (acm + mat[0][i])%mod;
        return acm;
    }

};

ll n = 64;
Matrix mat(64);
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

bool isok(int i, int j){
    return i>=0 && j>=0 && i<8 && j<8;
}

int main(){
    ll k;
    int dx[8] = {1,1,-1,-1,2,2,-2,-2}, dy[8] = {2,-2,2,-2,1,-1,1,-1};

    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            mat.mat[i*8+j][i*8+j] = 1;

    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            for(int k=0;k<8;k++)
                if(isok(i+dx[k],j+dy[k]))
                    mat.mat[i*8+j][(i+dx[k])*8+j+dy[k]]++;

    cin >> k;
    cout << fexp(k) <<'\n';
    return 0;
}
