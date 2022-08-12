#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        vector<vector<char>> grid;
        vector<vector<int>> dist;
        int n, m;

        cin >> m >> n;
        grid.assign(n,vector<char>(m,0));
        dist.assign(n,vector<int>(m,0));

        for(auto &x:grid){
            for(auto &y:x){
                cin >> y;
            }
        }

        auto isok = [n, m](int x, int y){
            return x>=0 && y>=0 && x<n && y<m;
        };

        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

        queue<tuple<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='*')
                    q.push({i,j});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@')
                    q.push({i,j});
            }
        }

        int x, y;
        while(q.size()){
            tie(x,y) = q.front(), q.pop();

            for(int k=0;k<4;k++){
                int nx = x+dx[k], ny = y+dy[k];
                if(isok(nx,ny)&&grid[nx][ny]=='.'){
                    grid[nx][ny] = grid[x][y];
                    dist[nx][ny] = dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        int answ = 1e8;
        for(int i=0;i<n;i++){
            if(grid[i][m-1]=='@'){
                answ = min(answ,dist[i][m-1]+1);
            }
            if(grid[i][0]=='@'){
                answ = min(answ,dist[i][0]+1);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[n-1][i]=='@'){
                answ = min(answ,dist[n-1][i]+1);
            }
            if(grid[0][i]=='@'){
                answ = min(answ,dist[0][i]+1);
            }
        }

        if(answ==1e8){
            cout << "IMPOSSIBLE\n";
        }
        else{
            cout << answ <<"\n";
        }
        
    }

    return 0;
}