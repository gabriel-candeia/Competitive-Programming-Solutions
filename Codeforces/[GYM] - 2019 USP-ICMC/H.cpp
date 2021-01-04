#include<bits/stdc++.h>
#define maxn 9
#define ll long long
using namespace std;

const ll mod = 1e9+7;

struct Matrix{
    ll mat[maxn][maxn];

    Matrix(bool id=false){
        for(int i=0;i<maxn;i++)
            for(int j=0;j<maxn;j++)
                mat[i][j] = (i==j)*id;
    }

    Matrix operator*(Matrix b){
        Matrix c;
        for(int i=0;i<maxn;i++)
            for(int j=0;j<maxn;j++)
                for(int k=0;k<maxn;k++)
                    c.mat[i][j] = (c.mat[i][j] + (mat[i][k]*b.mat[k][j])%mod)%mod;
        return c;
    }
};

Matrix mat;
ll binpow(ll n){
    Matrix result(true);
    n-=2;
    while(n){
        if(n%2)
            result = result*mat;
        mat = mat*mat;
        n/=2;
    }
    ll answ = 0;
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            //cout << result.mat[i][j] << " ";
            answ = (answ+(result.mat[i][j])%mod)%mod;
        }
        //cout<< '\n';
    }
    return answ;
}

int main(){
    ll coef[maxn][maxn], n;
    memset(coef,0,sizeof(coef));
    coef[0][0] = coef[0][1] = coef[0][2] = 1;
    coef[1][3] = coef[1][4] = coef[1][5] = 1;
    coef[2][6] = coef[2][7] = coef[2][8] = 1;
    coef[3][0] = 1;
    coef[4][3] = coef[4][4] = 1;
    coef[5][6] = coef[5][7] = coef[5][8] = 1;
    coef[6][0] = 1;
    coef[7][3] = 1;
    coef[8][6] = coef[8][7] = coef[8][8] = 1;
    cin >> n;
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            mat.mat[i][j] = coef[i][j];
    
    cout <<  binpow(n) << '\n';
    return 0;
}