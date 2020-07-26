#include<bits/stdc++.h>
#define N 1005
using namespace std;

int main(){
    int mat[N][N], col[N], lin[N], n;

    cin >> n;
    memset(col,0,n+1); memset(lin,0,n+1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
            lin[i]+=mat[i][j];
            col[j]+=mat[i][j];
        }
    }

    int answ=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            answ = max(answ,lin[i]+col[j]-2*mat[i][j]);
        }
    }

    cout << answ << '\n';

    return 0;
}
