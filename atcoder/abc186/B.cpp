#include<bits/stdc++.h>
#define maxn 200
using namespace std;

int mat[maxn][maxn];

int main(){
    int h, w, mn=100000;

    cin >> h >> w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> mat[i][j];
            mn = min(mat[i][j],mn);
        }
    }

    int answ = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            answ += mat[i][j]-mn;
        }
    }

    cout << answ <<'\n';

    return 0;
}