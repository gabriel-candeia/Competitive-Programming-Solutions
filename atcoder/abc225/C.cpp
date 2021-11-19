#include<bits/stdc++.h>
#define maxn int(1e4+5)
#define maxm int(8)
using namespace std;

int mat[maxn][maxm];

int main(){
    int n, m;

    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j];

    bool poss = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i){
                poss = (poss&&(mat[i][j]-mat[i-1][j]==7));
            }
            if(j){
                poss = (poss&&(mat[i][j]-mat[i][j-1]==1));
            }
            if(j){
                poss = (poss&&(mat[i][j]%7>mat[i][j-1]%7) || poss&&(mat[i][j]%7==0 && mat[i][j-1]%7==6));
            }
            if(mat[i][j]%7==0){
                poss = poss && (j==m-1);
            }
        }
    }


    if(poss)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}