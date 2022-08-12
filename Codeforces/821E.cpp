#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

struct Matrix{
    int n;
    vector<vector<ll>> mat;

    Matrix(int pn, bool id=false){
        n = pn;
        mat.assign(n,vector<ll>(n,0));
        if(id) for(int i=0;i<n;i++) mat[i][i] = 1;
    }

    Matrix operator*(const Matrix& o){
        Matrix c(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    c.mat[i][j] = (c.mat[i][j] + mat[i][k]*o.mat[k][j])%mod;
        return c;
    }

    vector<ll> operator*(const vector<ll>& o){
        vector<ll> answ(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                answ[i] = (answ[i] + mat[i][j]*o[j])%mod;
            }
        }
        return answ;
    }
};

Matrix exp(Matrix m, ll k){
    Matrix answ(m.n,true);
    for(;k;k>>=1){
        if(k&1){
            answ = answ*m;
        }
        m = m*m;
    }
    return answ;
}

Matrix gerar(ll n, ll c){
    Matrix answ(n);
    if(c==0){
        answ.mat[0][0] = 1;
    }
    else{
        answ.mat[0][0] = answ.mat[0][1] = 1;
        for(int i=1;i<c;i++)
            answ.mat[i][i-1] = answ.mat[i][i] = answ.mat[i][i+1] = 1;
        answ.mat[c][c] = answ.mat[c][c-1] = 1;
    }
    return answ;
}

int main(){
    ll n, k;
    vector<array<ll,3>> arr;

    cin >> n >> k;
    arr.assign(n,{0,0,0});
    for(auto &p:arr)
        for(auto &x:p)
            cin >> x;

    arr.back()[1] = min(arr.back()[1],k);

    vector<ll> answ(16,0);
    answ[0] = 1;
    for(int i=0;i<n;i++){
        auto mov = gerar(16, arr[i][2]);
        answ = exp(mov,arr[i][1]-arr[i][0])*answ;
    }

    cout << answ[0] <<"\n";

    return 0;
}