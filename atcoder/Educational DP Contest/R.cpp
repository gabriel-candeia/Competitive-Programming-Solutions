#include<bits/stdc++.h>
#define maxn 55
#define ll long long
using namespace std;

const ll mod = 1e9+7;
struct Matrix{
    ll mat[maxn][maxn];

    Matrix(bool id = false){
        for(ll i=0;i<maxn;i++)
            for(ll j=0;j<maxn;j++)
                mat[i][j] = id*(i==j);
    }

    Matrix operator*(Matrix &b){
        Matrix c;   
        for(ll i=0;i<maxn;i++)
            for(ll j=0;j<maxn;j++)
                for(ll k=0;k<maxn;k++)
                    c.mat[i][j] = (c.mat[i][j] + mat[i][k]*b.mat[k][j])%mod;
        return c;
    }

    ll sum(){
        ll answ = 0;
        for(ll i=0;i<maxn;i++)
            for(ll j=0;j<maxn;j++)
                answ = (answ+mat[i][j])%mod;
        return answ;
    }
};

ll n, k;
Matrix adj;
ll fexp(ll k){
    Matrix result(true);

    while(k){
        if(k%2)
            result = result*adj;
        adj = adj*adj;
        k/=2;
    }

    return result.sum();
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> adj.mat[i][j];

    cout << fexp(k) <<'\n';

    return 0;
}