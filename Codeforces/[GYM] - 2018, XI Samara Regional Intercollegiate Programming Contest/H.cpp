#include<bits/stdc++.h>
using namespace std;

int n, m, d;
vector<vector<char>> mat;
vector<vector<int>> dist;
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

bool isok(int x, int y){
    return x>=0 && y>=0 && x<n && y<m;
}

int main(){
    cin >> n >> m >> d;
    mat.assign(n,vector<char>(m,0));

    for(auto &x:mat)
        for(auto &y:x)
            cin >> y;

    dist.assign(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mat[i][j]=='M')
                dist[i][j] = 1, q.push({i,j});
    
    int x, y;
    while(q.size()){
        tie(x,y) = q.front(), q.pop();

        for(int k=0;k<4;k++){
            int nx = x+dx[k], ny = y + dy[k];
            if(isok(nx,ny) && dist[nx][ny]==0 && dist[x][y]<d+1){
                dist[nx][ny] = dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(dist[i][j])
                dist[i][j] = -1;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mat[i][j]=='S' && dist[i][j]!=-1)
                q.push({i,j}), dist[i][j] = 1;

    while(q.size()){
        tie(x,y) = q.front(), q.pop();

        for(int k=0;k<4;k++){
            int nx = x+dx[k], ny = y + dy[k];
            if(isok(nx,ny) && dist[nx][ny]==0){
                dist[nx][ny] = dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(mat[i][j]=='F')
                cout << (dist[i][j] - (dist[i][j]!=-1)) <<"\n";
    }

    return 0;
}