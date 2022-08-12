#include<bits/stdc++.h>
#define maxn 1005
using namespace std;

char mat[maxn][maxn];
int block[maxn][maxn];
int n, m;

bool isok(int x, int y){
    return x>=0 && y>=0 && x<=n+1 && y<=m+1;
}

void dfs(int i, int j){
    block[i][j] = 1;
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
    for(int k=0;k<4;k++){
        if(isok(i+dx[k],j+dy[k]) && block[i+dx[k]][j+dy[k]]==0 && mat[i+dx[k]][j+dy[k]]=='.'){
            dfs(i+dx[k],j+dy[k]);
        }
    }
    if(isok(i+1,j+1) && mat[i+1][j+1]=='.' && block[i+1][j+1]==0 && mat[i+1][j]=='\\'){
        dfs(i+1,j+1);
    }
    if(isok(i+1,j-1) && mat[i+1][j-1]=='.' && block[i+1][j-1]==0 && mat[i+1][j]=='/'){
        dfs(i+1,j-1);
    }
    if(isok(i-1,j+1) && mat[i-1][j+1]=='.' && block[i-1][j+1]==0 && mat[i-1][j]=='/'){
        dfs(i-1,j+1);
    }
    if(isok(i-1,j-1) && mat[i-1][j-1]=='.' && block[i-1][j-1]==0 && mat[i-1][j]=='\\'){
        dfs(i-1,j-1);
    }
}

int main(){

    cin >> n >> m;    
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            mat[i][j] = '.';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
        }
    }
    
    int cc = -1;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            if(mat[i][j]=='.' && block[i][j]==0){
//                cout << i << " " << j <<"\n";
                cc++;
                dfs(i,j);
            }
        }
    }
/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << block[i][j] <<"";
        }
        cout<<"\n";
    }*/

    //cout << cc <<"\n";
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            if(mat[i][j]=='/' && mat[i+1][j]=='\\' && mat[i][j+1]=='\\' && mat[i+1][j+1]=='/'){
                cc++;
            }
        }
    }

    cout << cc <<"\n";

    return 0;
}