#include<bits/stdc++.h>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define N 10
using namespace std;

class Matrix{
    public:
        ll mat[N][N], n, c;

        Matrix(ll n, bool id=false, ll mod=1){
            this->n = n;
            c = mod;
            for(ll i=0;i<n;i++){
                for(ll j=0;j<n;j++){
                    mat[i][j] = (i==j)*id;
                }
            }
        }

        Matrix(ll n, ll mat[N][N], ll mod=1){
            this->n = n;
            c = mod;
            for(ll i=0;i<n;i++){
                for(ll j=0;j<n;j++){
                    this->mat[i][j] = mat[i][j];
                }
            }
        }

        Matrix operator *(const Matrix& o){
            Matrix r(n,false,c);
            for(ll i=0;i<n;i++){
                for(ll j=0;j<n;j++){
                    for(ll k=0;k<n;k++){
                        r.mat[i][j] = (r.mat[i][j]  + mat[i][k]*o.mat[k][j])%c;
                    }
                }
            }
            return r;
        }
};

ll base[N][N] = {{1,1},{1,0}};

ll fibo(ll n, ll c){
    if(n<=1){
        return n;
    }
    Matrix m(2,base,c), answ(2,true,c);
    n-=1;
    while(n){
        if(n%2){
            answ = answ*m;
        }
        m = m*m;
        n>>=1;
    }
    return answ.mat[0][0];
}

int main(){
    ll n, m, ciclo;
    fastIO();
    while(cin >> n >> m){
        ll a=0, b = 1, c;
        for(ciclo=1;a!=1 || b!=0;ciclo++){
            c = (a+b)%m;
            a = b;
            b = c;
        }
        cout << fibo(fibo(n,ciclo),m) << '\n';
    }

    return 0;
}