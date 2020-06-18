#include<bits/stdc++.h>
#define N 200
using namespace std;

int main(){
    int l, c;
    char mat[N][N];
    int ci, cj, li=0, lj=0;

    for(int i=1;i<=l;i++){
        for(int j=1;j<=c;j++){
            mat[i][j] = '.';
        }
    };

    cin >> l >> c;
    for(int i=1;i<=l;i++){
        for(int j=1;j<=c;j++){
            cin >> mat[i][j];
            if(mat[i][j]=='o'){
                ci = i;
                cj = j;
            }
        }
    };
    mat[ci][cj] = '.';
    while(li!=ci || lj!=cj){
        li = ci;
        lj = cj;
        if(mat[ci-1][cj]=='H'){
            mat[ci-1][cj] = '.';
            ci--;
        }
        else if(mat[ci+1][cj]=='H'){
            mat[ci+1][cj] = '.';
            ci++;
        }
        else if(mat[ci][cj-1]=='H'){
            mat[ci][cj-1] = '.';
            cj--;
        }
        else if(mat[ci][cj+1]=='H'){
            mat[ci][cj+1] = '.';
            cj++;
        }
    }

    cout << ci << ' ' << cj << '\n';
    
    return 0;
}

