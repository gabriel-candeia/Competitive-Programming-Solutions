#include<bits/stdc++.h>
#define maxn int(1100)
using namespace std;

int n, m;
vector<vector<char>> mat;
int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};

void bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push({i,j});

    mat[i][j] = 'o';
    while(q.size()){
        tie(i,j) = q.front(); q.pop();
        for(int k=0;k<4;k++){
            int x = i+dx[k], y = j+dy[k];
            if(x>=0 && y>=0 && x<n && y<m && mat[x][y]=='.'){
                mat[x][y] = 'o';
                q.push({x,y});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    mat.assign(n+1,vector<char>(m+1,' '));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }

    int answ = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='.'){
                answ++;
                bfs(i,j);
            }
        }
    }

    cout << answ <<"\n";

    return 0;   
}