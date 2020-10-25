#include<bits/stdc++.h>
using namespace std;
#define maxn 1005

int mat[maxn][maxn],vazio[maxn];
int n, m, c;

int testa(int j){
    int last[2] = {-2000,-2000};
    for(int i=0;i<n;i++){
        if(mat[i][j]){
            if(i-last[mat[i][j]%2]-1<c)
                return false;
            else
                last[mat[i][j]%2] = i;
        }
    }
    return true;
}

int main(){

    cin >> n >> m >> c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            vazio[j]+=(mat[i][j]!=0);
        }
    }

    bool poss = true;
    for(int i=0;i<m-1;i++){
        if(vazio[i] && vazio[i+1]){
            poss = false;
        }
    }
    
    for(int j=0;j<m && poss;j++){
        poss = testa(j);
    }

    cout << ((poss) ? "S" : "N") <<'\n';
    return 0;
}