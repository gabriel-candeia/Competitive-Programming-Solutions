#include<bits/stdc++.h>
#define ll long long
#define N 3
using namespace std;

const ll mod = 1e9+7;

class Matrix{
    public:
        ll n, mat[N][N];

        Matrix(int n, bool id=false){
            this->n = n;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j] = (i==j)*id;
                }    
            }
        }

        Matrix(int n, ll m[N][N]){
            this->n = n;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j] = m[i][j];
                }    
            }
        }

        Matrix operator *(const Matrix& m){
            Matrix answ(n);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        answ.mat[i][j] = (answ.mat[i][j] + mat[i][k]*m.mat[k][j])%mod;
                    }
                }
            }
            return answ;
        }
};

ll base[3] = {0,1,1}, m[N][N] = {{0,1,1},
                                 {1,0,0},
                                 {0,1,0}};

ll binpow(Matrix m, ll k){
    if(k<=2)
        return base[k];
    Matrix result(m.n,true);
    k-=2;
    while(k){
        if(k%2)
            result = result*m;
        m = m*m;
        k/=2;
    }
    ll answ = 0;
    for(int i=0;i<3;i++)
        answ = (answ + base[2-i]*result.mat[0][i])%mod;
    return answ;
}

int main(){
    ll n;
    while(cin >> n){
        cout << (binpow(Matrix(3,m),n) + binpow(Matrix(3,m),n-1))%mod << '\n';
    }
    return 0;
}