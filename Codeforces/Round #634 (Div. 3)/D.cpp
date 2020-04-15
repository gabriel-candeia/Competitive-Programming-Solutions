#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    char mat[9][9];

    cin >> t;
    while(t--){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin >> mat[i][j];
            }
        }

        for(int i=0, j=0;i<9;i+=3,j++){
            mat[i][j] = ((mat[i][j]=='1') ? '2' : '1');
        }

        for(int i=1, j=3;i<9;i+=3,j++){
            mat[i][j] = ((mat[i][j]=='1') ? '2' : '1');
        }

        for(int i=2, j=6;i<9;i+=3,j++){
            mat[i][j] = ((mat[i][j]=='1') ? '2' : '1');
        }

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << mat[i][j];
            }
            cout << '\n';
        }

    }  

    return 0;
}