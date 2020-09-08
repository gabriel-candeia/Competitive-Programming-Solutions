#include<bits/stdc++.h>
#define maxn 105
#define ll long long
using namespace std;

const ll inf = (ll) 1e18 + 5;

struct Matrix{
    ll mat[maxn][maxn], n;

    Matrix(){

    }

    Matrix(int n, bool id = false){
        this->n = n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mat[i][j] = (id) ? (i==j) : inf;
    }

    Matrix operator*(const Matrix& b){
        Matrix c = Matrix(n);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    if(mat[i][k]!=inf && b.mat[k][j]!=inf)
                        c.mat[i][j] = min(c.mat[i][j],mat[i][k]+b.mat[k][j]);
        
        return c;
    }

    ll answ(){
        ll mn=inf;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mn = min(mn,mat[i][j]);
        return mn;
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

    return result.answ();
}

int main(){
    cin >> n >> m >> k;

    ll x, y, w;
    mat = Matrix(n);
    while(m--){
        cin >> x >> y >> w;
        mat.mat[x-1][y-1] = min(mat.mat[x-1][y-1],w);
    }

    ll answ = fexp(k);
    if(answ!=inf)
        cout << answ << '\n';
    else
        cout << "IMPOSSIBLE" << '\n';

    return 0;
}

    
