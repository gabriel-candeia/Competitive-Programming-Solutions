#include<bits/stdc++.h>
#define maxn 405
using namespace std;

char mat[maxn][maxn];
int visited[maxn][maxn], n, m;
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

int dfs(int i, int j){
    if(i<0 || j<0 || i==n || j==m)
        return 0;
    if(visited[i][j] || mat[i][j]!='C')
        return 0;
    visited[i][j] = 1;
    int answ=1;
    for(int k=0;k<4;k++)
        answ += dfs(i+dx[k],j+dy[k]);
    return answ;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j];
    int answ=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!visited[i][j])
                answ = max(answ,dfs(i,j));
    cout << answ <<'\n';
    return 0;
}