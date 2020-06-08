#include<bits/stdc++.h>
using namespace std;

int main(){
    char mat[4][100];
    int n, k, x;

    cin >> n >> k;

    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = '.';
        }
    }

    cout << "YES\n";

    int row = 1;
    if(k>n-2){
        for(int j=1;j<=n-2;j++){
            mat[1][j] = '#';
        }
        k-=n-2;
        row = 2;
    }

    x = k/2;
    for(int j=1;j<=x;j++){
        mat[row][j] = '#';
        mat[row][n-1-j] = '#';
    }
    if(k%2==1){
        mat[row][n/2] = '#';
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            cout << mat[i][j];
        }
        cout << '\n';
    }

    return 0;
}