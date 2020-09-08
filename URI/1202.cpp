#include<bits/stdc++.h>
#define N 5
using namespace std;

const int mod = 1000;
class Matrix{
    public:
        int n, mat[5][5];

        Matrix(int n, bool id=false){
            this->n = n;
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    mat[i][j] = (i==j)*id;
                }
            }
        }

        Matrix operator*(const Matrix& m){
            Matrix r(n);
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    for(int k=0;k<=n;k++){
                        r.mat[i][j] = (r.mat[i][j] + mat[i][k]*m.mat[k][j])%mod;
                    }    
                }
            }
            return r;
        }
};

int binpow(Matrix& mat, string s){
    Matrix result(mat.n,true);
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1')
            result = result*mat;
        mat = mat*mat;
    }
    return (result.mat[0][0] + result.mat[0][1])%mod;
}

void subtract(string& s){
    int i=s.size()-1;
    while(s[i]=='0'){
        s[i--] = '1';
    }
    s[i] = '0';
}

int main(){
    int t; 
    string s;
    Matrix mat(2);

    cin >> t;
    while(t--){
        mat.mat[0][0] = 1; mat.mat[0][1] = 1;
        mat.mat[1][0] = 1; mat.mat[1][1] = 0;
        cin >> s;
        if(s=="1" || s=="10"){
            cout << "001\n";
        }
        else{
            subtract(s); subtract(s);
            printf("%.3d\n",binpow(mat,s));
        }
    }


    return 0;
}