#include<bits/stdc++.h>
#define N 8
using namespace std;

int diag1[N+2], diag2[N+2], col[N];

int alg(char mat[N][N], int i){
    if(i==N){
        return 1;
    }
    int acm=0;
    bool flag = false;
    for(int j=0;j<N;j++){   
        if(!diag1[i+j] && !diag2[i-j+N-1] && !col[j] && mat[i][j]!='*'){
            diag1[i+j] = diag2[i-j+N-1] = col[j] = 1;
            acm += alg(mat,i+1);
            diag1[i+j] = diag2[i-j+N-1] = col[j] = 0;
        }
    }
    return acm;
}


int main(){
    char mat[N][N];    

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> mat[i][j];
        }
    }

    cout << alg(mat,0) << '\n';

    return 0;
}